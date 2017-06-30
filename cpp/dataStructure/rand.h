/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rand.h
 * Author: gg
 *
 * Created on 2017年6月23日, 上午11:22
 */

#ifndef RAND_H
#define RAND_H
#include <stdint.h>
int32_t redisLrand48();
void redisSrand48(int32_t seedval);

#define REDIS_LRAND48_MAX INT32_MAX

#endif /* RAND_H */
