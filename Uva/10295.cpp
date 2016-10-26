/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main()
{
	ios::sync_with_stdio(false);
	map<string,int> input;
	int m,n;
	string in;
	int inb;
	lli sum;
	
	while(cin>>m>>n)
	{
		if(cin.eof()) break;
		sum=0;
		for(int t=0;t<m;t++)
		{
			cin>>in>>inb;
			input[in]=inb;

			//cout<<in<<input[in];
		}

		for(int t=0;t<n;t++)
		{
			sum=0;
			while(cin>>in && in!=".")
			{
				if(input[in]>0) sum+=input[in];
			//printf("%lld\n",sum);	
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
