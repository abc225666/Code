#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <algorithm>
#include <math.h>

//#include <bits/stdc++.h>

//using namespace std;

typedef long long int lli;

int times=0;

struct matrix
{
	lli a,b,c,d;
};

matrix mul(matrix m1,matrix m2)
{
	matrix temp;



	temp.a=m1.a * m2.a + m1.b * m2.c;
	temp.b=m1.a * m2.b + m1.b * m2.d;
	temp.c=m1.c * m2.a + m1.d * m2.c;
	temp.d=m1.c * m2.b + m1.d * m2.d;
	return temp;
}

matrix pow(matrix m,int n)
{
	matrix output;

	if(n==0)
	{
		output.a=1;
		output.b=0;
		output.c=0;
		output.d=1;
	}
	else if(n==1)
	{
		return m;
	}
	else
	{

		if(n%2==1)
		{
			output=mul(pow(m,1),pow(m,n-1));
		}
		else if(n %2==0)
		{
			
			output=mul(pow(m,n/2),pow(m,n/2));
		}
	}

	return output;
}

int main()
{
	matrix basic;
	basic.a=0;
	basic.b=1;
	basic.c=1;
	basic.d=1;

	matrix result;
	int n;
	while(printf("Enter an integer>=0:") && scanf(" %d",&n)!=EOF )
	{
		if(n<0)
		{
			printf("input need to >= 0\n");
		}
		else
		{

			result=pow(basic,n);
		}
		//printf("%lld %lld\n%lld %lld\n",result.a,result.b,result.c,result.d);
		printf("F(%d)=%lld\n",n,result.b);
	}

	return 0;
}
