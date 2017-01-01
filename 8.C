#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
typedef struct node *NODE;
NODE insertrear(int item,NODE first)
{
	NODE temp,cur;
	temp=(NODE)malloc(sizeof(struct node));
	temp->info=item;
	temp->link=NULL;
	if(first==NULL)
		return temp;
	cur=first;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;
	return first;
}
NODE merge(NODE a,NODE b)
{
	NODE k,c,first;
	k=(NODE)malloc(sizeof(struct node));
	c=k;
	while(a!=NULL && b!=NULL)
	{
		if(a->info<b->info)
		{
			k->link=a;
			a=a->link;
			k=k->link;
		}
		else
		{
			k->link=b;
			b=b->link;
			k=k->link;
		}
	}
	if(b!=NULL)
		k->link=b;
	else
		k->link=a;
	first=c->link;
	free(c);
	return first;
}
NODE reverse(NODE first)
{       NODE temp,cur;
	temp=NULL;
	while(first!=NULL)
	{
		cur=first;
		first=first->link;
		cur->link=temp;
		temp=cur;
	}
	return temp;
}
void display(NODE first)
{
	NODE cur;
	if(first==NULL)
	{
		printf("list is empty\n");
		return ;
	}
	cur=first;
	while(cur!=NULL)
	{
		printf("%2d",cur->info);
		cur=cur->link;
	}
}
void main()
{
	NODE first,second,third;
	int ch,item,m,n,i;
	for(;;)
	{
		clrscr();
		first=second=third=NULL;
		printf("1.merge 2.reverse 3.display 4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the number ofnodes to create first list\n");
			scanf("%d",&m);
			printf("enter the element in the list\n");
			for(i=1;i<=m;i++)
			{
				printf("enter the %d item for the first node\n",i);
				scanf("%d",&item);
				first=insertrear(item,first);
			}
			printf("\n the first sorted list is\n");
			display(first);
			printf("enter the number of nodes tp create the second list\n");

			scanf("%d",&n);
			printf("enter the elements in the lsit\n");
			for(i=1;i<=n;i++)
			{
				printf("enter the %d item to create the second list\n",i);
				scanf("%d",&item);
				second=insertrear(item,second);
			}
			printf("\n the second sorted list is\n");
			display(second);
			third=merge(first,second);
			printf("the third sorted list is\n");
			display(third);
			break;
			case 2:printf("enter the number of nodes tocreate the list\n");
			scanf("%d",&n);
			printf("Enter the element in the list\n");
			for(i=1;i<=n;i++)
			{
				printf("enter the %d item for the list ",i);
				scanf("%d",&item);
				first=insertrear(item,first);
			}
			printf("\n the list are\n");
			display(first);
			first=reverse(first);
			printf("\nreverse list is\n");
			display(first);
			break;
			default:exit(0);
		}
		getch();
	}
}

