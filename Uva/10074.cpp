/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int input[105][105];
int dp[105][105];


int main()
{
	int m,n;

	while(scanf(" %d %d",&m,&n)&& (n!=0&&m!=0))
	{
		int ans=0;
		memset(input,0,sizeof(input));
		memset(dp,0,sizeof(dp));
		for(int t=1;t<=m;t++)
		{
			for(int t1=1;t1<=n;t1++)
			{
				scanf(" %d",&input[t][t1]);
				input[t][t1]^=1;
				if(input[t][t1]==1)
				{
					dp[t][t1]=dp[t][t1-1]+1;
				}
				else
				{
					dp[t][t1]=0;
				}
			}
		}

		
		int min_length=200;
		int max_rect=0;
		for(int t=1;t<=m;t++)
		{
			for(int t1=1;t1<=n;t1++)
			{
				min_length=200;
				for(int t2=t;input[t2][t1]==1;t2--)
				{
					min_length=min(min_length,dp[t2][t1]);
					max_rect=max(max_rect,(t-t2+1)*min_length);
				}
			}
		}
		printf("%d\n",max_rect);

	}
	return 0;
}
