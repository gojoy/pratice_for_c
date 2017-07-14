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
static inline void _dictReset(dictht *ht) {
	ht->table = NULL;
    ht->size = 0;
    ht->sizemask = 0;
    ht->used = 0;
}

int _dictKeyIndex(dict *d,void *key) {
	unsigned int hash,idx,index;
	dictEntry *e;
	hash=dictHashKey(d,key);
	idx=hash&d->ht[0].sizemask;
	printf("idx is %d,hash is %d,sizemask is %d\n",idx,hash,d->ht[0].sizemask );
	e=d->ht[0].table[idx];
	while(e!=NULL) {
		printf("in while loop\n" );
			if(dictCompareKeys(d,key,e->key))
				return __HASHMAP_ERR;
			e=e->next;
	}
	printf("after loop\n");
	return idx;
}

void dictFreeVal(dict *d, dictEntry *entry) {
	if(d->type->valDestructor)
		d->type->valDestructor(NULL, entry->v.val);
}

void dictSetVal(dict *d, dictEntry *entry, void *_v_) {
	if(d->type->valDup)
		entry->v.val=d->type->valDup(NULL, _v_);
	else
		entry->v.val=_v_;
}

int dictCompareKeys(dict *d, void *key1, void *key2) {
	if(d->type->keyCompare)
		return d->type->keyCompare(NULL,key1,key2);
	else
		return key1==key2;
}


//-------------------------------api-------------------------------------

dict *dictCreate(dictType *type) {
	dict *d=(dict *)malloc(sizeof(dict));
	d->type=type;
	d->rehashidx=-1;
	d->iterators=0;
	_dictReset(&d->ht[0]);
	_dictReset(&d->ht[1]);
	dictExpend(d,16);
	return d;
}

int dictExpend(dict *d, unsigned long size) {

	if( dictIsRehashing(d) || d->ht[0].used>size)
		return __HASHMAP_ERR;

	dictEntry **aryentry=(dictEntry **)malloc(sizeof(dictEntry*)*size);
	memset(aryentry,0,size*sizeof(dictEntry *));

	if (d->ht[0].table==NULL)
	{
		d->ht[0].table=aryentry;
		d->ht[0].size=size;
		d->ht[0].sizemask=size-1;
		d->ht[0].used=0;
		return __HASHMAP_OK;
	}

	fprintf(stderr, "cannot expend dirty dict\n");
	return __HASHMAP_ERR;

}

int dictAdd(dict *d, void *key, void *val) {

	printf("now add k %s,v%s,vlen is %d\n",key,val,strlen((char *)val) );
	dictEntry *e=dictAddRaw(d,key);
	if(!e) return __HASHMAP_ERR;

	dictSetVal(d,e,val);
	printf("added k is %s,v is %s\n",e->key,e->v.val );
	return __HASHMAP_OK;
}


dictEntry *dictAddRaw(dict *d, void *key) {
	int index;

	if( (index=_dictKeyIndex(d,key))==__HASHMAP_ERR)
		return NULL;
	dictEntry *e=(dictEntry *)malloc(sizeof(dictEntry));
	memset(e,0,sizeof(dictEntry));
	e->key=key;
	e->next=d->ht[0].table[index];
	d->ht[0].table[index]=e;
	d->ht[0].used++;


	//dictSetVal(d,e,key);
	return e;

}

dictEntry *dictFind(dict *d, void *key) {
	dictEntry *e;
	unsigned int hash=dictHashKey(d,key);
	int idx=hash&d->ht[0].sizemask;
	e=d->ht[0].table[idx];
	while(e){
		if(dictCompareKeys(d,key,e->key))
			return e;
		e=e->next;
	}
	return NULL;
}

char *dictGetchar(dict *d, void *key) {
	dictEntry *e;
	e=dictFind(d,key);
	if(e==NULL) {
		fprintf(stderr, "null\n" );
	 return NULL;
	}
	return (char *)dictGetVal(e);
}


int dictDelete(dict *d, void *key) {
	dictEntry *e;
	unsigned int hash,idx,h;
	hash=dictHashKey(d,key);
	idx=hash&d->ht[0].sizemask;
	e=d->ht[0].table[idx];
	if(e==NULL) {
		fprintf(stderr, "no this key %s\n",(char *)key );
		return __HASHMAP_ERR;
	}
	if (dictCompareKeys(d,key,e->key))
	{
		d->ht[0].table[idx]=e->next;
		free(e);
		d->ht[0].used--;
		return __HASHMAP_OK;
	}else {
		dictEntry *pre;
		pre=e;
		e=e->next;
		while(e) {
			if(dictCompareKeys(d,key,e->key)) {
				pre->next=e->next;
				free(e);
				d->ht[0].used--;
				return __HASHMAP_OK;
			}
			pre=e;
			e=e->next;
		}
		fprintf(stderr, "no this key %s\n",(char *)key );
		return __HASHMAP_ERR;
	}
}


void showDict(dict *d) {
	printf("size is %d,used is %d\n",d->ht[0].size,d->ht[0].used );
}

dict *Newdict() {
	return dictCreate(&commonDictType);
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
