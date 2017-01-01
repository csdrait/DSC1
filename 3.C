#include<stdio.h>
#include<conio.h>
#include<process.h>
#define stacksize 50
void push(int item,int *top,int s[])
{
	if (*top==stacksize-1)
	{
		printf("stack overflow\n");
		return;
	}
	*top=*top+1;
	s[*top]=item;
}
int pop(int *top,int s[])
{
	int item;
	if(*top==-1)
		return -1;
	item=s[*top];
	*top=*top-1;
	return item;
}
void display(int top ,int s[])
{       int i;
	if(top==-1)
	{
		printf("stack is empty\n");
		return;
	}
	printf("the elements of the stack are\n");
	for(i=0;i<=top;i++)
		printf("%d\n",s[i]);
}
void main()
{
	int top,item,y,ch,s[stacksize];
	top=-1;
	for(;;)
	{
		clrscr();
		printf("1.insert 2.pop 3.display 4.exit\n");
		printf("eneter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the item to inser\n");
			scanf("%d",&item);
			push(item,&top,s);
			break;
			case 2:y=pop(&top,s);
			if(y==-1)
				printf("stack underflow\n");
			else
				printf("popped item is%d",y);
			break;
			case 3:display(top,s);
			break;
			default:exit(0);
		}
		getch();
	}
}