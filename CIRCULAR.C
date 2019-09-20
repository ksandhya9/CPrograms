/*given a single, sorted linked list convert that into a single, sorted, circular linked list. for example 1->2->3->NULL should be 1->2->3->1*/
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
void circular();
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

	printf(" after converting into circular linked list\n");
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
	temp->next=head;
}
void circular()
{
	node *current=(node *)malloc(sizeof(node));
	printf("%d-->",head->num);
	for(current=head->next;current!=head;current=current->next)
	printf("%d-->",current->num);
	printf("%d",current->num)
}
