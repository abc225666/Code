/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

char mmap[105][105];

int main()
{
	int m,n;
	int count=1;
	while(scanf(" %d %d",&m,&n) && m &&n)
	{
		getchar();
		for(int t=0;t<m;t++)
		{

			fgets(mmap[t],sizeof(mmap[t]),stdin);
		}

		if(count!=1) printf("\n");
		printf("Field #%d:\n",count++);
		
		for(int t=0;t<m;t++)
		{
			for(int t1=0;t1<n;t1++)
			{
				if(mmap[t][t1]=='*') printf("*");
				else
				{
					int temp=0;
					char c='a';
					if(t-1>=0 && mmap[t-1][t1]=='*') temp++;
					if(t+1<=m-1 && mmap[t+1][t1]=='*') temp++;
					if(t1-1>=0 && mmap[t][t1-1]=='*') temp++;
					if(t1+1<=n-1 && mmap[t][t1+1]=='*') temp++;
					if(t-1>=0 && t1-1>=0 && mmap[t-1][t1-1]=='*') temp++;
					if(t-1>=0 && t1+1<=n-1 && mmap[t-1][t1+1]=='*') temp++;
					if(t+1<=m-1 && t1-1>=0 && mmap[t+1][t1-1]=='*') temp++;
					if(t+1<=m-1 && t1+1<=n-1 && mmap[t+1][t1+1]=='*') temp++;

					printf("%c",temp+'0');
				}
			}
			printf("\n");
		}
	}
	return 0;
}
