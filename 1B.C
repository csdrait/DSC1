#include<stdio.h>
#include<conio.h>
void sort(int n,int a[],int s[])
{
	int c[10],i,j;
	for(i=0;i<n;i++)
	{
		c[i]=0;
	}
	for(i=0;i<=n-2;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
				c[j]=c[j]+1;
			else
				c[i]=c[i]+1;
		}
	}
	for(i=0;i<n;i++)
		s[c[i]]=a[i];
	printf("the sorted element are\n");
	for(i=0;i<n;i++)
		printf("%d\n",s[i]);
}
void main()
{
	int num,arr[10],s1[10],i;
	clrscr();
	printf("Enter the number of elements\n");
	scanf("%d",&num);
	printf("Enter the elements in the array\n");
	for(i=0;i<num;i++)
		scanf("%d",&arr[i]);
	sort(num,arr,s1);
	getch();
}
