#ifndef Doubly_linkList
#define Doubly_linkList
#include <iostream>
#include"node.hpp"

class doubly_linkList{
    private:
        Dnode* head;
        Dnode* pre;
    public:

        doubly_linkList() {
            head = nullptr;
            pre  = nullptr;
        }

        void addvalueDll(int n){
            if (n <=0)
            {
                return;
            }
            for (int i = 1; i <= n; i++)
            {
                insertEnd(i);
            }
            
        }
        void insertEnd(int val){
            Dnode* new_Node = new Dnode(val);
            if (head == nullptr)
            {
                head = pre = new_Node;
                return;
            }

            pre->next = new_Node;
            new_Node->pre = pre;
            pre = new_Node;
            
        }
        void insertFront(int val){
            Dnode* new_Node = new Dnode(val);
            if (head == nullptr)
            {
                head = pre = new_Node;
                return;
            }
            
            new_Node->next = head;
            head->pre      = new_Node;
            head = new_Node;
        }
        void deleteDllNode(int pos){
            if (head == nullptr)
            {
                cout <<"Node empty!";
                return;
            }
            Dnode* cur = head;
            if (pos ==  1)
            {
               head = head->next;
               head->pre = nullptr;
               delete cur;
               return;
            }
            for (int i = 1; i < pos && cur != nullptr; i++)
            {
                cur = cur->next;
            }
            if (cur == nullptr)
            {
                cout<< "Invalid position!";
                return;
            }
            
            if (cur->pre != nullptr)
            {    
                cur->pre->next = cur->next;
            }
            
            if (cur->next != nullptr)
            {
                cur->next->pre = cur->pre;
            }
            if (head == cur)
            {
                head = head->next;
            }
            delete cur;
        }
    void displayForword(){
        if (head == nullptr)
        {
            cout << "Node empty!";
            return;
        }
        Dnode* cur =  head;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    //  Real-world use cases
    void add_remove_FrontDll(int ops){
        head = nullptr;
        for (int i = 0; i < ops; i++)
        {
            if (rand()%2 == 0)
            {
                Dnode* new_Node = new Dnode(i);
                new_Node->next  = head;
                if(head) head->pre   = new_Node;
                head = new_Node;
            }
            else
            {
                if (head)
                {
                    
                    Dnode* temp = head;
                    head = head->next;
                    if(head) head->pre = nullptr;
                    delete temp;
                }
                
            }
            
            
        }
        
    }   
};

#endif