/*
 * Copyright (C) 2017 gg
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/* 
 * File:   heap.c
 * Author: gg
 * 
 * Created on 2017年6月23日, 下午3:57
 */

#include "heap.h"

const int MinData=INT32_MIN;

int  error(const char *c) {
    printf("Error: %s!\n",c);
    exit(1);
}

PriorityQueue PQInit(int MaxElement) {
    PriorityQueue h;
    if(MaxElement < __MINPQSIZE)
        error("Init size is too small");
    h=malloc(sizeof(struct HeapStruct));
    if(h==NULL)
        error("malloc false");
    h->Elements=malloc(sizeof(ElementType)*(MaxElement+1));
    if(h->Elements==NULL)
        error("malloc false");
    h->Capacity=MaxElement;
    h->Size=0;
    h->Elements[0]=MinData;
    
    printf("init sucess\n");
    return h; 
}

void MakeEmpty( PriorityQueue h) {
    if(!PQIsEmpty(h))
        return;
    memset(h->Elements+1,0,sizeof(ElementType)*(h->Size-1));
    h->Size=0;
}

void Destory(PriorityQueue h) {
    free(h->Elements);
    free(h);
    return;
}

int PQIsFull(PriorityQueue h) {
    return h->Size>=h->Capacity;
}

int PQIsEmpty(PriorityQueue h) {
    return h->Size==0;
}

int PQInsert(ElementType x, PriorityQueue h) {
    int i;
    if(PQIsFull(h)) {
        error("insert false,full pq");
        return __PQ_ERR;
    }
    
    for(i=++h->Size; h->Elements[i/2]>x; i=i/2)
        h->Elements[i]=h->Elements[i/2];
    h->Elements[i]=x;
    
    return __PQ_OK;
        
}

ElementType PQFindMin(PriorityQueue h){
    if(PQIsEmpty(h)) {
        printf("find false,empty pq\n");
        return h->Elements[0];
    }
    return h->Elements[1];
}

ElementType PQDeleteMin(PriorityQueue h) {
    int i;
    if(PQIsEmpty(h)) {
        error("delete empty error\n");
        return h->Elements[0];
    }
    ElementType min=h->Elements[1];
    for(i=1;2*i<h->Size;) {
        int min=i*2;
//        当堆中元素个数为偶时，需要测试该节点是否只有一个儿子，min!=h->size
        if(min!=h->Size && h->Elements[min]<h->Elements[min+1])
            min++;
       
        h->Elements[i]=h->Elements[min];
        i=min;
    }
    h->Elements[i]=h->Elements[h->Size];
    h->Elements[h->Size--]=0;
    return min;
}

void pqshow(PriorityQueue h) {
    for(int i=1;i < h->Size+1;i++)
        printf("%d ",h->Elements[i]);
    
}