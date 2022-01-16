#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{ 
  int data;
  struct node *link;
  }node;
  
  
node* insert_begin(int data, node *head)
{
	struct node *new =(struct node*)malloc(sizeof(struct node));
	new->data =data;
	new->link = head;
	head = new;
	return head;
}


void insert_end(int data , node *head)
{
	node *new =(node *)malloc(sizeof(node));
	node *t =head;
	while(t->link)
		t=t->link;
	t->link=new;
	new->link=NULL;
	new->data = data;
}

node *insert_place(int ele, int place , node *head)
{
	int i = 0;
	node *new =(node*)malloc(sizeof(node));
	node *t = head;
	
	if (place == 0)
	{
		head = insert_begin(ele, head);
		return head;
	}
	for(i = 1; i<place;i++)
		t = t->link;
	
	new->data = ele;
	new->link = t->link;
	t->link = new;
	
	return head;
}  
         
           
struct node *reverse_by_size(struct node *head, int size)
{       
        if (!head )
        return NULL;
        
        
        struct node* current = head;
        struct node* link = NULL;
        struct node* prev = NULL;
        int count = 0;
        
        
        while(current!= NULL && count<size)
        { 
               link = current -> link;
               current -> link = prev;
               prev = current;
               current = link;
               count++;
         }
         
        
                       
         if (link!= NULL)
         head -> link = reverse_by_size (link , size);
         
         return prev;
}

void printlist(struct node *node)
{
     while(node!=NULL)
     { 
       printf("%d " , node->data);
       node = node ->link;
     }
}
       
                 
int main(){
        node *head; 
	int ele , size ,place, option;
	head = NULL;
	printf("select any opration to perform  \n 1.insert at begin \n 2. insert at end \n 3. insert at place \n 4.reverse by size \n 5.exit \n");
	printf("the position starts at zero !! ");
	
            do{
		printf("\n\nEnter your choice:");
		scanf("%d",&option);

		if(option == 1){
			printf("\nEnter element:");
			scanf("%d", &ele);
			head = insert_begin(ele, head);
		}
		else if(option == 2){
			printf("\nEnter element:");
			scanf("%d", &ele);
			insert_end(ele, head);
		}
		else if(option == 3){
			printf("\nEnter element:");
			scanf("%d", &ele);
			printf("Enter a place:");
			scanf("%d",&place);
			head = insert_place(ele,place, head);
		}
		else if(option == 4){
			printf("Enter size:");
			scanf("%d",&size);
			printf("\n given linked list \n");
			printlist(head);
			head = reverse_by_size(head,size);
			printf("\n reversed linked list \n");
			printlist(head);
		}
			
		else if(option == 5);
		else 
	        	printf("enter a valid choice !!");
	        	}while(option!=5);
	        	
	        	
         	return 0;
	        	}
