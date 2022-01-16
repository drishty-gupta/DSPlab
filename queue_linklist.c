#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;
 
struct Node
{
    int data;
    struct Node *next;
};
// struct Node *ptr = NULL;
void linkedListTraversal()
{
struct Node *ptr;
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
 
void enqueue(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
 
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
 
 
    void main()
{
    int no, option, e;
 
    printf("\n 1 - enqueue");
    printf("\n 2 - dequeue");
    printf("\n 3 - display");
    printf("\n 4 - exit");
   
 
   
 
    do
    {
        printf("\n Enter choice : ");
        scanf("%d", &option);
 
        if (option==1){
            printf("Enter data : ");
            scanf("%d", &no);
            enqueue(no);
           }
         else if (option == 2){
            dequeue();
            }
         
         else if (option == 3){
           //struct Node *e = t;   
           linkedListTraversal();
            }
         else if(option==4);
            else
            printf(" Wrong choice, Please enter correct choice  ");
           
        }while(option!=4);
    }

