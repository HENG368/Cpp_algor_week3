#include<iostream>
#include"circular_singly_linkList.hpp"
#include"doubly_linkList.hpp"
#include"singly_linkList.hpp"
#include <chrono>
using namespace std;
int main (){
    Singly_linkList list;
    list.sll_observe(&list,void(&Singly_linkList::rotate(10))(),"duration");
}