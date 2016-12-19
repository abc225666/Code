#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define kinds 4

typedef long long int lli;

typedef struct stack
{
	int top;
	int stk[10000];
}stack;

int d[kinds]={1,5,10,50};
stack dollar;


int int_cmp(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}

void facevalue()
{
	printf("\n");
	int t;

	for(t=0;t<kinds;t++)
	{
		printf("  $%d",d[t]);
	}
	printf("\n");
}

int cc(int n,int k)
{
	if(n<0 || k==0) 
	{
		
		return 0;
	}
	else if(n==0)
	{
		int output[kinds];
		memset(output,0,sizeof(output));
		int t;
		for(t=0;t<dollar.top;t++)
		{
			output[ dollar.stk[t] ]++;
		}
		for(t=0;t<kinds;t++)
		{
			printf("%4d",output[t]);
		}
		printf("\n");
		
		return 1;
	}	
	
	dollar.stk[dollar.top]=k-1;
	dollar.top++;

	int total=cc(n-d[k-1],k);
	dollar.top--;

	total+=cc(n,k-1);
	return total;

}


void ui(void)
{
	int n;
	printf("Enter amount of money: ");
	scanf("%d",&n);
	facevalue();
	printf("\nThere are %d ways to make change.\n",cc(n,kinds));
	dollar.top=0;
	int t,t1;
	
	
}

int main()
{
	qsort(d,kinds,sizeof(int),int_cmp);
	
	while(1)
	{
		dollar.top=0;
		//memset(dollar.stk,0,sizeof(dollar.stk));
		ui();

	}
	return 0;
}
