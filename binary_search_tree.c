#include<stdio.h>
#include<stdlib.h>
#define MAX 500

struct node
{ 
   int data;
   struct node *left;
   struct node *right;
};

struct node *newNode(int data)
{
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp -> data = data;
   temp -> left = temp -> right = NULL;
   return temp;
}

struct node **createQueue(int *front , int *rear)
{
   struct node **queue = (struct node **)malloc(sizeof(struct node *)*MAX);
   *front = *rear = 0;
   return queue;
}

void enqueue(struct node **queue,int *rear,struct node *newNode)
{
   queue[(*rear)++] = newNode;
}

struct node *dequeue(struct node **queue , int *front)
{
   return queue[(*front)++];
}

int isQueueEmpty(int *rear,int *front)
{
    return ((*rear)==(*front));
}

void getLevelOrder(struct node *root)
{
   int front , rear;
   if(root)
   {
       struct node **queue = createQueue(&front,&rear);
       struct node *temp ;
       enqueue(queue,&rear,root);
       while(!isQueueEmpty(&rear , &front))
       {
            temp = dequeue(queue ,&front);
            printf("%d\t" , temp->data);
            if(temp->left)
                enqueue(queue ,&rear , temp->left);
            if (temp ->right)
                enqueue(queue ,&rear , temp->right);
        }
    }            
}

void insert_into_bst()
{ 
	int ele;
	printf("enter the element u want to insert :  ");
	scanf("%d" , &ele);
       struct node* insert(struct node* node , int data)
       {
           if (node == NULL)
           return newNode(data);
           
           if (data < node->data)
              node->left = insert(node->left , data);
           else if  (data> node->data)
               node->right =insert(node->right ,data);
           return node;
       }
}

/*struct node* minValueNode(struct node* node)
{ 
       struct node* current =node;
       while(current && current->left!=NULL)
       current = current->left;
       return current;
}*/

void delete_from_bst(struct node* root,int data)
{
      
      printf("Enter the element you want to delete :  ");
      scanf("%d" , &data);
      struct node* minValueNode(struct node* node)
{ 
       struct node* current =node;
       while(current && current->left!=NULL)
       current = current->left;
       return current;
}
      struct node* deleteNode(struct node* root,int data)
      {
      
      
      
           if (root == NULL)
           return root;
           
           if(data<root->data)
           root->data = deleteNode(root->left , data);
           else if (data> root->data)
           root->right = deleteNode(root->right , data);
           else{
                  if(root->left == 	NULL){
                       struct node* temp =root->right;
                       free(root);
                       return temp; }
                  else if (root->right == NULL){
                       struct node* temp=root->left;
                       free(root);
                       return temp;
                       }
          struct node* temp =minValueNode(root->right);
          root->data = temp->data;
          root->right = deleteNode(root->right , temp->data);}
          return root;
      }
}    

void sum_of_leaf(struct node *root, int sum)
{
         
         if(!root)
         return;
         if (!root->left && !root->right)
         sum += root->data;
         sum_of_leaf(root->left,sum);
         sum_of_leaf(root->right,sum);
         }                

void sum_of_nonleaf(struct node *root , int sum)
{
         if(root == NULL || (root->left == NULL && root->right == NULL))
         return;
         if(root->left != NULL || root->right != NULL)
         {
              sum += root->data;
         }
         
         sum_of_nonleaf(root->right , sum);
}

int main()
{    
     struct node *root;
     int ele ,sum, option ; 
     printf("........ operations you can perform ...............\n1. insert into bst \n2. delete from bst \n3.print level order traersal of tree \n4. display sum of all leaf nodes \n5. display sum of all non leaf nodes \n6. exit \n");
     printf("enter the option which u want to perform :   ");
     scanf("%d" ,&option);
     
     do
     {
        if(option==1){
        insert_into_bst();
        }
        
        else if(option ==2){
        delete_from_bst(root,ele);
        }
        
        else if(option==3){
        getLevelOrder(root);
        }
        
        else if(option==4){
        sum_of_leaf(root,sum);
        }
        
        else if(option==5){
        sum_of_nonleaf(root,sum);
        }
        
        else if(option==6);
        
        else
        printf("please enter a valid choice...");
        
        }while(option!=6);
         
        
     return 0;
}   
 
 
