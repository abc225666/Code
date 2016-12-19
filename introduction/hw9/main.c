#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "recognizer.h"
#include "generator.h"
//#include <algorithm>*/

//#include <bits/stdc++.h>

//using namespace std;

typedef long long int lli;

void c1()
{
	char input[20000];
	getchar();
	printf("Enter a binary string:");
	fgets(input,sizeof(input),stdin);
	rec_x3(input,0);
}

void c2()
{
	int n;
	printf("Enter the length of binary string:");
	scanf("%d",&n);
	int total;
	total=gen_x3(n,0);

	printf("\n%d binary strings in total\n\n",total);
}

int main()
{
	char c;
	while(printf("Enter your choice: (1) Recognizer (2) Generator :") && scanf(" %c",&c)!=EOF)
	{
		switch(c)
		{
			case '1':
			c1();
			break;
			case '2':
			c2();
			break;
			default :
			printf("please input only 1 and 2\n");
		}
	}

	

	

	return 0;
}
