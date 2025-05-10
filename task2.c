#include<stdio.h>
#include<stdlib.h>
#include "arraylist.h"
// #include "linkedlist.h"

int main()
{
    FILE* file = fopen("in_prob.txt", "r");
    if(file == NULL){
        return 1;
    }

    arrayList dal, fl;
     //linkedList dal, fl;
    
    // initialize the lists
    init(&dal);
    init(&fl);

    int func, param;
    while(fscanf(file, "%d", &func) == 1 && func != 0)
    {
        if(func == 1 && fscanf(file, "%d", &param) == 1){
            printf("Recruit %d\n", param);
            if(!is_present(param,&dal) && !is_present(param,&fl))append(param,&dal);
            printf("DA list: ");
            print(&dal);
            if(size(&fl)){
                printf("Foe list: ");
                print(&fl);
            }
            
        }
        else if(func == 2 && fscanf(file, "%d", &param) == 1){
            printf("Fire %d\n", param);
            delete_item(param,&dal);
            append(param,&fl);
            printf("DA list: ");
            print(&dal);
            if(size(&fl)){
                printf("Foe list: ");
                print(&fl);
            }

            // implement logic here
        }
        else if(func == 3 && fscanf(file, "%d", &param) == 1){
            printf("Check %d\n", param);
            //implement logic here
            if(is_present(param,&dal)){
                printf("Friend");
            }
            else if(is_present(param,&fl))
            {
                printf("Foe");
            }
            else{
                printf("Unknown");
            }
        }
        
        else{
            break;
        }
        printf("\n");
    }
   
    // free memory
    clear(&dal);
    clear(&fl);
    
    return 0;
}