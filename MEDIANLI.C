/*given a single, sorted linked list, find the median of the linked list*/
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
void median();
void display();
int n;
void main()
{
	int r,i;
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
	median();
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
		//n++; we can find n after reading
		printf("%d-->",temp->num);
		temp=temp->next;
	}
	printf("NULL\n");
}
void median()
{
	node *t;
	int i;
	float m;

	t=head;
	if(head==NULL)
	{
	printf("no elements\n");
	return;
	}

	for(i=0;i<n/2-1;i++)
	{

	t=t->next;
	}
	if(n%2==0)

	m=(float)(t->next->num+t->num)/2;

	else

	m=(float)t->next->num;

	printf("median is %f",m);

}

