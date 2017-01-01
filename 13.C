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
typedef struct node * NODE;

NODE insert(int item,NODE root)
{
	NODE cur,temp,prev;
	temp=(NODE)malloc(sizeof(struct node));
	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;
	if (root == NULL)
		return temp;
	prev=NULL;
	cur=root;
	while(cur!=NULL)
	{
		prev=cur;
		if(item==cur->info)
		{
			printf("duplicate items not allowed\n");
			free(temp);
			return root;
		}
		if(item<cur->info)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if(item<prev->info)
		prev->llink=temp;
	else
		prev->rlink=temp;
	return root;
}
void preorder(NODE root)
{
	if(root==NULL)
		return;
	printf("%d",root->info);
	preorder(root->llink);
	preorder(root->rlink);
}
void inorder(NODE root)
{
	if(root==NULL)
		return;
	inorder(root->llink);
	printf("%d",root->info);
	inorder(root->rlink);
}
void main()
{
	NODE root;
	int ch,item;
	root=NULL;
	for(;;)
	{
		clrscr();
		printf("1.insert 2.print traversal 3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the item\n");
			scanf("%d",&item);
			root=insert(item,root);
			break;
			case 2:if(root==NULL)
				printf("tree is empty\n");
			else
			{
				printf("PREORDER TRAVERSAL IS\n");
				preorder(root);
				printf("\n");
				printf("INORDER TRAVERSAL IS\n");
				inorder(root);

			}
			break;
			default:exit(0);
		}
		getch();
	}
}
