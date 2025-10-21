#ifndef node
#define node
#include<iostream>

using namespace std;
struct Snode{
    int data;
    Snode* next;
    Snode(int val){
        this->data = val;
        this->next = nullptr;
    }
};
struct Dnode{
    int data;
    Dnode* next;
    Dnode* pre;
    Dnode(int val){
        this->data = val;
        this->next = nullptr;
        this->pre  = nullptr;
    }
};
#endif 