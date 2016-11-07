#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int f(int  n)
{
	int t;
	int output=1;
	for(t=2;t<=n;t++)
	{
		output*=t;
	}
	return output;
}
int c(int n,int r)
{
	return f(n)/(f(r)*f(n-r));
}

int k(int n,int r)
{
	return c(n+r-1,r);
}


int main()
{
	int n,r;
	while(printf("Enter integer n and r: ")&&scanf("%d %d",&n,&r)!=EOF)
		printf("k(n,r)=%d\n\n\n",k(n,r));
	return 0;
}

