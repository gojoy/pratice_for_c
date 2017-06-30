/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dict.c
 * Author: gg
 * 
 * Created on 2017年6月21日, 下午3:30
 */
#include "dict.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/time.h>
#include <ctype.h>

//----------------------------hash------------------------------------

static uint32_t dict_hash_function_seed = 5381;

unsigned int dictGenCaseHashFunction(const unsigned char *buf, int len) {
	unsigned int hash=(unsigned int)dict_hash_function_seed;

	while(len--) {
		hash=((hash << 5) + hash) + (tolower(*buf++));
	}
	return hash;
}


unsigned int dictCharHash(const void *key) {
	return dictGenCaseHashFunction((unsigned char *)key, strlen( (char *)key ) );
}

int dictCharCompare(void *privdata, const void *key1, const void *key2) {
	char *c1=(char *)key1,*c2=(char *)key2;
	return strcasecmp(c1, c2) == 0;
}



dictType commonDictType={
	dictCharHash,
	NULL,
	NULL,
	dictCharCompare,
	NULL,
	NULL
};


//------------------------------private-------------------------------




void logger(const char *s) {
    fprintf(stderr,"%s,in file %s,line %d\n",s,__FILE__,__LINE__);
    return;
}

void showEntry(dictEntry *e) {
    if(e==NULL){
        logger("showentry null");
        return;
    }
    printf("key is %s\n",(char *)e->key);
    return;
}

static  void _dictReset(dictht *ht) {
    ht->table = NULL;
    ht->size = 0;
    ht->sizemask = 0;
    ht->used = 0;
}

//以2的幂向上取大于size的数
static unsigned long _dictNextPower(unsigned long size) {
    unsigned long i=DICT_HT_INITIAL_SIZE;
    if(size>=LONG_MAX) return size;
    while (1) {
        if(i>=size)
            return i;
        i*=2;
    }

}




void dictFreeVal(dict *d, dictEntry *entry) {
	if(d->type->valDestructor)
		d->type->valDestructor(NULL, entry->v.val);
        else
            free(entry->v.val);
}

void dictSetVal(dict *d, dictEntry *entry, void *_v_) {
	if(d->type->valDup)
		entry->v.val=d->type->valDup(NULL, _v_);
	else
		entry->v.val=_v_;
}

void dictFreeKey(dict *d, dictEntry *entry) {
    if(d->type->keyDestructor)
        d->type->valDestructor(NULL,entry->key);
}

void dictSetKey(dict *d,dictEntry *entry, void *_k_) {
    if(d->type->keyDup)
        entry->key=d->type->keyDup(NULL,_k_);
    else
        entry->key=_k_;
}

int dictCompareKeys(dict *d, void *key1, void *key2) {
	if(d->type->keyCompare)
		return d->type->keyCompare(NULL,key1,key2);
	else
		return key1==key2;
}

int dictAllRehash(dict *d) {
    if(dictIsRehashing(d))
        _reHashAll(d);
    printf("after dictallre\n");
    return 1;
}

int _reHashAll(dict *d) {
    return _dictRehashStep(d,d->ht[0].used+1);
}


int _dictRehashStep(dict *d, unsigned long step) {
    if (!dictIsRehashing(d))
        return __HASHMAP_ERR;

    //fprintf(stderr, "begin to rehash!!,rehash mamber is %ld\n", d->rehashidx);

    dictEntry *entry, *nexten;
    
    int i;
    while (step--) {

//        rehash完成时的操作
        if (d->ht[0].used == 0) {
            //logger("finish rehash and reset ht");
            free(d->ht[0].table);
            d->ht[0] = d->ht[1];
            _dictReset(&d->ht[1]);
            d->rehashidx = -1;
            fprintf(stderr,"finish rehash and reset ht,ridx is %ld,isbool is %d\n",d->rehashidx,dictIsRehashing(d));
            return 1;
        }
        
        
        if (d->rehashidx > d->ht[0].size) {
            fprintf(stderr,"rehash error \n");
            return __HASHMAP_ERR;
        }
        
        //logger("begin rehash find pos");
        while (d->ht[0].table[d->rehashidx] == NULL) d->rehashidx++;
        //printf("find pos is %ld\n",d->rehashidx);
        entry = d->ht[0].table[d->rehashidx];
        //showEntry(entry);
        while (entry) {
            unsigned int n, time = 0;
            nexten = entry->next;
            n = dictHashKey(d, entry->key) & d->ht[1].sizemask;
            entry->next = d->ht[1].table[n];
            d->ht[1].table[n] = entry;
            d->ht[1].used++;
            d->ht[0].used--;
            entry = nexten;
            //printf("move key %s to ht1 pos %u,hi sizemask is %lu\n", (char *) d->ht[1].table[n]->key, n, d->ht[1].sizemask);
        }
        d->ht[0].table[d->rehashidx] = NULL;
        d->rehashidx++;
    }
    //logger("rehash finished!\n");
    return __HASHMAP_OK;
}


