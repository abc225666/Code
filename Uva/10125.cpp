/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

//a+b=d-c

struct number
{
	int sum;
	int a;
	int b;
};


int num_set[1005];
number sum_set[1000005];


int int_cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int number_cmp(const void *a,const void *b)
{
	number *i,*j;
	i=(number*)a,j=(number*)b;
	return i->sum - j->sum;
}

int binsearch(int target,int a,int b,int n)
{
	int l,r,m;
	l=0,r=n;
	while(l<=r)
	{
		m=(l+r)/2;
		if(target>sum_set[m].sum) //in right
		{
			l=m+1;
		}
		else if (target<sum_set[m].sum)
		{
			r=m-1;
		}
		else //equal
		{
			bool flag=false;

			for(int t=m;t<=r;t++)
			{
				if(sum_set[t].sum!=target) break;
				if(a!=sum_set[t].a && b!=sum_set[t].a 
					&& a!=sum_set[t].b && b!=sum_set[t].b)
					return 1;
			}
			for(int t=m;t>=l;t--)
			{
				if(sum_set[t].sum!=target) break;
				if(a!=sum_set[t].a && b!=sum_set[t].a 
					&& a!=sum_set[t].b && b!=sum_set[t].b)
					return 1;
			}
			return 0;
		}

	}
	return 0;
}

int main()
{
	int n;
	while(scanf(" %d",&n)&&n)
	{

		for(int t=0;t<n;t++)
		{
			scanf(" %d",&num_set[t]);
		}
		int sum_index=0;
		qsort(num_set,n,sizeof(int),int_cmp);



		
		


		for(int t=0;t<n;t++)
		{
			for(int t1=t+1;t1<n;t1++)
			{
				sum_set[sum_index].sum=num_set[t]+num_set[t1];
				sum_set[sum_index].a=num_set[t];
				sum_set[sum_index].b=num_set[t1];
				sum_index++;
			}
		}
		qsort(sum_set,sum_index,sizeof(number),number_cmp);

		

		int mmax=-536870913*2;
		bool flag=false;

		for(int t=n-1;t>=0;t--) //biggest to smallest
		{
			if(flag) break;
			for(int t1=0;t1<n;t1++)
			{
				if (flag) break;
				if(t!=t1)
				{
					
					if(binsearch(num_set[t]-num_set[t1],num_set[t],num_set[t1],sum_index-1))
					{

						mmax=num_set[t];
						flag=true;
					}
				}
			}
		}
		if(flag)
		{
			printf("%d\n",mmax);
		}
		else
		{
			printf("no solution\n");
		}
	}


	return 0;
}
