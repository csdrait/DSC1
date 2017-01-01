#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
struct node
{
	int cf;
	int px;
	struct node *link;
};
typedef struct node * NODE;
NODE insertrear(int cf,int px,NODE head)
{       NODE cur,temp;
	temp=(NODE)malloc(sizeof(struct node));
	temp->px=px;
	temp->cf=cf;
	temp->link=temp;
	cur=head->link;
	while(cur->link!=head)
	{
		cur=cur->link;
	}
	temp->link=cur->link;
	cur->link=temp;
	return head;

}
NODE readpoly(NODE head)
{
	int cf,px,i,n;
	printf("Enter the number of terms\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the coefficient and power of %d term\n",i);
		scanf("%d %d",&cf,&px);
		head=insertrear(cf,px,head);
	}
	return head;
}
int compare(int x,int y)
{
	 if(x<y)
		return -1;
	 else if(x==y)
		return 0;
	 else
		return 1;
}
NODE addpol(NODE h1,NODE h2,NODE h3)
{
	NODE p1,p2;
	int sumcf;
	p1=h1->link;
	p2=h2->link;
	while(p1!=h1 && p2!=h2)
	{
		switch(compare(p1->px,p2->px))
		{
			case 0:sumcf=p1->cf+p2->cf;
			if(sumcf!=0)
				h3=insertrear(sumcf,p1->px,h3);
			p1=p1->link;
			p2=p2->link;
			break;
			case 1:h3=insertrear(p1->cf,p1->px,h3);
			p1=p1->link;
			break;
			case -1:h3=insertrear(p2->cf,p2->px,h3);
			p2=p2->link;
			break;
		}
	}
	while(p1!=h1)
	{
		h3=insertrear(p1->cf,p1->px,h3);
		p1=p1->link;
	}
	while(p2!=h2)
	{
		h3=insertrear(p2->cf,p2->px,h3);
		p2=p2->link;
	}
	return h3;
}
void display(NODE head)
{        NODE cur;
	if(head->link==head)
	{
		printf("polynomial is empty");
		return;
	}
	cur=head->link;
	while(cur!=head)
	{
		if(cur->cf>0)
			printf("+");
		printf("%dx^%d",cur->cf,cur->px);
		cur=cur->link;
	}
}
void main()
{
	NODE h1,h2,h3;
	clrscr();
	h1=(NODE)malloc(sizeof(struct node));
	h2=(NODE)malloc(sizeof(struct node));
	h3=(NODE)malloc(sizeof(struct node));
	h1->link=h1;
	h2->link=h2;
	h3->link=h3;
	printf("Enter the first polynomial\n");
	h1=readpoly(h1);
	printf("Enter the second polynimail\n");
	h2=readpoly(h2);
	h3=addpol(h1,h2,h3);
	printf("first polynomial is\n");
	display(h1);
	printf("second polynomial is\n");
	display(h2);
	printf("added polynomial is\n");
	display(h3);
	getch();
}


