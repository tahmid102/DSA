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

void modifyvalue(node* &head, node* target,int value){
    if(head==NULL || target==NULL) return;
    node* curr= head;
    while(curr){
        if(curr==target){
            
            break;
        }
        curr=curr->next;
    }
    if(curr==NULL) return;
    curr->data=value;
    return;
}

void printlist(node * head){
    node * curr=head;
    while(curr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main()
{
    node* head=createnode(10);
    head->next=createnode(20);
    head->next->next=createnode(30);
    printlist(head);
    cout<<endl;
    modifyvalue(head,head->next,90);
    printlist(head);
}