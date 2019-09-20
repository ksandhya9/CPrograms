
/*given a number as input, create a single linked list for the number. example: 1234 as input you shoudl create a linked list which is in memory like 1->2->3->4*/
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
void insertfirst(int x);
void display(node *head);
void main()
{
	int n,r;

	head=(node *)malloc(sizeof(node));
	head->next=NULL;
	printf("enter a number\n");
	scanf("%d",&n);
	while(n>0)
	{
		r=n%10;
		insertfirst(r);
		n=n/10;
	       //	printf("%d%d",n,r);
	}
	display(head);
	getch();
}
void insertfirst(int x)
{
	node *temp;
      /*	if(head==NULL)
	{

		head->num=x;
		head->next=NULL;
	}
	else
	{*/
		temp=(node *)malloc(sizeof(node));
		temp->num=x;
		temp->next=head;

		head=temp;

       //	}
}
void display(node *head)
{
	node *temp=(node *)malloc(sizeof(node));
	temp=head;
	while(temp->next!=NULL)
	{
		printf("%d-->",temp->num);
		temp=temp->next;
	}
//	printf("%d",temp->num);
}