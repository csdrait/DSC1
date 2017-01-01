#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
struct node
{
int info;
struct node *llink;
struct node *rlink;
};
typedef struct node *Node;
Node insert(int item,Node root)
{
Node cur,temp,prev;
temp=(Node) malloc (sizeof(struct node));
temp->info=item;
temp->llink=temp->rlink=NULL;
if(root==NULL)
{
return temp;
}
cur=root;
prev=NULL;
while(cur!=NULL)
{
	prev=cur;
	if(item < cur->info)
	{
	cur=cur->llink;
	}
	else
	cur=cur->rlink;
}
if(item<prev->info)
	prev->llink=temp;
else
	prev->rlink=temp;
return root;
}
void preorder(Node root)
{
if(root!=NULL)
{
printf("%d\n",root->info);
preorder(root->llink);
preorder(root->rlink);
}
}
void inorder(Node root)
{
if(root!=NULL)
{
inorder(root->llink);
printf("%d\n",root->info);
inorder(root->rlink);
}
}
void postorder(Node root)
{
if(root!=NULL)
{
postorder(root->llink);
postorder(root->rlink);
printf("%d\n",root->info);
}
}
void main()
{
Node root;
int item,choice;
root=NULL;
clrscr();
for(;;)
{
printf("1.insert 2.preorder 3.inorder 4.postorder 5.exit\n");
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the item\n");
       scanf("%d",&item);
       root=insert(item,root);
       break;
case 2:if(root!=NULL)
       {
       preorder(root);
       }
       else
       {
       printf("tree empty\n");
       }
       break;
case 3:if(root!=NULL)
       {
       inorder(root);
       }
       else
       {
       printf("tree empty\n");
       }
       break;
case 4:if(root!=NULL)
       {
       postorder(root);
       }
       else
       {
       printf("tree empty\n");
       }
       break;
default:exit(0);
}
getch();
}
}
