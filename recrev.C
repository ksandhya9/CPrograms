//Reversing a linked list using recursion
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct llist
{
	int num;
	struct llist *next;
};
typedef struct llist node;
void display(node * head)
{
while(head->next!=NULL)
{
printf("%d->",head->x);
head=head->next;
}
printf("%d \n",head->x);
}

void reverse(node ** head)
{
node * first;
node * rest;
if(head==NULL)
return;
first=*head;
rest=first->next;
if(rest==NULL)
return;
reverse(&rest);
first->next->next=first;
first->next=NULL;
*head=rest;
}

void main()

{

node * root=NULL;
node *p,*q,*n;
    int t,w,r,s;
    printf("Enter the number of elements");
    scanf("%d",&t);
    root=malloc(sizeof(node));
    scanf("%d",&r);
    root->x=r;
    root->next=NULL;
    q=root;
    w=0;
    while(w<t-1)
    {
	p=malloc( sizeof(node) );
	scanf("%d",&r);
	p->x=r;
	q->next=p;
	p->next=NULL;
	q=p;
	w++;
     }
printf("the list is :");

display(root);

reverse(&root);

printf("after reverse :");

display(root);
}