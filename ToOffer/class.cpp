/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>

class A {
public:

    A() {printf("A \n");this->a=10;}

    virtual void foo() { printf("A:parents,foo\n");}
    
    virtual void bar() { printf("A:parents,bar\n"); }
    
    void p() { printf("parent\n"); }
    
    int a;
    
   virtual ~A() { printf("~A\n");};
   
};

    class B : public A {
    public:

        B() { printf("B \n");this->a=10; }

        void foo() { printf("B:foo\n"); }
        
        void bar() { printf("B:bar\n"); }
        
        void son() { printf("son\n"); }
        
        ~B() { printf("~B\n"); }
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
//        
//        A *c = new B;
//       
//        c->foo();
//        c->bar();
//        printf("size c is %d\n",sizeof(A));
//        delete c;
//       // A *a=new A;
//        printf("\n~~~~~~~~~~~~~~~\n");
//        B *b=new B;
//        b->foo();
//        b->bar();
//        printf("size b is %d\n",sizeof(b));
////        delete b;
//        //delete c;
        
        printf("\n~~~~~~~~~~~~~~~\n");
//        A *a=new A();
        A a;
        a.bar();
        printf("%d\n",a.a);
        
        
        return 0;
    }