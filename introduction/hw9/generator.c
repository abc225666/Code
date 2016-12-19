
#include <stdio.h>
#include <stdlib.h>

#include "generator.h"

char output[1000000];

int gen_x3(int n, int index)
{
	if(index==n)
	{
		output[index]='\0';
		printf("%s ",output);
		return 1;
	}
	int sum=0;
	output[index]='0';
	sum+=gen_x3_1(n,index+1);
	output[index]='1';
	sum+=gen_x3(n,index+1);
	return sum;

}

int gen_x3_1(int n, int index)
{
	if(index==n)
	{
		return 0;
	}
	int sum=0;
	output[index]='0';
	sum+=gen_x3_2(n,index+1);
	output[index]='1';
	sum+=gen_x3_1(n,index+1);
	return sum;
}

int gen_x3_2(int n, int index)
{
	if(index==n)
	{
		return 0;
	}
	int sum=0;
	output[index]='0';
	sum+=gen_x3(n,index+1);
	output[index]='1';
	sum+=gen_x3_2(n,index+1);
	return sum;
}