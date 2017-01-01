#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
struct node
{
 int info;
 struct node *link;
};
typedef struct node * NODE;
NODE insertrear(int item,NODE first)
{
 NODE temp,cur;
 temp=(NODE)malloc(sizeof(struct node));
 temp->info=item;
 temp->link=NULL;
 if(first==NULL)
 {
  first=temp;
  return first;
 }
 cur=first;
 while(cur->link!=NULL)
 {
  cur=cur->link;
 }
 cur->link=temp;
 return first;
}
NODE deletefront(NODE first)
{
 NODE temp;
 if(first==NULL)
 {
  printf("List is empty\n");
  return first;
 }
 temp=first;
 first=first->link;
 printf("The deleted element is %d",temp->info);
 free(temp);
 return first;
}
void display(NODE first)
{
 NODE cur;
 if(first==NULL)
 {
  printf("Nothing to display\n");
  return;
 }
 cur=first;
 while(cur!=NULL)
 {
  printf("%d",cur->info);
  cur=cur->link;
 }
}
void main()
{
 NODE first;
 int choice,item;
 clrscr();
 first=NULL;
 for(;;)
 {
  printf("1.Insertrear 2.Deletefront 3.Display 4.Exit\n");
  printf("Enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:printf("Enter element to insert\n");
	  scanf("%d",&item);
	  first=insertrear(item,first);
	  break;
   case 2:first=deletefront(first);
	  break;
   case 3:display(first);
	  break;
  default:exit(0);
  }
 }
 getch();
}