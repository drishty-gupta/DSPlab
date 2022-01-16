#include <stdio.h>
#include<stdlib.h>

typedef struct queue
{
	struct node
	{
		int data;
		struct node *next;
	}*rear, *front;
}queue;

typedef struct node node;

void enqueue(queue *q, int *q_n)
{
	int number;
	node *n;
	n = (node *)malloc(sizeof(node));
	if (n == NULL)
	{
		printf("\n\nOverflow\n\n");
		return;
	}
	
	if (q->rear == NULL && q->front == NULL)
	{
		q->front = n;
	}
	else
	{
		q->rear->next = n;
	}
	

	printf("\n\nEnter a number\n");
	scanf("%d", &number);
	

	q->rear = n;
	n->data = number;
	n->next = NULL;
	
	*q_n += 1;
}

void dequeue(queue *q, int *q_n)
{
	int number;

	if (q->rear == NULL && q->front == NULL)
	{
		printf("\n\nUnderflow\n\n");
		return;
	}
	
	
	number = q->front->data;
	q->front = q->front->next;
	

	printf("\n\nThe dequeued value is = %d\n\n", number);
	
	
	if (q->front == NULL)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	
	*q_n -= 1;
}

void display(queue *q)
{
	node *n;
	
	n = q->front;
	
	if (q->front == NULL && q->rear == NULL)
	{
		printf("\n\nSorry your list is empty\n\n");
		return;
	}
	
	printf("\n\nThe queue list is");
	while(n != NULL)
	{
		printf("\t%d->", n->data);
		n = n->next;
	}
	
	printf("\n\n");
	return;
}

int give_your_choice()
{
	int choice;
	printf("1-> Enqueue\n");
	printf("2-> Dequeue\n");
	printf("3-> Display\n");
	printf("0-> Exit\n");
	printf("\nEnter your choice\n");
	scanf("%d",&choice);
	return choice;
}

void main()
{
	queue *q1, *q2, *q3, *q4;
	int q11, q22, q33, q44;
	int choice = 1, i =0;
	
	q1 = (queue *)malloc(sizeof(queue));
	q1->rear = NULL;
	q1->front = NULL;
	q11 = 0;
	
	q2 = (queue *)malloc(sizeof(queue));
	q2->rear = NULL;
	q2->front = NULL;
	q22 = 0;
	
	q3 = (queue *)malloc(sizeof(queue));
	q3->rear = NULL;
	q3->front = NULL;
	q33 = 0;
	
	q4 = (queue *)malloc(sizeof(queue));
	q4->rear = NULL;
	q4->front = NULL;
	q44 = 0;
	
	printf("\nElements for queue1\n");
	for (i = 0; i<5; i++)
	{
		enqueue(q1, &q11);
	}
	
	printf("\nElements for queue2\n");
	for (i = 0; i<3; i++)
	{
		enqueue(q2, &q22);
	}
	
	printf("\nElements for queue3\n");
	for (i = 0; i<2; i++)
	{
		enqueue(q3, &q33);
	}
	
	printf("\nElements for queue4\n");
	for (i = 0; i<6; i++)
	{
		enqueue(q4, &q44);
	}
	
	while (choice != 0)
	{
		choice = give_your_choice();
		
		if(choice == 1)
		{
			if ((q11 <= q22) && (q11 <= q33) && (q11 <= q44))
				enqueue(q1, &q11);
			
			else if ((q22 <= q11) && (q22 <= q33) && (q22 <= q44))
				enqueue(q2, &q22);
				
			else if ((q33 <= q11) && (q33 <= q22) && (q33 <= q44))
				enqueue(q3, &q33);
			
			else
				enqueue(q4, &q44);
		}
		
		else if(choice == 2)
		{
			if ((q11 >= q22) && (q11 >= q33) && (q11 >= q44))
				dequeue(q1, &q11);
			
			else if ((q22 >= q11) && (q22 >= q33) && (q22 >= q44))
				dequeue(q2, &q22);
				
			else if ((q33 >= q11) && (q33 >= q22) && (q33 >= q44))
				dequeue(q3, &q33);
			
			else
				dequeue(q4, &q44);
		}
		
		else if (choice == 3)
		{
			display(q1);
			display(q2);
			display(q3);
			display(q4);
			
			printf("q11 = %d\t q22 = %d\t q33 = %d\t q44 = %d\n\n", q11, q22, q33, q44);
		}
		
		else if (choice == 0)
		
			return;
		
		
		else
			printf("\n\nenter correct\n\n");
	}
}
