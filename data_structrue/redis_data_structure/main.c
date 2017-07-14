/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: gg
 *
 * Created on 2017年6月21日, 下午3:25
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



/*
 * 
 */
#define T 3



#if T==1
#include "sds.h"
#include "dict.h"
#include "map.h"

int main(int argc, char** argv) {

    dict *map=Newmap();

    long i;
    for(i=0;i<10;i++) {
        dictAdd(map,sdsfromll(i),sdsfromll(i+1));
    }
    showDict(map);
    //sleep(3);
    //sleep(10);
    dictAllRehash(map);
    showDict(map);
    printf("get 1 val is %s\n",dictGetchar(map,sdsfromll(1)));
    sds l1=sdsfromll(1);
    sds l2=sdsfromll(1);
    printf("delete status is %d\n",dictDelete(map,l1));
    showsds(l1);
    dictDelete(map,l1);
    
    return (EXIT_SUCCESS);
}

#elif T==2

#include "rand.h"

int main(int argc, char** argv) {
    printf("hello\n");
    int i=3;
    while(i--)
        printf("rand is %d\n",redisLrand48());
    showrand();
}

#elif T==3

#include "heap.h"
int main(int argc, char** argv) {
    printf("pq\n");
    PriorityQueue h=PQInit(11);
    PQInsert(5,h);
    PQInsert(4,h);
    PQInsert(2,h);
    PQInsert(6,h);
   

    
}
#endif