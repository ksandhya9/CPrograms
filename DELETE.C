/*given a single(not sorted) linked list, and a value, delete the value from the linked list. the value may exist or may not exist in the list*/
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
void deleten(int d);
void display();
void main()
{
	int n,r,i,d;
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
	printf("elements\n");
	display();
	printf("enter the number you want to delete\n");
	scanf("%d",&d);
	deleten(d);

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
	while(temp->next!=NULL)
	{
		printf("%d-->",temp->num);
		temp=temp->next;
	}
	printf("%d\n",temp->num);
}
void deleten(int d)
{
	node *t,*prev;

	t=head;
	while(t->num!=d&&t!=NULL)
	{
	prev=t;
	t=t->next;
	}
	if(t==head)
	{
	head=t->next;
	free(t);
	return;
	}
	if(t==NULL)
	{
	printf("%d does not exist\n",d);
	 return;
	 }

	 prev->next=t->next;
	 free(t);

}

