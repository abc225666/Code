#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <algorithm>
#include <math.h>
#include <time.h>

//#include <bits/stdc++.h>

//using namespace std;

typedef long long int lli;

char** mmap;

int main()
{
	int n,m;
	int t,t1;
	srand(time(NULL));

	while(scanf(" %d %d",&n,&m)!=EOF)
	{
		if(n<=0 || m<=0)
			printf("i and j need to be > 0\n");
		else
		{
			//malloc
			mmap=(char**)malloc(n * sizeof(char*));
			for(t=0;t<n;t++)
			{
				mmap[t]=(char*)malloc(m * sizeof(char));
			}
			//end malloc

			//init map
			for(t=0;t<n;t++)
			{
				for(t1=0;t1<m;t1++)
				{
					mmap[t][t1]='.';
				}
			}

			int x=0,y=0;
			char output='B';
			mmap[0][0]='A';
			while(1)
			{
				//you can't go
				if(
					(x-1<0 || mmap[x-1][y]!='.') &&//left
					(x+1>n-1 || mmap[x+1][y]!='.') &&//right
					(y-1<0 || mmap[x][y-1]!='.') &&//up
					(y+1>m-1 || mmap[x][y+1]!='.') //down
					) break;
				if(output-1=='Z') break;
				//0 left, 1 right, 2 up, 3 down
				switch(rand()%4)
				{
					case 0:
						if(x-1<0 || mmap[x-1][y]!='.')//can't go
						{
							break;
						}
						x--;
						mmap[x][y]=output++;
						break;
					case 1:
						if(x+1>n-1 || mmap[x+1][y]!='.')//can't go
						{
							break;
						}
						x++;
						mmap[x][y]=output++;
						break;
					case 2:
						if(y-1<0 || mmap[x][y-1]!='.')//can't go
						{
							break;
						}
						y--;
						mmap[x][y]=output++;
						break;
					case 3:
						if(y+1>m-1 || mmap[x][y+1]!='.')//can't go
						{
							break;
						}
						y++;
						mmap[x][y]=output++;
						break;
				}
			}

			for(t=0;t<n;t++)
			{
				for(t1=0;t1<m;t1++)
				{
					printf("%c",mmap[t][t1]);
				}
				printf("\n");
			}
			
			//free
			for(t=0;t<n;t++)
			{
				free(mmap[t]);
			}
			free(mmap);
			//end free

		}
	}
	return 0;
}
