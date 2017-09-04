/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#undef TEST

#define TEST 1

#if TEST==1

#include <stdio.h>

class A {
public:

    A() { printf("A\n");this->a=10;}
    A(int num):a(num) {printf("A \n");}
    A(const A& orign):a(orign.a) { printf("copy A\n");};

    virtual void foo() { printf("A:parents,foo\n");}
    
    virtual void bar() { printf("A:parents,bar\n"); }
    
    void p() { printf("parent\n"); }
    
    int a;
    
   virtual ~A() { printf("~A\n");};
   
};

    class B : public A {
    public:

        B() { printf("B \n"); this->a=11;}
        B(int num):b(num) { printf("construct B\n"); }
       
        void foo() { printf("B:foo\n"); }
        
        void bar() { printf("B:bar\n"); }
        
        void son() { printf("son\n"); }
        
        ~B() { printf("~B\n"); }
        //int a;
    protected:
        int b;
    };
    
    class C {
    public:
        C() { printf("C\n"); }
        
        void bar() { printf("C:bar\n"); }
        ~C() { printf("~C\n"); }
        
        int a;
        int b;
//        int b;
    };

    
    int main() {
        
       // A a3=A(1);
        B b;
        A a=b;
        printf("b.a is %d\n",a.a);
        
         
        return 0;
    }
    
#endif