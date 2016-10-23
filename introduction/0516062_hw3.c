#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>

//#include <bits/stdc++.h>

//using namespace std;

typedef long long int lli;


lli prime[100000000];
lli prime_time[100000000];


int main()
{
	lli n;
	lli t,t1;
	while(printf("Enter an unsigned integer >= 2:") && scanf("%lld",&n)!=EOF)
	{
		lli out_n=n;
		lli div_num=1;
		memset(prime_time,0,sizeof(prime_time));
		int prime_index=0;
		while(n%2==0)
		{
			prime[prime_index]=2;
			prime_time[prime_index]++;
			n/=2;

		}
		if(prime_time[prime_index]>0) 
		{
			div_num*=prime_time[prime_index]+1;
			prime_index++;

		}
		for(t=3;t<=sqrt(out_n)&&t<=n;t+=2)
		{
			while(n%t==0)
			{
				prime[prime_index]=t;
				prime_time[prime_index]++;
				n/=t;
			}
			if(prime_time[prime_index]>0)
			{
				div_num*=prime_time[prime_index]+1;
				prime_index++;
			}
		}
		if(n!=1)
		{
			prime[prime_index]=n;
			prime_time[prime_index]++;
			

			div_num*=prime_time[prime_index]+1;
			prime_index++;
		}

		printf("Prime factorization of %lld = ",out_n);
		for(t=0;t<prime_index;t++)
		{
			printf("%lld^%lld",prime[t],prime_time[t]);
			if(t<prime_index-1) printf("x");
		}

		printf("\n");
		printf("NumBer of divisors=%lld\n", div_num);

		// sum and product
		lli sum=1;
		lli pro=1;
		bool sum_over=false;
		bool pro_over=false;
		for(t=0;t<prime_index;t++)
		{
			lli temp=0;
			for(t1=0;t1<=prime_time[t];t1++)
			{
				temp+=(lli)pow(prime[t],t1);
			}
			if(   (temp>>63 & 1 ) || temp>(lli)pow(2,32)-1 )
			{
				sum_over=true;
				break;
			}
			sum*=temp;
			if((sum>>63 &1)|| sum>(lli)pow(2,32)-1)
			{
				sum_over=true;
				break;
			}
		}
		if(sum_over)
		{
			printf("Sum of divisors overflow!\n",sum);
		}
		else
		{
			printf("Sum of divisors = %lld\n",sum);
		}
		div_num--;
		if(div_num%2==0)
		{
			pro*=(lli)sqrt(out_n);

		}
		else
		{
			div_num++;
		}
		div_num/=2;

		for(t=1;t<=div_num;t++)
		{
			pro*=out_n;
			if(   (pro>>63 & 1 ) || pro>(lli)pow(2,32)-1 )
			{
				pro_over=true;
				break;
			}
		}
		if(pro_over)
		{
			printf("Product of divisors overflow!\n");
		}
		else
		{
			printf("Product of divisors = %lld\n",pro);
		}



	}
	return 0;
}
