#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <algorithm>*/

//#include <bits/stdc++.h>

//using namespace std;

typedef long long int lli;

typedef struct st_data
{
	char name[100];
	char date[100];
	char conc[100];
	char unit[100];
} st_data;

st_data data[200000];

int cmp(const void* a,const void * b)
{
	// compare with name
	st_data *in_a=(st_data*)a;
	st_data *in_b=(st_data*)b;
	
	return strcmp(in_a->name,in_b->name);
}

int cmp_conc(const void* a,const void * b)
{
	// compare with name and concertration
	st_data *in_a=(st_data*)a;
	st_data *in_b=(st_data*)b;

	if(!strcmp( in_a->name, in_b->name))
	{
		return  -(strtoll( in_a->conc , NULL,10) - strtoll( in_b->conc,NULL,10 ));
	}
	return strcmp( in_a->name, in_b->name);
}

void read_data(char* in,int index)
{
	// split string with ,
	char *split;
	split=strtok(in,",");
	strcpy(data[index].name,split);
	
	split=strtok(NULL,",");
	strcpy(data[index].date,split);

	split=strtok(NULL,",");
	strcpy(data[index].conc,split);

	split=strtok(NULL,",");
	strcpy(data[index].unit,split);

}

int main()
{
	int t;

	// get file name
	char filename[300];
	printf("input the file name:");
	scanf("%s",filename);

	// open file ptr
	FILE* input=fopen(filename,"r");
	FILE* output=fopen("outcomeSingle.csv","w");
	FILE* output_bin=fopen("outcomePair.csv","w");

	// puts the first line into output
	char in[500];
	char *split;
	fgets(in,sizeof(in),input);
	fputs(in,output);
	fputs(in,output_bin);

	// get all datas
	int index=0;
	while(fgets(in,sizeof(in),input) !=NULL)
	{
		read_data(in,index);
		index++;
	}

	// generate PartI file
	printf("output outcomeSingle.cvs...\n");
	qsort(data,index,sizeof(st_data),cmp);
	
	for(t=0;t<index;t++)
	{
		fprintf(output,"%s , %s , %s , %s",data[t].name,data[t].date,data[t].conc,data[t].unit);
	}
	printf("finish!\n");
	
	// generate PartII file
	printf("output outcomePair.csv...\n");
	qsort(data,index,sizeof(st_data),cmp_conc);

	for(t=0;t<index;t++)
	{
		fprintf(output_bin,"%s , %s , %s , %s",data[t].name,data[t].date,data[t].conc,data[t].unit);
	}
	printf("finish!\n");

	// get a threshold and outout answer
	int threshold,error=0;
	printf("Enter an integer n as threshold:");
	scanf("%d",&threshold);

	for(t=0;t<index;t++)
	{
		if( strtoll(data[t].conc,NULL,10) >=threshold)
		{
			printf("%s , %s , %s , %s",data[t].name,data[t].date,data[t].conc,data[t].unit);
			error++;
		}
	}
	printf("%d warning data in total.\n",error);


	// close file ptr
	fclose(output_bin);
	fclose(input);
	fclose(output);
	
	

	return 0;
}
