#ifndef sll_h
#define sll_h
#include"node.hpp"
#include<iostream>
#include <chrono>
#include <string>
using namespace std;
using clk = chrono::high_resolution_clock;


class Singly_linkList{
    Snode* head;
    Snode* tail;
    public:
        Singly_linkList(){
            head = nullptr;
            tail = nullptr;
        };
    // add value to sll 
    Snode* addValue_sll(int n){
        if (n <= 0) return nullptr;
        head = new Snode(0);
        Snode* cur  = head;

        for (int i = 1; i < n; i++)
        {
            cur->next = new Snode(i);
            cur  = cur->next;
        }
        return head;
    }
    // Traversal with restart at head (for A1)
    void traver(Snode* head , int n){
        Snode* cur = head;
        for (int i = 0; i < n; i++)
        {
            cout << cur->data << " " ;
            cur = cur->next;
        }
        
    }
    void pushfront(int val){
        Snode* new_Node = new Snode(val);
        new_Node->next  = head;
                head    = new_Node;
    }
    void pushback(int val){
        Snode* new_Node = new Snode(val);
        tail->next  = new_Node;
        tail = new_Node;
    }

    Snode* popHead(){
        if (head == nullptr)
        {
            return nullptr;
        }
        Snode* cur = head;
        head = head->next;
        delete cur ;
        return head;
    }
    // Delete node when predecessor known (O(1))
    void deleteWithpre(Snode*pre){
        Snode* Node = pre->next;
        pre->next = Node->next;
        delete Node;
    }

    // Delete node when only node pointer
    void deleteWithoutpre(Snode* Node ){
        if (Node == nullptr)
        {
            return;
        }
        if (Node == head)
        {
            popHead();
            return;
        }
        
        Snode* pre = head;
        while (pre && pre->next != Node )
        {
            pre = pre->next;
        }
        pre->next = Node->next;
        if (Node == tail)
        {
            tail = pre;
        }
        
        delete Node;
    }
    // Rotate right by k 
   void rotate(int k) {
    if (!head || !head->next) return;
    int len = 1;
    Snode* cur = head;
    while (cur->next) { cur = cur->next; len++; } 
    k %= len;
    if (k == 0) return;

    int split = len - k;
    cur = head;
    for (int i = 1; i < split; ++i) cur = cur->next;

    tail = cur;       
    Snode* newHead = cur->next;
    tail->next = nullptr;
    head = newHead;
    }

    void sll_observe(Singly_linkList* obj, void (Singly_linkList::*method)(), string msg) {
    auto t0 = clk::now();

    (obj->*method)();  // call the method

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout << msg << ": " << duration.count() << " nanosecond(s)" << endl;
    }

    
};

#endif