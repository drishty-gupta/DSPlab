#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;
 
int topelement();
void push(int data);
void pop();
void empty();
void display();
void create();
 
int count = 0;
 
void main()
{
    int no, option, e;
 
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Top");
    printf("\n 4 - Display");
    printf("\n 5 - Exit");
   
 
    create();
 
    do
    {
        printf("\n Enter choice : ");
        scanf("%d", &option);
 
        if (option==1){
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
           }
         else if (option == 2){
            pop();
            }
         else if (option==3){
		    if (top == NULL){
		        printf("No elements in stack");
		    }
		    else
		    {
		        e = topelement();
		        printf("\n Top element : %d", e);
		    }}
         else if (option == 4){   
          display();
            }
         else if(option==5);
            else
            printf(" Wrong choice, Please enter correct choice  ");
           
        }while(option!=5);
    }

 
/* Create empty stack */
void create()
{
    top = NULL;
}
 
/* Count stack elements */
void stack_count()
{
    printf("\n No. of elements in stack : %d", count);
}
 
/* Push data into stack */
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
 
/* Display stack elements */
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }
 
/* Pop Operation on stack */
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\n Popped value : %d", top->info);
    free(top);
    top = top1;
    count--;
}
 
/* Return top element */
int topelement()
{
    return(top->info);
}
 
/* Check if stack is empty or not */
void empty()
{
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty with %d elements", count);
}
 
/* Destroy entire stack */
void destroy()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
 
    printf("\n All stack elements destroyed");
    count = 0;
}
