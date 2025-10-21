#ifndef circular_singly_linkList
#define circular_singly_linkList
#include <iostream>
#include "node.hpp"

class circular_singlylinkList{

    private:
       
        Snode* tail;
    public:
        circular_singlylinkList();
    void addvalue(int count){
        if (count <=0)
        {
           return;
        }
        
        tail = new Snode(0);
        Snode* cur  = tail;
        for (int i = 0; i < count; i++)
        {
            cur->next = new Snode(i);
        }
        cur->next = tail;
        tail = cur;
    }

    void  insertFront(int val){
        Snode* new_Node = new Snode(val);
        if (tail == nullptr)
        {
            tail = new_Node;
            new_Node->next = new_Node;
            return;
        }
        new_Node->next = tail->next;
        tail->next     = new_Node;
    }
    void indertEnd(int val){
        Snode* new_Node = new Snode(val);
        if (tail == nullptr)
        {
            tail = new_Node;
            new_Node->next = new_Node;
            return;
        }
        new_Node->next = tail->next;
        tail->next     = new_Node;
        tail = new_Node;
    }

    void deleteNode(){
        Snode* head = tail->next;
        if (tail == nullptr)
        {
            cout << "node empty!";
            return;
        }
        
        if (head == tail)
        {
            delete head;
            tail = nullptr;
        }
        tail->next = head->next;
        delete head;
    }
};

#endif