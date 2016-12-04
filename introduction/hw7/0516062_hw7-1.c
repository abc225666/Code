#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*#include <algorithm>

#include <bits/stdc++.h>

using namespace std;*/

typedef long long int lli;

typedef struct node 
{	
	char c;
	struct node* next;
	

}node;

void append(node** now,char in)
{
	node* n=(node*)malloc(sizeof(node*));
	//printf("now=%p\n",*now);
	n->next=NULL;
	n->c=in;
	
	if(*now==NULL)
	{
		
		*now=n;
		
	}
	else
	{
		(*now)->next=n;
		*now=n;		
	}
	
}

node* reverse(node* head)
{
	node *newhead=head;
	node *tmp=NULL;

	while( newhead->next!=NULL)
	{
		
		head=newhead->next;
		newhead->next=tmp;
		tmp=newhead;

		newhead=head;
	}
	newhead->next=tmp;

	return newhead;



}

int main()
{
	node* head=NULL;
	node* tail=NULL;
	char in;
	while(1)
	{
		head=NULL;
		tail=NULL;
		printf("enter a string:");
		while(scanf("%c",&in)!=EOF && in!='\n')
		{

			append(&tail,in);
		//printf("a this: %p  next: %p\n", tail,tail->next);
			if(head==NULL)
			{
				head=tail;
			}


		}
		node* ptr=head;


		node* rptr=reverse(head);
		printf("string reversal:");
		while(rptr!=NULL)
		{
		//printf("this: %p  next: %p c: %c\n", rptr,rptr->next,rptr->c);
			printf("%c",rptr->c);
			rptr=rptr->next;

		}
		printf("\n\n");
	}

	return 0;
}
