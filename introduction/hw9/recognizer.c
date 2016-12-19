#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "recognizer.h"
//#include <algorithm>*/

//#include <bits/stdc++.h>

//using namespace std;

typedef long long int lli;

void rec_x3(char * input, int index)
{
	if(index==strlen(input))
	{
		printf("Accepted\n\n");
		return;
	}
	if(input[index]=='0')
	{
		rec_x3_1(input,index+1);
	}
	else
	{
		rec_x3(input,index+1);
	}
}
void rec_x3_1(char* input, int index)
{
	if(index==strlen(input))
	{
		printf("Rejected\n\n");
		return;
	}
	if(input[index]=='0')
	{
		rec_x3_2(input,index+1);
	}
	else
	{
		rec_x3_1(input,index+1);
	}

}
void rec_x3_2(char* input, int index)
{
	if(index==strlen(input))
	{
		printf("Rejected\n\n");
		return;
	}
	if(input[index]=='0')
	{
		rec_x3(input,index+1);
	}
	else
	{
		rec_x3_2(input,index+1);
	}
}
