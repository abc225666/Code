#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <algorithm>*/

//#include <bits/stdc++.h>

//using namespace std;

typedef long long int lli;

typedef struct node
{
	struct node* next;
	int c;
}node;

void append(node** now,int in)
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

void node_swap(node** a, node** b)
{
	
	node *temp=*a;
	*a=*b;
	temp->next=(*b)->next;
	(*a)->next=temp;
	
}

int main()
{
	node *head=NULL,*tail=NULL;
	int in;
	printf("Enter a sequence of integer:\n");
	while(scanf("%d",&in)==1)
	{
		
		append(&tail,in);
		//printf("a this: %p  next: %p\n", tail,tail->next);
		if(head==NULL)
		{
			head=tail;
		}
		

	}

	//bubble
	node *ptr1=head;
	node **ptr2=&head;
	int flag=1;
	while(flag)
	{
		ptr2=&head;
		flag=0;
		if((*ptr2)==NULL)
		{
			break;
		}
		while( (*ptr2)->next != NULL)
		{

			if( (*ptr2)->c < (*ptr2)->next->c)
			{
				flag=1;
				node_swap(ptr2,&((*ptr2)->next));

			}
			
			ptr2=&((*ptr2)->next);
		}
		
	}

	printf("Output: ");
	
	node *ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->c);
		ptr=ptr->next;
	}
	
	return 0;
}
