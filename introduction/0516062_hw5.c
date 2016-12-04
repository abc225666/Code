#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <algorithm>
#include <math.h>

//#include <bits/stdc++.h>

//using namespace std;

typedef long long int lli;

int times=0;

typedef struct matrix
{
	lli a,b,c,d;
} matrixc ;

struct matrix mul(struct matrix m1,struct matrix m2)
{
	struct matrix temp;



	temp.a=m1.a * m2.a + m1.b * m2.c;
	temp.b=m1.a * m2.b + m1.b * m2.d;
	temp.c=m1.c * m2.a + m1.d * m2.c;
	temp.d=m1.c * m2.b + m1.d * m2.d;
	return temp;
}

struct matrix poww(matrixc m,int n)
{
	matrixc output;

	
	output.a=1;
	output.b=0;
	output.c=0;
	output.d=1;

	/*else if(n==1)
	{
		return m;
	}
	else
	{

		if(n%2==1)
		{
			output=mul(poww(m,1),poww(m,n-1));
		}
		else if(n %2==0)
		{
			
			output=mul(poww(m,n/2),poww(m,n/2));
		}
	}*/
	

	//////////////////////////////
	// ex. 7 = 111 (4 2 1) 
	// n^1 * n^2 * n^4 = n^7
	//
	// ex. 10 = 1010
	// n^2 * n^8 =n^10
	// 
	// if last bit is 1 means we need this component
	// else ^2


	while(n)
	{
		if(n & 1)
		{
			output=mul(output,m);

		}
		m=mul(m,m);
		n>>=1;
	}
	


	return output;
}

int F(int n)
{
	struct matrix basic;
	basic.a=0;
	basic.b=1;
	basic.c=1;
	basic.d=1;
	matrix result;
	if(n<0)
	{
		printf("input need to >= 0\n");
	}
	else
	{

		result=poww(basic,n);
	}
		//printf("%lld %lld\n%lld %lld\n",result.a,result.b,result.c,result.d);
	return result.b;
	//printf("F(%d)=%lld\n",n,result.b);
}

int main()
{
	

	
	int n;
	while(printf("Enter an integer>=0:") && scanf(" %d",&n)!=EOF )
	{
		int result=F(n);
		printf("F(%d)=%d\n",n,result);
	}

	return 0;
}
