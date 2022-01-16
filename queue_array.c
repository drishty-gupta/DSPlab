#include<stdio.h>
#include<stdlib.h>
 
int queue[1000];
int front=-1;
int rear=-1;
int size;
 
int isEmpty(){
    if(front==-1){
        return 1;
    }
    return 0;
}
 
int isFull(){
    if(rear==(size-1)){
        return 1;
    }
    return 0;
    
}
 
int enqueue(int val){
    if(isFull())
	{
        printf("This Queue is full\n");
        return 0;
        
    }
    if(front==-1 || rear==-1)
    {
    	front=0;
	}
    
    rear++;
    queue[rear]=val;
    printf("Enqued element: %d\n", val);
    
    printf("enqueue is successfull\n");
}
 
 void display()
{
    int i;
    if (front==0 && rear==(size-1))
    {
        printf("queue is empty");
        return ;
    }
 
    else
    {
    	for(i=front;i<=rear;i++)
    	{
    		 printf("%d ", queue[i]);
		}
       
        
    }
 }

int dequeue(){
    int a = -1;
    if(isEmpty()){
        printf("This Queue is empty\n");
        return 1;
    }
    else{
        a=queue[front];
        front++;
    }
    printf("Deque is successfull\n");
    return a;
}
 
int main(){
    
int option,p,t;
int val;
printf("ENTER THE QUEUE SIZE\n");
scanf("%d",&size);
while(1)
{
 
printf("\n** queue Menu **");
printf("\n\n1.enqueue\n2.deueue\n3.Display\n4.Exit");
printf("\n\nEnter your choice(1-4):");
scanf("%d",&option);
do{
	printf("\n** queue Menu **");
printf("\n\n1.enqueue\n2.deueue\n3.Display\n4.Exit");
printf("\n\nEnter your choice(1-4):");
		printf("\n\nEnter your choice:");
		scanf("%d",&option);

		if(option == 1){
		         printf("enter element:");
		         scanf("%d",&val);
			     t=enqueue(val);
		}
		else if(option == 2){
			p=dequeue();
			printf("\nDELETED ELEMENT=%d\n",p);
		}
		else if(option == 3){
			display();
		}
		else if(option == 4);
		
		else
			printf("\nEnter a valid choice!");

	}while(option != 4);

 
 
 
    return 0;
}
}
