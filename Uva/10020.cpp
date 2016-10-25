/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

struct length
{
	int left,right;	
};

length freg[100005];

int cmp(const void* a,const void* b)
{
	length *i=(length*)a, *j=(length*)b;
	if(i->left!=j->left) return i->left - j->left;
	else return i->right - j->right;
}

int main()
{
	int n;
	while(scanf(" %d",&n)!=EOF)
	{
		while(n--)
		{
			int m;
			int freg_index=0;
			scanf(" %d",&m);
			int in_a,in_b;
			while(scanf(" %d %d",&in_a,&in_b) && (in_a || in_b) )
			{
				freg[freg_index].left=in_a;
				freg[freg_index].right=in_b;
				freg_index++;
			}
			qsort(freg,freg_index,sizeof(length),cmp);
			

			bool flag=true;

			length freg_ans[100005];
			int cur_right=0;
			int ans_index=0;
			int left_p=0;
			
			int temp_right;
			int temp_index;
			while(cur_right<m)
			{	
				temp_right=cur_right;
				for(int t=left_p;freg[t].left<=temp_right && t<freg_index;t++)
				{

					if(freg[t].right>cur_right)
					{
						cur_right=freg[t].right;
						temp_index=t;

					}
				}
				if(temp_right==cur_right) //not find
				{
					flag=false;
					break;
				}
				freg_ans[ans_index].left=freg[temp_index].left;
				freg_ans[ans_index].right=freg[temp_index].right;
				ans_index++;
				left_p=temp_index+1;
				
			}

			if(flag)
			{
				printf("%d\n",ans_index);
				for(int t=0;t<ans_index;t++)
				{
					printf("%d %d\n",freg_ans[t].left,freg_ans[t].right);
				}
			}
			else
			{
				printf("0\n");
			}
			if(n!=0)
			{
				printf("\n");
			}

			




		}
	}
	return 0;
}
