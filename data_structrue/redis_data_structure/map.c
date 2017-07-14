/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   map.c
 * Author: gg
 * 
 * Created on 2017年6月22日, 下午4:29
 */

#include "map.h"


int dictSdsCompare(void *parivate,const sds key1,const sds key2) {
    return sdsEqual(key1,key2);
}

void dictSdsValDestructor(void *privdata, void *obj) {
    return sdsfree(obj);
}
void dictSdsKeyDestructor(void *privdata, void *obj) {
    return sdsfree(obj);
}

dictType commonsdsDictType={
	dictCharHash,
	NULL,
	NULL,
	dictSdsCompare,
	NULL,
	dictSdsValDestructor
};



dict *Newmap() {
    return dictCreate(&commonsdsDictType);
}