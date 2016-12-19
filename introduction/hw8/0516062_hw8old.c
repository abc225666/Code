#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define kinds 4

typedef long long int lli;

typedef struct stack
{
	int top;
	int stk[10000][kinds];
}stack;

int d[kinds]={1,5,10,50};
stack dollar;


int int_cmp(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}

int cc(int n,int k)
{
	if(n<0 || k==0) return 0;

	

	if(n==0) 
	{
		
		dollar.top++;
		return 1;
	}

	{
		int t;
		int temp[kinds];
		for(t=0;t<kinds;t++)
		{
			if(t>=k-1)
				temp[t]=dollar.stk[dollar.top][t];
			else
				temp[t]=0;
		}
		
		if( (n-d[k-1]<=0||k==0) && n-d[k-2]>=0 && k>=2)
		{
			
			for(t=k-1;t<kinds;t++)
			{
				dollar.stk[dollar.top+1][t]=temp[t];
			}
			if(n>=0&&k-1!=0) dollar.stk[dollar.top+1][k-2]++;
		}
		
		if(n-d[k-1]>=0) dollar.stk[dollar.top][k-1]++;
		//if(k<=kinds && n>=d[k]) dollar.stk[dollar.top][k]++;
		
		return cc(n-d[k-1],k)+cc(n,k-1);
	}
}


void ui(void)
{
	int n;
	scanf("%d",&n);
	cc(n,kinds);

	int t,t1;
	for(t=0;t<dollar.top;t++)
	{
		for(t1=0;t1<kinds;t1++)
		{
			printf("%d ",dollar.stk[t][t1]);
		}
		printf("\n");
	}
	
}

int main()
{
	qsort(d,kinds,sizeof(int),int_cmp);
	dollar.top=0;
	memset(dollar.stk,0,sizeof(dollar.stk));
	ui();
	return 0;
}
