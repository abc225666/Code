/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>*/

#include <bits/stdc++.h>

#define mmax 10000005

using namespace std;

typedef long long int lli;

int sieve[mmax];

int main()
{

	ios::sync_with_stdio(false);
	vector<int>prime;
	memset(sieve,0,sizeof(sieve));
	for(int now_p=2;now_p<mmax;now_p++)
	{
		if(!sieve[now_p]) prime.push_back(now_p);
		for(int t=0;now_p*prime[t]<mmax;t++)
		{
			sieve[now_p*prime[t]]=1;
			if(now_p%prime[t]==0) break;
		}
	}

	for(int t=0;t<prime.size();t++)
	{
		cout<<prime[t]<<" ";
	}

	return 0;
}
