/*given a double linked list with head and tail pointers, find the middle element of the linked list*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define NULL 0

struct llist
{
	int num;
	struct llist *head,*tail;
};
typedef struct llist node;
node *first;
void insertlast(int x);
void middle();
void display();
int n;
void main()
{
	int r,i;
	clrscr();
	first=NULL;
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
	middle();
	getch();
}
void insertlast(int x)
{
	node *t1,*t2;
	t1=(node *)malloc(sizeof(node));
	t1->num=x;
	if(first==NULL)
	{
	t1->head=NULL;
	first=t1;
	first->tail=NULL;
	}
	else
	{
	for(t2=first;t2->head;t2=t2->head){}
	t1->tail=t2;
	t2->head=t1;
	t1->head=NULL;
	}
}
void display()
{
	node *temp=(node *)malloc(sizeof(node));
	temp=first;
	while(temp!=NULL)
	{
		//n++; we can find n after reading
		printf("%d-->",temp->num);
		temp=temp->head;
	}
	printf("NULL\n");
}
void middle()
{

	node *f,*t;
	f=first;
	t=first;
	while(t->head!=NULL)
	t=t->head;
	for(;f!=t&&f->head!=t;f=f->head,t=t->tail) {}
	if(f==t)
	printf("middle number is %d",t->num);
	else
	printf("middle elements are %d,%d",f->num,t->num);




}

