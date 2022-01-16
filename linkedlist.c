#include<stdio.h>
#include<stdlib.h>

typedef struct node{
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

node *Delete_place(int place, node *head){

	node *temp;
	
	temp = head;
	
	int i = place;
	
	if(head == NULL)
	{
		printf("\nEmpty List");
		return head;
	}
	
	if (place == 0)
	{
		head = temp->link;
		
		return head;
	}
	
	else{
		while(--i){
			if(temp->link == NULL){
				printf("\nNo position available. Failed to delete element");
				return head;
			}
			temp = temp->link;
		}
		
		temp->link = temp->link->link;
		
		
		printf("\nSuccessfully deleted the element at position %d of the list.",place);
		
		return head;
	}
}

node *Delete_Val(int value, node *head){

	node *t = head;
	
	if(t->data == value)
	{
		head = t->link;
		return head;
	}
	
	while(t->link->data != value)
		t=t->link;
	
	t->link = t->link->link;
	
	return head;
	
}

node *reverse(node *cur){
	 struct node *prev = NULL;
	 struct node *nextnode;
	 nextnode = NULL;
	 while(cur){
 		nextnode = cur-> link;
		cur->link = prev;
		prev =cur;
		cur= nextnode;
	 }
	 return prev;
 }

void show(node *head){
	node *temp;
	temp = head;
	if(head == NULL)
	{
		printf("\nEmpty list");
		return;
	}
	printf("\n[HEAD] ");

	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->link;
	}
	
	printf("[NULL]");
}


int  main(){

	node *head;
	int ele, place, option;
	char ans;

	head = NULL;

	printf("\n Operations to perform on linked list : \n");
	printf("\n1. Insert at Beginning\n  2. Insert at End\n 3. Insert at place\n 4. Delete at a place\n 5. Delete a value\n 6. show\n 7. Reverse the list\n 8. Exit\n");
	printf("\nNOTE - Position starts at 0.\n");
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
			printf("Enter a place:");
			scanf("%d",&place);
			head = Delete_place(place, head);
		}
			
		else if(option == 5){
			printf("\nEnter element:");
			scanf("%d", &ele);
			head = Delete_Val(ele, head);
		}
		
		else if(option == 6)
			show(head);
			
		else if(option == 7)
			head = reverse(head);
		
		else if(option == 8);
		else
			printf("\nEnter a valid choice!");

	}while(option != 8);
	
	return 0;
}



