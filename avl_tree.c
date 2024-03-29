#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
typedef struct node
{
	int data;
	struct node *left,*right;
	int ht;
}node;

typedef struct sum
{
	int total;
}sum;
 
node *insert(node *,int);
node *Delete(node *,int);
void currentlevel(node *, int);
void preorder(node *);
void inorder(node *);
void postorder(node *);
void sum_of_left_sub_tree(node *root, sum *s);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);
 
int main()
{
node *root=NULL; sum *s;
int x,n,i,op;
	printf("\n1)Create:");
	printf("\n2)Insert:");
	printf("\n3)Delete:");
	printf("\n4)Print inorder:");
	printf("\n5)Print preorder:");
	printf("\n6)Print postorder:");
	printf("\n7)Print levelorder:"); 
	printf("\n8)sum of nodes in left subtree:");
	printf("\n9)Quit:");
do
{
	
	printf("\n\nEnter Your Choice:");
	scanf("%d",&op);
if(op==1)
{
	printf("\nEnter no. of elements:");
	scanf("%d",&n);
	printf("\nEnter tree data:");
	root=NULL;
	for(i=0;i<n;i++)
	{
	scanf("%d",&x);
	root=insert(root,x);
}}
else if(op==2)
{
	printf("\nEnter a data:");
	scanf("%d",&x);
	root=insert(root,x);
}
else if(op==3)
{
	printf("\nEnter a data:");
	scanf("%d",&x);
	root=Delete(root,x);
}
else if(op==4)
{
	printf("\nInorder sequence:\n");
	inorder(root);
}
else if(op==5)
{
	printf("\nPreorder sequence:\n");
	preorder(root);
}
else if(op==6)
{
	printf("\nPostorder sequence:\n");
	postorder(root);
}
else if(op==7)
{
        printf("\nLevelorder sequence:\n");
	//height = height(node);
    /* Calling current level function, by passing levels one by one. */
    printf("\nThe height is %d\n",height(root));
    for(i = 0; i <= height(root); ++i)    
    { 
        currentlevel(root,i);
    }
   // printf("\nLevelorder sequence:\n");
	//Levelorder(root);
}
else if(op==8)
{       
              s->total = 0;
			sum_of_left_sub_tree(root->left, s);
			printf("\nThe sum of the left subtree of the root is %d\n\n", s->total);
      
}
else if(op==9);
else
	printf("\nEnter a valid choice!"); 
	
}while(op!=9);

return 0;
}
 
node * insert(node *T,int x)
{
	if(T==NULL)
	{
	T=(node*)malloc(sizeof(node));
	T->data=x;
	T->left=NULL;
	T->right=NULL;
}
else if(x > T->data) // insert in right subtree
{
	T->right=insert(T->right,x);
	if(BF(T)==-2)
	if(x>T->right->data)
	T=RR(T);
	else
	T=RL(T);
}
else if(x<T->data)
{
	T->left=insert(T->left,x);
	if(BF(T)==2)
	if(x < T->left->data)
	T=LL(T);
	else
	T=LR(T);
}
T->ht=height(T);
return(T);
}
 
node * Delete(node *T,int x)
{
node *p;
if(T==NULL)
{
	return NULL;
}
else if(x > T->data) // insert in right subtree
{
	T->right=Delete(T->right,x);
	if(BF(T)==2)
	if(BF(T->left)>=0)
	T=LL(T);
	else
	T=LR(T);
	}
else if(x<T->data)
{
	T->left=Delete(T->left,x);
	if(BF(T)==-2) //Rebalance during windup
	if(BF(T->right)<=0)
	T=RR(T);
	else
	T=RL(T);
}
else
{
//data to be deleted is found
if(T->right!=NULL)
{ //delete its inorder succesor
p=T->right;
while(p->left!= NULL)
	p=p->left;
	T->data=p->data;
	T->right=Delete(T->right,p->data);
	if(BF(T)==2)//Rebalance during windup
if(BF(T->left)>=0)
T=LL(T);
else
T=LR(T);\
}
else
return(T->left);
}
T->ht=height(T);
return(T);
}
 
int height(node *T)
{
int lh,rh;
if(T==NULL)
return(0);
if(T->left==NULL)
lh=0;
else
lh=1+T->left->ht;
if(T->right==NULL)
rh=0;
else
rh=1+T->right->ht;
if(lh>rh)
return(lh);
return(rh);
}
 
node * rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 
node * rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 
node * RR(node *T)
{
	T=rotateleft(T);
	return(T);
}
 
node * LL(node *T)
{
	T=rotateright(T);
	return(T);
}
 
node * LR(node *T)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);
	return(T);
}
 
node * RL(node *T)
{
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return(T);
}
 
int BF(node *T)
{
int lh,rh;
if(T==NULL)
return(0);
 
if(T->left==NULL)
lh=0;
else
lh=1+T->left->ht;
 
if(T->right==NULL)
rh=0;
else
rh=1+T->right->ht;
 
return(lh-rh);
}
 
void preorder(node *T)
{
	if(T!=NULL)
	{
	printf("%d(Bf=%d)",T->data,BF(T));
	preorder(T->left);
	preorder(T->right);
	}
}
 
void inorder(node *T)
{
	if(T!=NULL)
	{
	inorder(T->left);
	printf("%d(Bf=%d)",T->data,BF(T));
	inorder(T->right);
	}
}

void postorder(node *T)
{
	if(T!=NULL)
	{
	postorder(T->left);
	postorder(T->right);
	printf("%d(Bf=%d)",T->data,BF(T));
	}
}


/*
 * Function to print all the nodes left to right of the current level
 */
void currentlevel(struct node *root, int level)
{
    if (root != NULL) 
    {
        if (level == 1)
        {
            printf("%d ", root->data);
        }
        else if (level > 1) 
        { 
            currentlevel(root->left, level-1); 
            currentlevel(root->right, level-1);
        }			
    }
    else
    	printf("\nNo root\n");
}

void sum_of_left_sub_tree(node *root, sum *s)
{
	if (root == NULL)
		return;
		
	sum_of_left_sub_tree(root->left, s);
	sum_of_left_sub_tree(root->right, s);
	s->total += root->data;
	}


