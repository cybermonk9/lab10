#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *lchild;
struct node *rchild;
};
typedef struct node *nodepointer;
nodepointer getnode()
{
nodepointer x;
x=(nodepointer)malloc(sizeof(struct node));
return x;
}
nodepointer insert(int item, nodepointer root)
{
nodepointer temp,cur,prev;
temp=getnode();
temp->info=item;
temp->lchild=temp->rchild=NULL;
if(root==NULL)
{
root=temp;
return root;
}
else
{
prev=NULL;
cur=root;
while(cur!=NULL)
{
prev=cur;
if(temp->info < cur->info)
cur=cur->lchild;
else if(temp->info > cur->info)
cur=cur->rchild;
else
{
printf("Duplicate Node\n");
return root;
}
}
if(temp->info > prev->info)
prev->rchild=temp;
else
prev->lchild=temp;
return root;
}
}
void preorder(nodepointer root)
{
if(root!=NULL)
{
printf("%d\t",root->info);
preorder(root->lchild);
preorder(root->rchild);
}
}
void inorder(nodepointer root)
{
if(root!=NULL)
{
inorder(root->lchild);
printf("%d\t",root->info);
inorder(root->rchild);
}
}
void postorder(nodepointer root)
{
if(root!=NULL)
{
postorder(root->lchild);
postorder(root->rchild);
printf("%d\t",root->info);
}
}
void traversal(nodepointer root)
{
if(root==NULL)
{
printf("The tree is empty\n");
return;
}
printf("\nThe preorder traversal is\n");
preorder(root);
printf("\nThe inorder traversal is\n");
inorder(root);
printf("\nThe post order traversal is\n");
postorder(root);
}
void search(nodepointer root)
{
int key;
nodepointer cur;
printf("Enter the key element to be searched\n");
scanf("%d",&key);
if(root==NULL)
{
printf("The tree is empty\n");
return;
}
cur=root;
while(cur!=NULL)
{
if(key==cur->info)
{
printf("The key element %d is found in tree\n",key);
return;
}
if(key<cur->info)
cur=cur->lchild;
else
cur=cur->rchild;
}
printf("The key element %d is not found in the tree\n",key);
}


