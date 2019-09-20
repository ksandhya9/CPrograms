/*given a single linked list, write a program to reverse the single linked list. for example 1->2->3 should be converted to 3->2->1. please write this program using without recursion*/
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
void display();
void reverse();
void main()
{
	int n,r,i;
	clrscr();
	head=NULL;
	printf("how many umber of elements you want to enter?\n");
	scanf("%d",&n);
	printf("enter %d number of elements\n",n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&r);
	insertlast(r);
	}
	printf("elements before reversing\n");
	display();
	reverse();
	printf("elements after reversing\n");
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
	while(temp->next!=NULL)
	{
		printf("%d-->",temp->num);
		temp=temp->next;
	}
	printf("%d\n",temp->num);
}
void reverse()
{
	node *p,*q,*r;
	p=head;
	q=p->next;
	p->next=NULL;
	r=q->next;
	while(r)
	{
	q->next=p;

	p=q;
	q=r;
	r=r->next;
	}
	q->next=p;
	head=q;

}
