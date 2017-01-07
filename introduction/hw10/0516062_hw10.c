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
	int index=0;
	while(index<100)
	{
		if( (((st_data*)a)->name[index]) != (((st_data*)b)->name[index]) )
			return (((st_data*)a)->name[index]) - (((st_data*)b)->name[index]);
		index++;
	}
	return 1;
	

}

int cmp_conc(const void* a,const void * b)
{
	
	int index=0;
	while(index<100)
	{
		if( (((st_data*)a)->name[index]) != (((st_data*)b)->name[index]) )
			return (((st_data*)a)->name[index]) - (((st_data*)b)->name[index]);
		index++;
	}
	return  -(strtoll( ((st_data*)a)->conc , NULL,10) - strtoll( ((st_data*)b)->conc,NULL,10 ));
	
}

void read_data(char* in,int index)
{
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
	FILE* input=fopen("PM2.5.csv","r");
	FILE* output=fopen("outcomeSingle.csv","w");
	FILE* output_bin=fopen("outcomePair.csv","w");

	char in[500];
	char *split;
	fgets(in,sizeof(in),input);
	fputs(in,output);
	fputs(in,output_bin);


	int index=0;
	while(fgets(in,sizeof(in),input) !=NULL)
	{
		read_data(in,index);
		index++;
	}

	printf("output outcomeSingle.cvs...\n");
	qsort(data,index,sizeof(st_data),cmp);
	
	for(int t=0;t<index;t++)
	{
		//puts(data[t].name);
		fprintf(output,"%s , %s , %s , %s",data[t].name,data[t].date,data[t].conc,data[t].unit);
	}
	printf("finish!\n");
	
	printf("output outcomePair.csv...\n");
	qsort(data,index,sizeof(st_data),cmp_conc);

	for(int t=0;t<index;t++)
	{
		//puts(data[t].name);
		fprintf(output_bin,"%s , %s , %s , %s",data[t].name,data[t].date,data[t].conc,data[t].unit);
	}
	printf("finish!\n");

	int threshold,error=0;
	printf("Enter an integer n as threshold:");
	scanf("%d",&threshold);

	for(int t=0;t<index;t++)
	{
		if( strtoll(data[t].conc,NULL,10) >=threshold)
		{
			printf("%s , %s , %s , %s",data[t].name,data[t].date,data[t].conc,data[t].unit);
			error++;
		}
	}
	printf("%d warning data in total.\n",error);



	

	
	
	fclose(output_bin);
	fclose(input);
	fclose(output);
	
	

	return 0;
}