//查找出key对应槽的index
int _dictKeyIndex(dict *d,void *key) {
	unsigned int hash,idx,index;
        int i=0;
	dictEntry *e;
	hash=dictHashKey(d,key);
        for(i;i<=1;i++) {
	idx=hash&d->ht[i].sizemask;
	//printf("idx is %u,hash is %u,sizemask is %lu\n",idx,hash,d->ht[i].sizemask );
	e=d->ht[i].table[idx];
	while(e!=NULL) {
		//printf("in while loop\n" );
			if(dictCompareKeys(d,key,e->key)){
                            fprintf(stderr,"find same key,key is %s,e->key is %s!\n",key,e->key);
				return -1;
                        }
			e=e->next;
	}
        if(!dictIsRehashing(d))
            break;
	//printf("after loop i is %d\n",i);
        }
	return idx;
}


//-------------------------------api-------------------------------------

dict *dictCreate(dictType *type) {
	dict *d=(dict *)malloc(sizeof(dict));
	d->type=type;
	d->rehashidx=-1;
	d->iterators=0;
	_dictReset(&d->ht[0]);
	_dictReset(&d->ht[1]);
	dictExpend(d,DICT_HT_INITIAL_SIZE);
	return d;
}

int dictExpend(dict *d, unsigned long size) {

	if( dictIsRehashing(d) || d->ht[0].used>size)
		return __HASHMAP_ERR;
        
        unsigned long  realsize=_dictNextPower(size);

	dictEntry **aryentry=(dictEntry **)malloc(sizeof(dictEntry*)*realsize);
	memset(aryentry,0,realsize*sizeof(dictEntry *));
        
	if (d->ht[0].table==NULL)
	{
		d->ht[0].table=aryentry;
		d->ht[0].size=realsize;
		d->ht[0].sizemask=realsize-1;
		d->ht[0].used=0;
                d->rehashidx=-1;
		return __HASHMAP_OK;
	}
        
        d->ht[1].table=aryentry;
	d->ht[1].size=realsize;
	d->ht[1].sizemask=realsize-1;
	d->ht[1].used=0;
        d->rehashidx=0;
        
	fprintf(stderr, "expend dirty dict,rehash member is %d\n",d->rehashidx);
	return realsize;

}

int dictAdd(dict *d, void *key, void *val) {

    //printf("Add log::now add k %s,v%s,vlen is %d\n", key, val, strlen((char *) val));
    
    if(dictIsRehashing(d))  _dictRehashStep(d,1);
    
    if(d->ht[0].used >= d->ht[0].size/2+1 )
    {
        logger("enlarge before add\n");
        if(dictIsRehashing(d))
            _reHashAll(d);
    dictEnLarge(d);
    }
        
        
    dictEntry *e = dictAddRaw(d, key);
    if (!e) {
        fprintf(stderr,"ADD:%sfalse\n",(char *)key);
        return __HASHMAP_ERR;
    }

    dictSetVal(d, e, val);
    //printf("ADD::added k is %s,v is %s sucess\n\n", e->key, e->v.val);
    return __HASHMAP_OK;
}


dictEntry *dictAddRaw(dict *d, void *key) {

    dictht *tempht;
    int index;
    if ((index = _dictKeyIndex(d, key)) == -1) {
        fprintf(stderr,"find indx in dict,cannot add raw\n");
        return NULL;
    }
        
    dictEntry *e = (dictEntry *) malloc(sizeof (dictEntry));
    memset(e, 0, sizeof (dictEntry));
    if(dictIsRehashing(d))
        tempht=&d->ht[1];
    else
        tempht=&d->ht[0];
    e->next = tempht->table[index];
    tempht->table[index] = e;
    tempht->used++;
    dictSetKey(d,e,key);
    return e;
}

