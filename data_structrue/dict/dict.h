#include <stdint.h>
#include <stdio.h>

#define	__HASHMAP_OK	0
#define	__HASHMAP_ERR	1

//存放键值对
typedef struct dictEntry
{
	void *key;
	union{
		void *val;
		uint64_t u64;
		int64_t i64;
		double d;
	}v;
	struct dictEntry *next;
}dictEntry;

//加载的各种函数
typedef struct dictType
{	
	unsigned int (*hashFunction)(const void *key);
	void *(*keyDup)(void *privdata, const void *key);
	void *(*valDup)(void *privdata, const void *obj);
    int (*keyCompare)(void *privdata, const void *key1, const void *key2);
    void (*keyDestructor)(void *privdata, void *key);
    void (*valDestructor)(void *privdata, void *obj);
}dictType;

//哈希表结构
typedef struct dictht
{	dictEntry **table;
	unsigned long size;
	unsigned long sizemask;
	unsigned long used;
}dictht;


//哈希字典
typedef struct dict
{
	dictType *type;
	dictht ht[2];
	long rehashidx;
	int iterators;
}dict;



#define dictHashKey(d, key) (d)->type->hashFunction(key)
#define dictGetKey(he) ((he)->key)
#define dictGetVal(he) ((he)->v.val)
#define dictGetSignedIntegerVal(he) ((he)->v.s64)
#define dictGetUnsignedIntegerVal(he) ((he)->v.u64)
#define dictGetDoubleVal(he) ((he)->v.d)
#define dictSlots(d) ((d)->ht[0].size+(d)->ht[1].size)
#define dictSize(d) ((d)->ht[0].used+(d)->ht[1].used)
#define dictIsRehashing(d) ((d)->rehashidx != -1)


dict *dictCreate(dictType *type);
int dictExpend(dict *d, unsigned long size);
int dictAdd(dict *d, void *key, void *val);
int dictDelete(dict *d, void *key);
dictEntry *dictFind(dict *d, void *key);
dictEntry *dictAddRaw(dict *d, void *key);

char *dictGetchar(dict *d, void *key);
void showDict(dict *d);

//hash function
unsigned int dictCharHash(const void *key);
unsigned int dictGenCaseHashFunction(const unsigned char *buf, int len);
dict *Newdict();


