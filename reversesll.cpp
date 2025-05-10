#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}node;

node* createnode(int data){
    node* temp= new node();
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void reverselist(node*& head){
    if(head==NULL) return;
    if(head->next==NULL) return;
    node* prev=NULL;
    node* curr=head;
    node* post=NULL;
    while(curr){
        post=curr->next;
        curr->next=prev;
        prev=curr;
        curr=post;
    }
    head=prev;
}

void printlist(node * head){
    node * curr=head;
    while(curr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main(){

    node* head=createnode(10);
    head->next=createnode(20);
    head->next->next=createnode(30);
    printlist((head));
    reverselist(head);
    cout<<endl;
    printlist((head));

}
