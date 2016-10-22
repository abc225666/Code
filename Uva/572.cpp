#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

char inputmap[105][105];
int nummap[105][105];

int m,n;

int dfs(int x,int y,int c)
{
    nummap[x][y]=c;
    if(x>0 && nummap[x-1][y]==0) dfs(x-1,y,c);
    if(x<m-1 && nummap[x+1][y]==0) dfs(x+1,y,c);
    if(y>0 && nummap[x][y-1]==0) dfs(x,y-1,c);
    if(y<n-1 && nummap[x][y+1]==0) dfs(x,y+1,c);
    if(x>0 && y>0 && nummap[x-1][y-1]==0) dfs(x-1,y-1,c);
    if(x>0 && y<n-1 && nummap[x-1][y+1]==0) dfs(x-1,y+1,c);
    if(x<m-1 && y>0 && nummap[x+1][y-1]==0) dfs(x+1,y-1,c);
    if(x<m-1 && y<n-1 && nummap[x+1][y+1]==0) dfs(x+1,y+1,c);
}


int main()
{
    int in;
    while(scanf("%d %d",&m,&n)&&getchar()&& m!=0)
    {

        for(int t=0;t<m;t++)
        {
            fgets(inputmap[t],sizeof(inputmap[t]),stdin);

        }
        for(int t=0;t<m;t++)
        {
            for(int t1=0;t1<n;t1++)
            {
                if(inputmap[t][t1]=='*')
                {
                    nummap[t][t1]=-1;
                }
                if(inputmap[t][t1]=='@')
                {
                    nummap[t][t1]=0;
                }
            }

        }

        int index=0;
        for(int t=0;t<m;t++)
        {
            for(int t1=0;t1<n;t1++)
            {
                if(nummap[t][t1]==0)
                {
                    index++;
                    dfs(t,t1,index);

                }
            }
        }
        printf("%d\n",index);





    }

    return 0;
}