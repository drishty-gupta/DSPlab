#include<stdio.h>
#include<stdlib.h>
 
#define MAX 1000 //Maximum number of elements that can be stored
 
int top=-1,stack[MAX];
void push();
void pop();
void display();
 
void main()
{
int option;
int ele;
while(1) //infinite loop, will end when choice will be 4
{
printf("\n** Stack Menu **");
printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit");
printf("\n\nEnter your choice(1-4):");
scanf("%d",&option);
do{
		printf("\n\nEnter your choice:");
		scanf("%d",&option);

		if(option == 1){
		         printf("enter element:");
		         scanf("%d",&ele);
			push(ele);
		}
		else if(option == 2){
			pop();
		}
		else if(option == 3){
			display();
		}
		else if(option == 4);
		
		else
			printf("\nEnter a valid choice!");

	}while(option != 4);
}
 }
void push()
{
int val;
if(top==MAX-1)
{
printf("\nStack is full!!");
}
else
{
printf("\nEnter element to push:");
scanf("%d",&val);
top=top+1;
stack[top]=val;
}
}
 
void pop()
{
if(top==-1)
{
printf("\nStack is empty!!");
}
else
{
printf("\nDeleted element is %d",stack[top]);
top=top-1;
}
}
 
void display()
{
int i;
int stack[100];
if(top==-1)
{
printf("\nStack is empty!!");
}
else
{
printf("\nStack is...\n");
for(i=top;i>=0;i--)
{
printf("%d\n",stack[i]);
}
}
}
