#include<stdio.h>
#include<string.h>

char q[1000][1000];
int pri[1000];
int front =-1,rear =-1;
int size;
void insert(char *name,int pr)
{
	int i,j,pos,count=0;
	if(rear==(size-1))
	{
	   printf("QUEUE IS FULL.INSERTION IS NOT POSSIBLE.\n");
	   return;	
	}
	else if(rear==-1 && front==-1)    
	{
		front=0;
		rear=rear+1;
		for(j=0;name[j]!='\0';j++)
		{
		    q[rear][j]=name[j];	
		}
		
		pri[rear]=pr;
		
	}
	
	else     
	{
	
	for(i=front;i<=rear;i++)  
	{
	  if(pr>pri[i])    
	  {
	  	pos=i;
	  	count=100;
	  	break;
	  }
    }
    if(count==100) 
    {
	
    for(i=rear;i>=pos;i--)   
    {
    	for(j=0;q[i][j]!='\0';j++)
    	{
		
    	q[i+1][j]=q[i][j];
        }
        q[i+1][j]='\0';
    	pri[i+1]=pri[i];
	}
	for(j=0;name[j]!='\0';j++) 
		{
		    q[pos][j]=name[j];	
		}
		q[pos][j]='\0';
	
	    pri[pos]=pr;
	    rear=rear+1;
		
   }
   else     
   {
   	rear=rear+1;
   	for(j=0;name[j]!='\0';j++)
		{
		    q[rear][j]=name[j];	
		}
		q[rear][j]='\0';
   	   pri[rear]=pr;
   		
   }
}
	
	printf("SUCCESSFULLY INSERTION IS DONE..\n");
	
}
void delete()
{
	
	int t,i,j;
	if(front==-1)
	{
		printf("QUEUE IS EMPTY.DELETION IS NOT POSSIBLE\n");
		return;
	}
	if(front ==rear) 
	{
		
		
		front=-1;
		rear=-1;
		
		
	}
	else
	{
		
		for(i=front;i<=rear;i++)  
		{
			for(j=0;q[i+1][j]!='\0';j++)
			{
			
		    	q[i][j]=q[i+1][j];
		    }
		    q[i][j]='\0';
			pri[i]=pri[i+1];
		}
		front=0;
		rear=rear-1;
		
	}
	printf("SUCCESSFULLY DELETION IS DONE..\n");
	
	
}

void display()
{
 int i,j; 
 if(front==-1 && rear==-1  )
 {
 	printf("QUEUE IS EMPTY\n");
 	return;
  }
  if(rear==(size-1) && front==0)
  {
  	printf("Queue is full\n ");
  	
  }
  printf("GATE SCORE\tNAME\n");
  printf("..........\t....\n");
  for(i=front;i<=rear;i++)
  {
  	printf("%d\t\t",pri[i]);
  	puts(q[i]);
  	
	  
  	 
  	 
   }
   	
	
}
void main()
{
	int p=0;
	int n;
	char name[1000];
	printf("ENTER THE SIZE OF QUEUE: \n");
	scanf("%d",&size);
		while(p!=4)
	{
		printf("\nPRIORITY QUEUE OPERATIONS: \n");
	   	printf("\n ENTER \n 1 FOR INSERT DATA \n 2 FOR DELETE OPERATION \n 3.FOR DISPLAY\n 4.FOR EXIT\n");

        scanf("%d",&p);
	   if(p==1)
	   {
	   	     printf("Enter name & Gate score\n");
	   	     fflush(stdin);
	   	     gets(name);
	   	     
	   	     scanf("%d",&n);
	   		 insert(name,n);
	   }
	   	else if(p==2)
	   	{
		   
	   		delete();
	    }
	   	else if(p==3)
	   	{
	   		display();
		}
	   		
	   	else if(p==4)
	   	{ printf("exit");}
	   	     
	   	else
	   	{
	   		printf("ENTER VALID INPUT\n");
		}
	   		
	   		
	   
	   
    }  
	
}

