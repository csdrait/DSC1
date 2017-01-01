#include<stdio.h>
#include<conio.h>
#define maxsize 10
int insert_heap(int item,int a[],int n)
{       int c,p;
	if(n==maxsize-1)
	{
		printf("heap is full\n");
		return n-1;
	}
	c=n;
	p=c/2;
	while(p!=0 && item>a[p])
	{
		a[c]=a[p];
		c=p;
		p=c/2;
	}
	a[c]=item;
	return n;
}
int delete_heap(int a[],int n)
{
	int item,c,p;
	if(n==0)
	{
		printf("heap is empty\n");
		return 0;
	}
	printf("item deleted is %d",a[1]);
	item=a[n];
	p=1;
	c=2;
	n=n-1;
	while(c<=n)
	{
		if(c+1<=n && a[c]<a[c+1])
			c=c+1;
		if(item<a[c])
		{
			a[p]=a[c];
			p=c;
			c=2*p;
		}
		else
			break;
	}
	a[p]=item;
	return(n);
}
void display(int n ,int a[])
{       int i;
	if(n==0)
	{
		printf("heap is empty\n");
		return;
	}
	printf("contents of the heap are\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\n",a[i]);
	}
}

void main()
{
	int a[100],n,choice,item;
	n=0;
	for(;;)
	{
		clrscr();
		printf("1.insert 2.delete 3. display 4.exit\n");
		printf("eneter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the item\n");
			scanf("%d",&item);
			n=insert_heap(item,a,n+1);
			break;
			case 2:n=delete_heap(a,n);
			break;
			case 3:display(n,a);
			break;
			case 4:exit(0);
		}
		getch();
	}
}
