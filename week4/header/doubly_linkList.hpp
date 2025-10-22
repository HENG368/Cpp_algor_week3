#ifndef doubly_linkList
#define doubly_linkList
#include <iostream>
#include"node.hpp"

class doubly_linkList{
    private:
        Dnode* head;
        Dnode* pre;
    public:
        Dnode* addvalueDll(int n){
            if (n <=0)
            {
                return;
            }
            
            head  = new Dnode(0);
            Dnode* cur = head;
            for (int i = 1; i < n; i++)
            {
                Dnode* new_Node = new Dnode(i);
                cur->next = new_Node;
                new_Node->pre = cur;
                cur = new_Node;
            }
            return head;
        }
        
        void deleteDllNode(int pos){
            if (head == nullptr)
            {
                cout <<"Not empty!";
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
            for (int i = 1; i < pos; i++)
            {
                cur = cur->next;
            }
            if (cur == nullptr)
            {
                cout<< "Invalid position!";
                return;
            }
            
            if (cur->next != nullptr)
            {    
                cur->pre->next = cur->next;
            }
            
            if (cur->pre != nullptr)
            {
                cur->next->pre = cur->pre;
            }
            if (head == cur)
            {
                head = head->next;
            }
            delete cur;
        }
        
};

#endif