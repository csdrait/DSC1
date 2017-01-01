#include<stdio.h>
#include<conio.h>
#include<process.h>
int count;
void toh(int n,char source,char temp,char dest)
{
	if(n==0)
	{
		printf("There is no disc\n");
		getch();
		exit(0);
	}
	if(n==1)
	{
		printf("Move %d disc from %c to %c\n",n,source,dest);
		count+=1;
		return;
	}
	toh(n-1,source,dest,temp);
	printf("Move %d disc from %c to %c\n",n,source,dest);
	count+=1;
	toh(n-1,temp,source,dest);
}
void main()
{
	int n;
	clrscr();
	printf("enter the number of disc\n");
	scanf("%d",&n);
	toh(n,'A','B','C');
	printf("total number of disc moved is %d",count);
	getch();
}
