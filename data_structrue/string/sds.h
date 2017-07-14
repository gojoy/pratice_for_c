#ifndef __SDS_H
#define	__SDS_H

#undef TEST
#define TEST	1

#include <stdarg.h>
#include <stdint.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>
#define SDS_LLSTR_SIZE 21

#define SDS_MAX_PREALLOC (1024*1024)

typedef char *sds;


struct sdshdr32 {
	uint32_t len;
	uint32_t alloc;
	unsigned char flags;
	char buf[];
}__attribute__((__packed__));
//__attribute__((__packed__))

#define SDS_HDR(T,s) ((struct sdshdr##T *)((s)-(sizeof(struct sdshdr##T))))
#define SDS_HDR_VART(T,s)	struct sdshdr##T *sh=(void *)( (s)-sizeof(struct sdshdr##T));

static inline size_t sdslen(const sds s) {
	return SDS_HDR(32,s)->len;
	//struct sdshdr32 *sh=(struct sdshdr32 *)(s-sizeof(struct sdshdr32));
	//return sh->len;
}

static inline size_t sdsavible(const sds s) {
	SDS_HDR_VART(32,s);
	return sh->alloc - sh->len;
}

static inline void sdssetlen(sds s,size_t newlen) {
	SDS_HDR(32,s)->len=newlen;
	return;
}

static inline void sdssetalloc(sds s, size_t newlen) {
	SDS_HDR(32,s)->alloc=newlen;
	return;
}

static inline void sdsinclen(sds s, size_t inc) {
	SDS_HDR(32,s)->len+=inc;
	return;
}

static inline size_t sdsalloc(const sds s) {
	return SDS_HDR(32,s)->alloc;
}

static inline size_t sdshdrsize(s) {
	return sizeof(struct sdshdr32);
}

char *strdup(const char *s);

sds sdsnewlen(const void *init, size_t initlen);
sds newsds(const char *init);
sds sdsempty();
sds sdsdup(sds s);
void sdsfree(sds s);
sds sdsgrowzero(sds s, size_t len);
sds sdsMakeRoomfor(sds s, size_t addlen);
sds sdscatlen(sds s,const void *init, size_t len);
sds sdscat(sds s, const char *init);
sds sdscatsds(sds s, const sds t);
sds sdscpylen(sds s, const char *init, size_t len);
sds sdscpy(sds s, const char *t);
sds sdsfmt(sds s,char *fmt,...);
sds sdstrim(sds s,const char *cset);
sds *sdssplitlen(const char *s, int len, const char *sep, int seplen, int *count);
sds *sdssplit(const char *s,const char *sep,int *count);



void  showsds(sds s);





#endif



