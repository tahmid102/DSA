#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node* next;
    struct node* prev;
}node;

typedef struct 
{
    node* head;
    node* tail;
    node* curr;
    int size;
    // declare head, tail, cur and other variables you need
}linkedList;

void init(linkedList* list)
{
    list->head=NULL;
    list->curr=NULL;
    list->tail=NULL;
    list->size=0;
}
void clear(linkedList* list);

void free_list(linkedList* list)
{
    clear(list);
    // implement destruction of list
}

void print(linkedList* list)
{
    node* temp=list->head;
    if(temp==NULL) {printf("[.]");
    return;}
    printf("[");
    while(temp){
        
        printf("%d",temp->element);
        if(temp==list->curr){
            printf("|");
        }
        printf(" ");
        temp=temp->next;
    }
    printf("]");
    // implement list printing
}

void insert(int item, linkedList* list)
{
   node *new=(node*)malloc(sizeof(node));
   new->element=item;
   new->next=NULL;
   new->prev=NULL;
   if(list->size==0){
    list->curr=list->head=list->tail=new;
   }
   else {
    new->prev = list->curr;
        new->next = list->curr->next;
        if (list->curr->next != NULL)
            list->curr->next->prev = new;
        else
            list->tail = new;

        list->curr->next = new;
        list->curr = new;
   }
    list->size++;
    // implement insert function
}

int delete_cur(linkedList* list)  //matha guracche
{
    if (list->curr == NULL || list->size == 0) return -1; //kake delete korbo(?_?)

    node* delete = list->curr;  
    int x = delete->element;

    if (list->size == 1) {
        list->head = list->tail = list->curr = NULL;  //vanish all em up
    }
    else if (delete == list->head) {
        list->head = delete->next;
        list->head->prev = NULL;
        list->curr = list->head;
    }
    else if (delete == list->tail) {
        list->tail = delete->prev;
        list->tail->next = NULL;
        list->curr = list->tail;
    }
    else {
        delete->prev->next = delete->next;
        delete->next->prev = delete->prev;
        list->curr = delete->next;
    }

    free(delete);
    list->size--;

    return x;
}


void append(int item, linkedList* list)
{
   node *new=(node*)malloc(sizeof(node));
   new->element=item;
   new->next=NULL;
   new->prev=NULL;
   if(list->size==0){
    list->curr=list->head=list->tail=new;
   }
   else{
    
    list->tail->next=new;
    new->prev=list->tail;
    list->tail=new;
    
   }
   list->size++;
}

int size(linkedList* list)
{
    return list->size;
}

void prev(int n, linkedList* list)
{
    for(int i=0;i<n;i++){
        if(list->curr==list->head){
           break;

        }
        list->curr=list->curr->prev;
    }

}

void next(int n, linkedList* list)
{
    for(int i=0;i<n;i++){
        if(list->curr==list->tail){
           break;

        }
        list->curr=list->curr->next;
    }
}

int is_present(int n, linkedList* list)
{
    node* check=list->head;
    
    int c=0;
    while(check){
        if(check->element==n){
            c++;
            break;
        }
        check=check->next;
       
    }
    
    return c;
}

void clear(linkedList* list)
{
    node* temp = list->head;
    while (temp != NULL) {
        node* next = temp->next;
        free(temp);
        temp = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->curr = NULL;
    list->size = 0;
    
}

void delete_item(int item, linkedList* list)
{
    node* temp=list->head;
    while(temp){
        if(temp->element==item){
            if(temp==list->tail){
                if(list->curr==list->tail){
                    list->curr=list->tail->prev;
                }
                list->tail=temp->prev;
                list->tail->next=NULL;
                
                
            }
            else if(temp==list->head){
                if(list->curr==list->head)list->curr=list->head->next;
                list->head=list->head->next;
                list->head->prev=NULL;
                
 
            }
            else{
                if(list->curr==temp){
                    list->curr=list->curr->next;
                }
                node* next=temp->next;
                node* prev=temp->prev;
                
                next->prev=prev;
                prev->next=next;

            }
            list->size--;
            if(list->curr==list->tail->next)list->curr=list->tail;
            break;
        }
        temp=temp->next;
    }
    if(!temp) printf("%d not found",item);
    
}

void swap_ind(int ind1, int ind2, linkedList* list)
{
    node* first=list->head;
    for(int i=0;i<ind1;i++)
    {
        if(!first) return;
        first=first->next;
    }
    node * sec= list->head;
    for(int i=0;i<ind2;i++)
    {
        if(!sec) return;
        sec=sec->next;
    }
    if(first && sec){
        int temp=first->element;
        first->element=sec->element;
        sec->element=temp;
    }
}

#endif
