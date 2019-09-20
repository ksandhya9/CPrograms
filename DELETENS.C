/*given a single linked list and value N, delete the last N nodes of the linked list. for example 1->2->3->4 and 2, output should be 1->2->NULL*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define NULL 0

struct llist
{
	int num;
	struct llist *next;
};
typedef struct llist node;
node *head;
void insertlast(int x);
void deletens(int d);
void display();
int n;
void main()
{
	int r,i,d;
	clrscr();
	head=NULL;
	printf("how many number of elements you want to enter?\n");
	scanf("%d",&n);
	printf("enter %d number of elements\n",n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&r);
	insertlast(r);
	}
	printf("elements before reversing\n");
	display();
	printf("enter the number you want to allow in the list\n");
	scanf("%d",&d);
	deletens(d);

	printf("elements after deleting\n");
	display();
	getch();
}
void insertlast(int x)
{
	node *t1,*t2;
	t1=(node *)malloc(sizeof(node));
	if(head==NULL)
	{
	t1->num=x;
	t1->next=NULL;
	head=t1;
	}
	else
	{
	for(t2=head;t2->next;t2=t2->next){}
	t2->next=t1;
	t1->num=x;
	t1->next=NULL;
	}
}
void display()
{
	node *temp=(node *)malloc(sizeof(node));
	temp=head;
	while(temp!=NULL)
	{
		printf("%d-->",temp->num);
		temp=temp->next;
	}
	printf("NULL\n");
}
void deletens(int d)
{
	node *t,*t2,*t3;
	int i;

	t=head;
	if(d>n)
	{
	printf("there are no %d elements\n",d);
	return;
	}
	for(i=0;i<d-1;i++)
	t=t->next;
	t2=t->next;
	t->next=NULL;
	while(t2!=NULL)
	{
	  t3=t2;
	  t2=t2->next;
	  free(t3);
	}

}

