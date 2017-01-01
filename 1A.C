#include<stdio.h>
#include<conio.h>
#include<process.h>
void insertion(int arr[],int num)
{
	int i,j,item;
	for(j=1;j<num;j++)
	{
		item=arr[j];
		i=j-1;
		while(i>=0 && item<arr[i])
		{
			arr[i+1]=arr[i];
			i=i-1;
		}
		arr[i+1]=item;
	}

	printf("sorted array is \n");
	for(i=0;i<num;i++)
		printf("%d\n",arr[i]);

}
void main()
{
	int n,a[10],i;
	clrscr();
	printf("enter the number of ellemnts\n");
	scanf("%d",&n);
	printf("enter the elements in the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	insertion(a,n);
	getch();
}
