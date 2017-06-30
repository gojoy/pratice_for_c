#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include "test.c"
#include <stdio.h>

#define HELLO {printf("hello");}

int say();

int sayhello();

int hello()
{
    printf("test.h:hello\n");
    return 0;
}




#endif // TEST_H_INCLUDED