dictEntry *dictFind(dict *d, void *key) {
    
    if(d->ht[0].size==0)
        return NULL;
    if(dictIsRehashing(d))  _dictRehashStep(d,1);
    dictEntry *e;
    int i=0;
    unsigned int hash = dictHashKey(d, key);
    for (i; i <= 1; i++) {
        int idx = hash & d->ht[i].sizemask;
        e = d->ht[i].table[idx];
        while (e) {
            if (dictCompareKeys(d, key, e->key))
                return e;
            e = e->next;
        }
        if(!dictIsRehashing(d))
            break;
    }
    return NULL;
}

char *dictGetchar(dict *d, void *key) {
	dictEntry *e;
	e=dictFind(d,key);
	if(e==NULL) {
		fprintf(stderr, "null key\n" );
	 return NULL;
	}
	return (char *)dictGetVal(e);
}

int dictDelete(dict *d, void *key) {
    dictEntry *e;
    unsigned int hash, idx, h;

    if (d->ht[0].size == 0) return __HASHMAP_ERR;
    if (dictIsRehashing(d)) _dictRehashStep(d, 1);

    hash = dictHashKey(d, key);
    for (int i = 0; i <= 1; i++) {
        idx = hash & d->ht[i].sizemask;
        e = d->ht[i].table[idx];
        dictEntry *pre=NULL;
        while (e) {
            if(dictCompareKeys(d,key,e->key)) {
                if(pre)
                    pre->next=e->next;
                else
                    d->ht[0].table[idx]=e->next;
                dictFreeVal(d,e);
                dictFreeKey(d,e);
                free(e);
                d->ht[i].used--;
                printf("delete %s sucess!\n",key);
                return __HASHMAP_OK;
            }
            
            pre=e;
            e=e->next;
        }
        if (!dictIsRehashing(d)) break;
    }
    printf("Delete Error!,no this key!%s\t\n",key);
    return __HASHMAP_ERR;
}

unsigned long dictEnLarge(dict *d) {
    if(!dictIsRehashing(d))
        return dictExpend(d,d->ht[0].used*2);
    return 0;
}

void showDict(dict *d) {
    if(dictIsRehashing(d)) {
        //printf("bool is %d\n",dictIsRehashing(d));
        // _dictRehashStep(d,1);
        fprintf(stdout,"SHOW::dict is rehashing!,ridx is %ld\n",d->rehashidx);
        return;
    }
    unsigned long dsize,dused;
    dsize=d->ht[0].size;
    dused=d->ht[0].used;
    float r=100*dused/dsize;
    int rate=(int)r;
    printf("SHOW::size is %lu,used is %lu,userate is %d,rehash is %ld\n",dsize,dused,rate,d->rehashidx );
}

dict *Newdict() {
	return dictCreate(&commonDictType);
}

dict *NewdictFromsds() {
    printf("not support\n");
    return NULL;
}

//--------------------------------------main---------------------------------
#define TEST 3

#if TEST==1


int main(int argc, char const *argv[])
{
	dict *d=dictCreate(&commonDictType);
	char k1[]="1";
	char k2[]="2";
	char k3[]="3";
	char v1[]="first";
	char v2[]="second";
	char v3[]="third";


	dictAdd(d,k1,v1);
	dictAdd(d,k2,v2);
	dictAdd(d,k3,v3);
	printf("thie is test,get 1 %s\n",dictGetchar(d,k1));
	showDict(d);
	dictDelete(d,k1);
	printf("after delete,get 1 %s\n",dictGetchar(d,k1));
	showDict(d);
	return 0;
}

#elif TEST==2

int main(int argc, char const *argv[])
{
	printf("test arry\n");
	char buf[]="abcde";
	char *p;
	p=buf;
	*p='c';

	printf("buf is %s,size is %d,addr is %p\n",buf,sizeof(buf),buf );
	printf("p addr is %p\n",p );
	return 0;
}

#endif