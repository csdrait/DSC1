#include<stdio.h>
#include<conio.h>
#include<process.h>
#define quesize 5
void insertrear(int item,int *r,int q[])
{
	if(*r==quesize-1)
	{
		printf("que is full\n");
		return;
	}
	*r=*r+1;
	q[*r]=item;
}
void deletefront(int *f,int *r,int q[])
{       int item;
	if(*f>*r)
	{
		printf("Q is empty\n");
		return;
	}
	item=q[*f];
	printf("deleted item is %d ",item);
	*f=*f+1;
	if(*f>*r)
	{
		*f=0;
		*r=-1;
	}
}
void display(int f,int r,int q[])
{       int i;
	if(f>r)
	{
		printf("q is empty\n");
		return;
	}
	printf("the contentsin the que are\n");
	for(i=f;i<=r;i++)
		printf("%d\n",q[i]);
}
void main()
{
	int f,ch,r,q[10],item;
	f=0;r=-1;
	for(;;)
	{
		clrscr();
		printf("1.insert 2.deletefront 3.display 4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the item to insert\n");
			scanf("%d",&item);
			insertrear(item,&r,q);
			break;
			case 2:deletefront(&f,&r,q);
			break;
			case 3:display(f,r,q);
			break;
			default:exit(0);
		}
		getch();
	}
}
