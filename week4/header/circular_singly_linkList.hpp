#ifndef circular_singly_linkList
#define circular_singly_linkList
#include <iostream>
#include "node.hpp"

class circular_singlylinkList{

    private:
       
        Snode* tail;
    public:
        circular_singlylinkList(){
            tail = nullptr;
        }
    void addvalue(int count){
        if (count <=0)
        {
           return;
        }
        for (int i = 1; i <= count; i++)
        {
            indsertEnd(i);
        }
        
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
    void indsertEnd(int val){
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
    void display() {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Snode* temp = tail->next; // start from head
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
};

#endif