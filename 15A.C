#include<stdio.h>
#include<conio.h>
int binsearch(int key,int a[],int low, int high)
{
	int mid;
	if(low>high)
		return -1;
	mid=(low+high)/2;
	if(key==a[mid])
		return (mid+1);
	if(key<a[mid])
		return binsearch(key,a,low,mid-1);
	return binsearch(key,a,mid+1,high);
}
void main()
{
	int arr[10],k,n,pos,i;
	clrscr();
	printf("enter the number of elements to be innserted\n");
	scanf("%d",&n);
	printf("enter the elelments in the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the key element to search");
	scanf("%d",&k);
	pos=binsearch(k,arr,0,n-1);
	if (pos==-1)
		printf("unsucccessful search");
	else
		printf("number found in position in%d",pos);
	getch();
}

