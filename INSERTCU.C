/*given a single, sorted, circular linked list and a value, insert the value as a new node at the appropriate location (to keep the linked list sorted). example 1->2->4->1 and value 3 output shoudl be 1->2->3->4->1*/
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
void convert();
void circular();
void insertintocirc(int x);
void main()
{
	int n,r,i,o;
	clrscr();
	head=NULL;
	printf("how many umber of elements you want to enter?\n");
	scanf("%d",&n);
	printf("enter %d number of elements in ascending order\n",n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&r);
	insertlast(r);
	}
	printf("elements before reversing\n");
	convert();

	printf(" after converting into circular linked list\n");
	circular();
	printf("enter the number to be inserted into circular llist\n");
	scanf("%d",&o);
	insertintocirc(o);
	circular();
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
void convert()
{
	node *temp=(node *)malloc(sizeof(node));
	temp=head;
	while(temp->next!=NULL)
	{

		temp=temp->next;
	}
	temp->next=head;
}
void circular()
{
	node *current=(node *)malloc(sizeof(node));
	printf("%d-->",head->num);
	for(current=head->next;current!=head;current=current->next)
	printf("%d-->",current->num);
	printf("%d",current->num);
}

void insertintocirc(int x)
{
	node *p1,*p2,*p;
	p1=head;
	p=(node *)malloc(sizeof(node));
	p->num=x;
	if(x<head->num)
	{
	p2=head->next;
	while(p2==head)
	{
	p1=p2;
	p2=p2->next;
	}
	p1->next=p;
	p->next=p2;
	head=p;
	}
	for(p2=head->next;p2->num<x&&p2!=head;p2=p2->next)
	{
	p1=p2;
	}
	p1->next=p;
	p->next=p2;

}