#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

#define vert 12
#define hori 18
/*[0, 11][0, 17]*/ 

char mmap[20][20];

void print_map()
{
	int t,t1;
	for(t=0;t<vert;t++)
	{
		for(t1=0;t1<hori;t1++)
		{
			printf("%c",mmap[t][t1]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int t,t1;
	srand(time(NULL));
	
	/* init */
	for(t=0;t<vert;t++)
	{
		for(t1=0;t1<hori;t1++)
		{
			mmap[t][t1]=' ';
		}
	}
	/* border */
	for(t=1;t<hori;t++)
	{
		mmap[0][t]='-';
		mmap[11][t]='-';
	}
	for(t=0;t<vert;t++)
	{
		mmap[t][0]='l';
		mmap[t][17]='l';
	}
	
	/* start point */
	mmap[0][1]='R';
	/* end point */
	mmap[vert-1][hori-2]=' ';
	
	int block=10;
	/* randon block */
	while(block)
	{
		int a=rand()%(vert-2)+1;
		int b=rand()%(hori-2)+1;
		if(mmap[a][b]==' ') mmap[a][b]='*',block--;
	}
	
	print_map();
	
	/* move */
	char in;
	int flag=1;
	int now_x=0,now_y=1;
	while(flag)
	{
		
		printf("Please enter your direction\n");
		in=getch();
		
		printf("%c\n",in);
		switch(in)
		{
			case 's':
			case 'S':
				if(mmap[vert-1][hori-2]=='R')
				{
					flag=0;
				}
				else
				{
					if(now_x+1<vert && mmap[now_x+1][now_y]==' ')
					{
						mmap[now_x][now_y]=' ';
						mmap[now_x+1][now_y]='R';
						now_x++;
					}
					else printf("\n===  You can't go there!!  ===");
				}
				break;
			case 'w':
			case 'W':
				if(now_x==0 && now_y==1) printf("\n===  Wrong direction!!  ===");
				else if(now_x-1>=0 && mmap[now_x-1][now_y]==' ')
				{
						mmap[now_x][now_y]=' ';
						mmap[now_x-1][now_y]='R';
						now_x--;
				}
				else printf("\n===  You can't go there!!  ===");
				break;
			case 'a':
			case 'A':
				if(now_y-1>=0 && mmap[now_x][now_y-1]==' ')
				{
						mmap[now_x][now_y]=' ';
						mmap[now_x][now_y-1]='R';
						now_y--;
				}
				else printf("\n===  You can't go there!!  ===");
				break;
			case 'd':
			case 'D':
				if(now_y+1<hori && mmap[now_x][now_y+1]==' ')
				{
						mmap[now_x][now_y]=' ';
						mmap[now_x][now_y+1]='R';
						now_y++;
				}
				else printf("\n===  You can't go there!!  ===");
				break;
			default:
				printf("\n===  Wrong Input, only w,a,s,d accepted  ===");
				break;
		}
		
		printf("\n");
		print_map();
		
		
		
		
		
	}
	printf("Your wins!!\n");
	
	return 0;
}

