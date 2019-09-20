/*given a single linked list, print the N element from the end of the linked list. example 1->2->3->4->5 and 2, output is 4*/
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
void displayk(int k);
int n;
void main()
{
	int r,i,k;
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

	printf("enter position of element from end\n");
	scanf("%d",&k);
	displayk(k);
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
		//n++;can find size of list;
		printf("%d-->",temp->num);
		temp=temp->next;
	}
	printf("%d\n",temp->num);
}
void displayk(int k)
{
int i;
node *temp;
temp=head;
if(n-k<0)
{
printf("no element\n");
return;
}
for(i=0;i<n-k;i++)
temp=temp->next;
printf("%d element from last %d",k,temp->num);
}


