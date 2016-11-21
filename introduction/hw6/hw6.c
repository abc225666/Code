#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*#include <algorithm>*/

typedef long long int lli;



void reverse(char** mmap, int line)
{
	int t,t1;
	for(t=0;t<line;t++)
	{
		
		char temp;
		for(t1=0;t1< (strlen(mmap[t])-2)/2;t1++)
		{
			temp=mmap[t][t1];
			mmap[t][t1]=mmap[t][strlen(mmap[t])-2-t1];
			mmap[t][strlen(mmap[t])-2-t1]=temp;

			//printf("%d  ",mmap[t][t1]);
		}
		
		
		//fputs(mmap[t],stdout);
		//printf("%s",mmap[t]);

	}
}

void printfImage(char** mmap, int line)
{
	int t,t1;
	for(t=0;t<line;t++)
	{	
		
		//printf("%s",mmap[t]);
		fputs(mmap[t],stdout);
	}
}

int main(int argc, char*  argv[])
{
	FILE* fp;
	

	char* input[1000];
	char filename[1000];
	printf("Enter filename:");
	scanf("%s",filename);
	fp = fopen(filename,"r");
	if(fp==NULL) 
	{
		printf("No such File!");
		return 1;
	}
	input[0]=(char*)malloc(105*sizeof(char));
	int index=0;
	int a;
	while(fgets(input[index],105,fp)!=NULL)
	{
		//printf("%s\n",input[index]);
		
		index++;
		input[index]=(char*)malloc(105*sizeof(char));
	}

	

	//printfImage(input,index);
	reverse(input,index);
	//printf("\n");
	printfImage(input,index);


	fclose(fp);
	return 0;
}
