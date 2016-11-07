#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	int t,t1;
	int i;
	for(i=2;i<=5;i++)
	{
		for(t=0;t<i;t++)
		{
			for(t1=0;t1<4-t;t1++)
			{
				printf(" ");
			}
			for(t1=0;t1<t*2+1;t1++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	for(t=0;t<3;t++)
	{
		for(t1=0;t1<2;t1++)
			printf(" ");
		for(t1=0;t1<5;t1++)
			printf("*");
		printf("\n");
	}
	

	return 0;
}

