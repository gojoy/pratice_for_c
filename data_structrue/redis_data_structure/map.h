/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   map.h
 * Author: gg
 *
 * Created on 2017年6月22日, 下午4:29
 */

#ifndef MAP_H
#define MAP_H

#endif /* MAP_H */

#include "dict.h"
#include "sds.h"

dict *Newmap();
int dictSdsCompare(void *parivate,const sds key1,const sds key2);
void dictSdsValDestructor(void *privdata, void *obj);
void dictSdsKeyDestructor(void *privdata, void *obj);