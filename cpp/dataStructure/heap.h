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
 * File:   heap.h
 * Author: gg
 *
 * Created on 2017年6月23日, 下午3:57
 */

#ifndef HEAP_H
#define HEAP_H

#define __MINPQSIZE 8
#define __PQ_OK 0
#define __PQ_ERR INT32_MIN
#include <stdint.h>
#include <stddef.h>



typedef  int ElementType;

struct HeapStruct {
    int Capacity;
    int Size;
    ElementType *Elements;
};

typedef struct HeapStruct *PriorityQueue;

PriorityQueue PQInit(int MaxElement);
void Destory(PriorityQueue h);
void MakeEmpty( PriorityQueue h);
int PQInsert(ElementType x, PriorityQueue h);
ElementType PQDeleteMin(PriorityQueue h);
ElementType PQFindMin(PriorityQueue h);
int PQIsEmpty(PriorityQueue h);
int PQIsFull(PriorityQueue h);


#endif /* HEAP_H */
