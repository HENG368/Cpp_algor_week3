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
    void addValue_sll(int n){
        if (n <= 0) return ;
        for (int i = 1; i <= n; i++)
        {
            pushback(i);
        }
        
    }
    // Traversal with restart at head (for A1)
    void traver(){
        if (head == nullptr)
        {
            cout << " Node empty! ";
            return;
        }

        Snode* cur = head;
        
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout <<endl;
        
    }
    void pushfront(int val){
        Snode* new_Node = new Snode(val);
        new_Node->next  = head;
                head    = new_Node;
    }
    void pushback(int val){
        Snode* new_Node = new Snode(val);
        if (head == nullptr)
        {
            head = new_Node;
            return;
        }
        Snode* cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = new_Node;
    }

    void popHead(){
        if (head == nullptr)
        {
            return;
        }
        Snode* cur = head;
        head = head->next;
        delete cur ;
    }
    // Delete node when predecessor known (O(1))
    void deleteWithpre(Snode*pre){
        if (pre == nullptr || pre->next == nullptr)   return;
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
        if (pre && pre->next == Node)
        {
            pre->next = Node->next;
            delete Node;
        }
        
    }
    // Rotate right by k 
   void rotate(int k) {
        if (!head || !head->next) return;
        int len = 1;
        Snode* cur = head;
        while (cur->next) { 
            cur = cur->next;
            len++;
        } 
        k %= len;
        if (k == 0) return;

        int split = len - k;
        Snode* prev = nullptr;
        cur = head;
        for (int i = 0; i < split; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = nullptr;
        Snode* newHead = cur;

        Snode* tail = newHead;
            while (tail->next)
            {
                tail = tail->next;
            }
            tail->next = head;
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