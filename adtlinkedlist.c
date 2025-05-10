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



int main()
{
    FILE* file = fopen("input.txt", "r");
    if(file == NULL){
        return 1;
    }

    //arrayList list;
    linkedList list;
    init(&list);

    int func, param, param2;
     while(fscanf(file, "%d", &func) == 1 && func != 0)
    {
        if(func == 1 && fscanf(file, "%d", &param) == 1){
            printf("Insert %d\n", param);
            insert(param, &list);
            print(&list);
        }
        else if(func == 2){
            printf("Delete current item\n");
            int ret = delete_cur(&list);
            printf("%d is deleted\n", ret);
            print(&list);
        }
        else if(func == 3 && fscanf(file, "%d", &param) == 1){
            printf("Append %d\n", param);
            append(param, &list);
            print(&list);
        }
        else if(func == 4){
            int ret = size(&list);
            printf("Size of the list is %d\n", ret);
            print(&list);
        }
        else if(func == 5 && fscanf(file, "%d", &param) == 1){
            printf("Prev %d\n", param);
            prev(param, &list);
            print(&list);
        }
        else if(func == 6 && fscanf(file, "%d", &param) == 1){
            printf("Next %d\n", param);
            next(param, &list);
            print(&list);
        }
        else if(func == 7 && fscanf(file, "%d", &param) == 1){
            int ret = is_present(param, &list);
            if(ret){
                printf("%d is present\n", param);
            }
            else{
                printf("%d is not present\n", param);
            }
            print(&list);
        }
        else if(func == 8){
            printf("Clear list\n");
            clear(&list);
            print(&list);
        }
        else if(func == 9 && fscanf(file, "%d", &param) == 1){
            printf("Delete %d\n", param);
            delete_item(param, &list);
            print(&list);
        }
        else if(func == 10 && fscanf(file, "%d %d", &param, &param2) == 2){
            printf("Swap index %d and %d\n", param, param2);
            swap_ind(param, param2, &list);
       print(&list);
        }
        printf("\n");
    }

    free_list(&list);
    return 0;
}