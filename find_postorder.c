#include<stdio.h>
#include<stdlib.h>
struct bstree
{
int data;
struct bstree *lchild,*rchild;
};
typedef struct bstree BST;
BST *root=NULL;
BST *create(BST *,int);
void inorder(BST *);
void preorder(BST *);
void postorder(BST *);
void search(BST *,int);
void main()
{
int ch;
int ele;
do
{
printf("\nPress 1 For Insertion.");
printf("\nPress 2 For Inorder Traversal.");
printf("\nPress 3 For Preorder Traversal.");
printf("\nPress 4 For Postorder Traversal.");
printf("\nPress 5 For Search Item.");
printf("\nPress 6 For Exit.");
printf("\nEnter Your Choice: ");
scanf("%d",&ch);
if (ch== 1){
printf("\nEnter Element: ");
scanf("%d",&ele);
root=create(root,ele);
getch();}

else if (ch== 2){
inorder(root);
getch();
}
else if (ch== 3){
preorder(root);
getch();}
else if (ch== 4){
postorder(root);
getch();
}
else if(ch== 5){
printf("\nEnter Element To Be Searched: ");
scanf("%d",&ele);
search(root,ele);
getch();}
else if(ch==6){exit(0);}
else  

printf("\nInvalid Choice... Try Again..");
getch();
}while(ch!=6);
}
BST *create(BST *node,int x)
{
if(node==NULL)
{
node=(BST *)malloc(sizeof(BST));
node->lchild=NULL;
node->rchild=NULL;
node->data=x;
}
else if(x)
node->lchild=create(node->lchild,x);
else if(x>=node->data)
node->rchild=create(node->rchild,x);
return node;
}
void inorder(BST *node)
{
if(node!=NULL)
{
inorder(node->lchild);
printf("%d ",node->data);
inorder(node->rchild);
}
}
void preorder(BST *node)
{
if(node!=NULL)
{
printf("%d ",node->data);
preorder(node->lchild);
preorder(node->rchild);
}
}
void postorder(BST *node)
{
if(node!=NULL)
{
postorder(node->lchild);
postorder(node->rchild);
printf("%d ",node->data);
}
}
void search(BST *node,int num)
{
if(node==NULL)
printf("\nThe Number Is Not Present.");
else if(node->data==num)
printf("\nElement Found.");
else if(node->data>num)
search(node->lchild,num);
else
search(node->rchild,num);
}
