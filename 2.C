#include<stdio.h>
#include<conio.h>
#include<process.h>
struct sparse
{
	int row;
	int col;
	int val;
};
typedef struct sparse MATRIX;
MATRIX a[50];
void main()
{
	int m,n,key,k,count,i,j,item;
	clrscr();
	printf("enter the number of rows and columns\n");
	scanf("%d %d",&m,&n);
	a[0].row=m;
	a[0].col=n;
	count=0;
	k=1;
	printf("enter the elemets in the matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&item);
			if(item!=0)
			{
				a[k].row=i;
				a[k].col=j;
				a[k].val=item;
				k+=1;
				count+=1;
			}
		}
	}
	a[0].val=count;
	printf("enter the key element to search\n");
	scanf("%d",&key);
	for(i=1;i<=a[0].val;i++)
	{
		if(key==a[i].val)
		{
			printf("item found in %d row in %d col ",a[i].row,a[i].col);
			getch();
			exit(0);
		}
	}
	printf("unsuccessful search\n");
	getch();

}