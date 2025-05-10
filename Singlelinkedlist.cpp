//SLL

#include<iostream>
using namespace std;


class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }

};


//create new node

node* createnode(int data){
    node* temp = new node(data);  // Create a new node and return the pointer
    return temp;
}



//to traverse accross all the elements of the sll (loop)
void traversal(node *head){
    node* temp= head;
    while(temp){
        // code here
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}   //has time complexity of O(n).....linear....


//recursive approach

void traversalrecursion(node* head){
    node* temp=head;
    if(temp==NULL) return;
    //code
    cout<<temp->data<<" ";
    
    //temp=temp->next;
    traversalrecursion(temp->next);

}

//searching inside sll

bool search(int key, node* head){
    node* temp=head;
    while(temp){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"nai vai"<<endl;
        return false;
    }
}

bool searchwrecursion(int key, node* head){
    node* curr=head;
    if(curr==NULL) return false;
    if(curr->data==key) return true;
    searchwrecursion(key,curr->next);
}

//insertion in a SLL

// inserting node at beginning ie: head

void insertatbeginnigng(int data, node* &head){
    node* temp=createnode(data);
    temp->next=head;
    head=temp;
    

}

//insert at the end

void insertatheend(int data, node*& head){
    node* temp=createnode(data);
    temp->next=NULL;
    node* curr=head;
    if(head==NULL){
        head=temp;
        return;
    }
    while(curr->next){
        curr=curr->next;
    }
    if(curr->next==NULL){curr->next=temp;
        return;}
}

//insert after a ceertain node
void insertnodeatcerrt(int data, node*& head, node* target){
    if(head==NULL || target==NULL)return;
    node* temp=createnode(data);
    temp->next=NULL;
    node* curr=head;
    while(curr){
        if(curr==target){
            break;
        }
        curr=curr->next;
    }
    if(curr==NULL) return;
    node* post=curr->next;
    
    temp->next=post;
    curr->next=temp;


}



//is empty func

bool isempty(node* head){
    if(head==NULL) return true;
    else return false;
}


//deletion
//delete from begining

void deletefrombeg(node*& head){
    if(isempty(head)){
        return;
    }
    node* temp=head;
    head=head->next;
    delete temp;
    
}
//remember the parameter to be passed by reff

//delete from anywhere else
void deletenode(node*& head, node* target){
    if(head==NULL || target==NULL)return;
    node* curr=head;
    if(head==target){
        node* temp=head;
        head=head->next;
        delete temp;
        return;

    }
    while(curr->next){
        if(curr->next==target){
            break;
        }
        curr=curr->next;
    }
    if(curr->next==NULL)return;
    node* post=target->next;
    curr->next=post;
    delete target;

}


int main(){
    node* head=createnode(10);
    head->next=createnode(20);
    head->next->next=createnode(30);
    traversal(head);
    traversalrecursion(head);
    if(search(60,head)){
        cout<<"present"<<endl;
    }
    if(searchwrecursion(50,head)){
        cout<<"present"<<endl;
    }
    else{
        cout<<"absent"<<endl;
    }

    insertatbeginnigng(2,head);
    traversal(head);
    cout<<endl;
    insertatheend(5,head);
    traversal(head);
    cout<<endl;
    insertnodeatcerrt(7,head,head);
    traversal(head);
    cout<<endl;
    deletefrombeg(head);
    traversal(head);
    cout<<endl;
    deletenode(head,head);
    traversal(head);
    cout<<endl;
    
}