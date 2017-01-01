#include<stdio.h>
#include<conio.h>
#define quesize 5
#include<process.h>
void insertrear(int item,int *count,int *r,int q[])
{
	if(*count==quesize)
	{
		printf("q is full\n");
		return;
	}
	*r=(*r+1)%quesize;
	q[*r]=item;
	*count+=1;
}
void deletefront(int *f,int *count,int q[])
{
	int item;
	if(*count==0)
	{
		printf("q is empty\n");
		return;
	}
	item=q[*f];
	printf("deleted item is %d",item);
	*f=(*f+1)%quesize;
	*count-=1;
}
void display(int count,int f,int q[])
{       int i;
	if(count==0)
	{
		printf("q is empty\n");
		return;
	}
	printf("the contents of the q are\n");
	for(i=0;i<count;i++)
	{
		printf("%d",q[f]);
		f=(f+1)%quesize;
	}
}
void main()
{
	int choice,r,f,count,item,q[50];
	count=0;r=-1;f=0;
	for(;;)
	{       clrscr();
		printf("1.insertrear 2.delete front 3.display 4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the item to insert\n");
			scanf("%d",&item);
			insertrear(item,&count,&r,q);
			break;
			case 2:deletefront(&f,&count,q);
			break;
			case 3:display(count,f,q);
			break;
			default:exit(0);
		}
		getch();
	}
}
