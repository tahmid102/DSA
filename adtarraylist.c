#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *array;
    int maxsize;
    int size;
    int curr;
} arrayList;

void init(arrayList* list)
{
    list->maxsize=2;
    list->array=(int*)malloc(sizeof(int)*(list->maxsize));
    
    list->size=0;
    list->curr=0;
}

void free_list(arrayList* list)
{
    free(list->array); 
    list->size=0;
    // implement destruction of list
}

void increase_capacity(arrayList* list)
{
    int new_capacity=2*list->maxsize;
    int *newarray=(int*)malloc(sizeof(int)*new_capacity);
    for(int i=0;i<list->size;i++){
        newarray[i]=list->array[i];
    }
    free(list->array);
    list->array=newarray;
    list->maxsize=new_capacity;
    printf("Capacity increased from %d to %d\n",list->maxsize/2,list->maxsize);


    // implement capacity increase
}

void decrease_capacity(arrayList* list)
{
    int new_capacity=list->maxsize/2;
    int *newarray=(int*)malloc(sizeof(int)*new_capacity);
    for(int i=0;i<list->size;i++){
        newarray[i]=list->array[i];
    }
    free(list->array);
    list->array=newarray;
    list->maxsize=new_capacity;
    printf("Capacity decreased from %d to %d\n",list->maxsize*2,list->maxsize);

    
    // implement capacity decrease
}

void print(arrayList* list)
{
    if(list->size==0){
        printf("[ . ]");
        return;
    }
    
    printf("[");
    for(int i=0;i<list->size;i++){
        
        printf("%d",list->array[i]);
        if(i==list->curr-1){
            printf("|");
        }
        
        printf(" ");
       
    }
    printf("]");

   
}



void insert(int item, arrayList* list)
{
    if(list->maxsize>list->size*2){
        
        list->curr++;
        
        for(int i=list->size;i>=list->curr;i--){
            list->array[i]=list->array[i-1];
        }
        list->array[list->curr-1]=item;
        list->size++;
    }
    else{
        increase_capacity(list);
        list->array[list->size]=item;
        list->curr++;
        list->size++;
    
    }
}

int delete_cur(arrayList* list)
{
    int t=list->array[list->curr-1];
    for(int i=list->curr-1;i<list->size-1;i++){
        list->array[i]=list->array[i+1];
    }
    if(list->curr-1>0)list->curr--;
    list->size--;
    if(list->maxsize>list->size*4){
        decrease_capacity(list);
    }
    if(list->curr<list->size)list->curr++;
  
   
    return t;
    // implement deletion of current index function
}

void append(int item, arrayList* list)
{
   
    list->array[list->size]=item;
        list->size++;
    if(list->size*2>list->maxsize){
        increase_capacity(list);
    }    

    // implement append function
}

int size(arrayList* list)
{
    return list->size;
    // implement size function
}

void prev(int n, arrayList* list)
{
    // implement prev function
    if(list->curr-n>=0){
        list->curr-=n;
    }
    else list->curr=0;
}

void next(int n, arrayList* list)
{
    // implement next function
    if(list->curr+n<list->size){
        list->curr+=n;
    }
    else list->curr=list->size;
}

int is_present(int n, arrayList* list)
{
    int c=0;
    for(int i=0;i<list->size;i++){
        if(list->array[i]==n){
            c++;
            break;
        }
    }
    return c;
    // implement presence checking function
}

void clear(arrayList* list)
{
    
    list->size=0;
    list->curr=0;
    // implement list clearing function
}

void delete_item(int item, arrayList* list)
{
    
    int idx=-1;
    for(int i=0;i<list->size;i++){
        if(list->array[i]==item){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        printf("%d not found",item);
        return;
    }
    for(int i=idx;i<list->size-1;i++){
        list->array[i]=list->array[i+1];
    }
        list->size--;
        if (list->size == 0) {
            list->curr = 0;
        } else if (list->curr > list->size) {
            list->curr = list->size;
        }
        if(list->size*4<list->maxsize){
            decrease_capacity(list);
        }
        
    }
    // implement item deletion function


void swap_ind(int ind1, int ind2, arrayList* list)
{
    if (ind1 >= list->size || ind2 >= list->size) return;
    int temp=list->array[ind1];
    list->array[ind1]=list->array[ind2];
    list->array[ind2]=temp;
}



int main()
{
    FILE* file = fopen("input.txt", "r");
    if(file == NULL){
        return 1;
    }

    arrayList list;
    // linkedList list;
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

// you can define helper functions you need