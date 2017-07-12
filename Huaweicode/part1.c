/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "part1.h"
#include <stddef.h>
#include <string.h>

int last_count(const char *s) {
    int count = 0;
    int i;
    if (s == NULL)
        return -1;

    for (i = 0; i < strlen(s)-1; i++) {
        if(s[i]!=' ')
            count++;
        if(s[i]==' ' && s[i+1]!=' ' && s[i+1]!=10) {
            count=0;
        }
       
    }
    return count;
}

int last_count1(const char *buf) {
    printf("len is %d\n",strlen(buf));
    int i,count=0;
    if( buf==NULL)
        return 0;
    i=strlen(buf)-1;
    while(i>=0) {
        if(buf[i]!=' '&& buf[i]!=10)
            break;
        printf("i -- is %d\n",i);
        i--;
    }
    
    printf("i is %d\n",i);
    for(;i>=0;i--) {
        printf("bufi is %c,",buf[i]);
        if(buf[i]==' ')
            break;
        count++;
    }
    return count;
}

int showstr(const char *c) {
    for(int i=0;i<strlen(c);i++) {
        printf("i is %d,si is %d\n",i,c[i]);
    }
    return 0;
}