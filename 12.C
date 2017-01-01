#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node * NODE;
NODE insertfront(int item,NODE first)
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;
	if(first==NULL)
		return temp;
	temp->rlink=first;
	first->llink=temp;
	return temp;
}
NODE insertleft(int item,int key,NODE first)
{
	NODE temp,cur,prev;
	temp=(NODE)malloc(sizeof(struct node));
	temp->info=item;
	temp->rlink=NULL;
	temp->llink=NULL;
	if(first==NULL)
	{
		printf("list is empty\n");
		free(temp);
		return first;
	}
	if(key==first->info)
	{
		temp->rlink=first;
		first->llink=temp;
		return temp;
	}
	cur=first;
	while(cur!=NULL && key!=cur->info)
		cur=cur->rlink;
	if(cur==NULL)
	{
		printf("key not found\n");
		free(temp);
		return first;
	}
	prev=cur->llink;
	prev->rlink=temp;
	temp->llink=prev;
	temp->rlink=cur;
	cur->llink=temp;
	return first;
}
NODE deleteinfo(int key,NODE first)
{       NODE cur,prev,next;
	if(first==NULL)
	{
		printf("list is empty\n");
		return first;
	}
	if(key==first->info)
	{
		cur=first;
		first=first->rlink;
		printf("deleted item is %d  ",cur->info);
		free(cur);
		if(first!=NULL)
			first->llink=NULL;
		return first;
	}
	cur=first;
	while(cur!=NULL && key!=cur->info)
		cur=cur->rlink;
	if(cur==NULL)
	{
		printf("key not found to delete\n");
		return first;
	}
	prev=cur->llink;
	next=cur->rlink;
	printf("deleted item is %d ",cur->info);
	free(cur);
	prev->rlink=next;
	if(next!=NULL)
		next->llink=prev;
	return first;
}
void display(NODE first)
{       NODE cur;
	if (first==NULL)
	{
		printf("list is empty\n");
		return;
	}
	cur=first;
	while(cur!=NULL)
	{
		printf("%d\n",cur->info);
		cur=cur->rlink;
	}
}
void main()
{
	int item,key,ch;
	NODE first;
	first=NULL;
	for(;;)
	{
		clrscr();
		printf("1.insertfront 2.insertleft 3.deleteinfo 4 display 5.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the item to insert\n");
			scanf("%d",&item);
			first=insertfront(item,first);
			break;
			case 2:printf("enter the item toinsert in left\n");
			scanf("%d",&item);
			printf("enter the key element to search\n");
			scanf("%d",&key);
			first=insertleft(item,key,first);
			break;
			case 3:printf("enter the key element to delete\n");
			scanf("%d",&key);
			first=deleteinfo(key,first);
			break;
			case 4:display(first);
			break;
			default:exit(0);
		}
		getch();
	}
}

