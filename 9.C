#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>
struct node
{
	int info;
	struct node *link;
};
typedef struct node * NODE;
NODE insertfront(int item,NODE first)
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("out of memory\n");
		getch();
		exit(0);
	}
	temp->info=item;
	temp->link=first;
	first=temp;
	return first;
}
NODE deletefront(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("list is empty\n");
		return first;
	}
	temp=first;
	printf("the deleted item is %d ",temp->info);
	first=first->link;
	free(temp);
	return first;
}
void display(NODE first)
{
	NODE cur;
	if(first==NULL)
	{
		printf("list is empty\n");
		return;
	}
	cur=first;
	while(cur!=NULL)
	{
		printf("%3d",cur->info);
		cur=cur->link;
	}
}
void main()
{
	int choice,item;
	NODE first;
	first=NULL;
	for(;;)
	{
		clrscr();
		printf("1.insert 2. delete 3.display 4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the item to insert\n");
			scanf("%d",&item);
			first=insertfront(item,first);
			break;
			case 2:first=deletefront(first);
			break;
			case 3:display(first);
			break;
			default:exit(0);
		}
		getch();
	}
}