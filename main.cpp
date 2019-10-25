#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    node* next;
    node* back;
    int data;
};
class mylist{
public:
    node* head;
    node* d_node;
    mylist(){
        d_node->next=NULL;
        d_node->back=NULL;
        d_node->data=0;
        head=d_node;

    }
    mylist(int value,int size){
        head= new node();
        d_node= new node();
        node* crr=new node();
        head->data=value;
        head->next=crr;
        head->back=NULL;
        for(int i=1;i<size;i++){
              node* new_node=new node();
              new_node->data=value;
              crr->next=new_node;
              new_node->back=crr;
              crr=new_node;
        }
        d_node->next=NULL;
        d_node->data=value;
        d_node->back=crr;

    }
    class iterator{
    public:
    node* n;
    mylist list;
    iterator Begin(){
        iterator it;
        it.n= list.head;
        return it;
    }
    iterator End(){
        iterator it;
        it.n=list.d_node;
        return it;
    }

void operator++(){
    if(n->next!=NULL){
    n=n->next;
    }
    else{
        throw "error";
    }
}

void operator--(){
    if(n->back!=NULL){
    n=n->back;
    }
    else{
        throw "error";
    }
}
int operator*(){
    return n->data;
}
bool operator==(const iterator& i){
    if(i.n==n){
        return true;
    }
    return false;
}

};
void insert(int value, iterator it){
    node* new_node= new node();
    if(it.n==head){
        new_node->data=value;
        new_node->next=head;
        new_node->back=NULL;
        head=new_node;
        return;
    }
    else{
        new_node->next=it.n;
        new_node->back=it.n->back;
        new_node->data=value;
        it.n->back->next=new_node;
        it.n->back=new_node;
    }
}
node* begin(){
    return head;
}
node* end(){
    node* crr1=NULL;
    if(head==NULL){
        return crr1;
    }
    crr1=head;
    if(head->next==NULL){
        return head;
    }
    else{
        while(crr1->next!=NULL){
            crr1=crr1->next;
        }
        return crr1;
    }
}
~mylist(){
 node* crr=head;
 while(crr!=NULL){
    node* delete_node=new node();
    delete_node=crr;
    crr=crr->next;
    delete(delete_node);
 }
 delete(crr);
}
int size(){
    int counter=0;
    if(head==NULL){
        return counter;
    }
    else if(head->next==NULL){
        counter++;
        return counter;
    }
    else{
        node* crr=head;
        while(crr!=NULL){
            counter++;
            crr=crr->next;
        }
        return counter;
    }
}
};
int main()
{


    return 0;
}
