#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

typedef unsigned long long int lli;

lli total_point;
int thread_num=16;

struct t_data
{
	int rank;
	lli rand_seed;
};

struct circle
{
	double x,y;
};

lli rand_a(lli randnum)
{
    return randnum+=(randnum<<16)+0x1db3d743;
}

int generate_and_check(int rank,lli* randnum)
{
	circle c;
	*randnum=rand_a(*randnum);
	
	c.x=(*randnum%20001ull);

	c.x=(c.x-10000)/10000;

	*randnum=rand_a(*randnum);
	
	c.y=((*randnum%20001ull));
	c.y=(c.y-10000)/10000;
	//printf("%lf %lf\n",c.x,c.y);
	
    if(sqrt(c.x*c.x+c.y*c.y)<=1)
	{
		return 1;
	}
	else return 0;
}

void* find_circle(void* input_data)
{
	t_data* data=(t_data*)input_data;
	int my_rank=data->rank;
	lli randnum=data->rand_seed;
	lli my_total_in_point=0;
	

	for(lli t=my_rank;t<total_point;t+=thread_num)
	{
		my_total_in_point+=generate_and_check(my_rank,&randnum);
		if(total_point-t<thread_num) break;
	}
	//printf("%d:%lld\n",my_rank,my_total_in_point);
	return (void *) my_total_in_point;

}

int main(int argc,char * argv[])
{
    srand(time(NULL));
	pthread_t* handles;
	t_data* thread_data;
	//scanf("%lld",&total_point);
	total_point=strtoll(argv[1],NULL,10);
	
	handles = (pthread_t*)malloc (thread_num*sizeof(pthread_t));
	thread_data=(t_data*)malloc(thread_num*sizeof(t_data));
	for(int t=0;t<thread_num;t++)
	{
		thread_data[t].rank=t;
		thread_data[t].rand_seed=(rand()<<31)+(rand()<<16)+(rand()&1);
		pthread_create(&handles[t],NULL,find_circle,&thread_data[t]);
	}

	lli total_in_point=0;
	void* every=0;

	for(int t=0;t<thread_num;t++)
	{
		pthread_join(handles[t],&every);
		//printf("%d:%lld!!\n",t,(lli)every);

		total_in_point+=(lli)every;
	}
	//printf("%llu\n",total_point );
	printf("%lf\n",(double)total_in_point/(double)total_point*4);

	return 0;

}
