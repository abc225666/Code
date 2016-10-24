#include <bits/stdc++.h>
#include <pthread.h>
#include <time.h>

using namespace std;

typedef long long int lli;

int thread_num=16;
lli total_point;

struct thread_data
{
	bool isinit=false;
	int MT_index=0;
	int MT[625];

	int rank;
};



void my_srand(int seed,thread_data* data)
{
    data->MT_index=0;
    data->isinit=true;
    data->MT[0]=seed;
    // init other element in sequence
    for(int t=1;t<624;t++)
    {
        int i=1812433253 * (data->MT[t - 1] ^ (data->MT[t - 1] >> 30)) + i; 
        data->MT[t]=i & 0xffffffff; //32 bits
    }
}

void generate(thread_data* data)
{
	for(int t=0;t<624;t++)
    {
        int y=(data->MT[t] & 0x80000000 ) + (data->MT[(t+1)%624] & 0x7fffffff);
        data->MT[t]=data->MT[(t+397)%624] ^(y>>1);
        if(y&1)
        {
            data->MT[t] ^=2567483615;
        }
        //printf("%d\n",MT[t]);
    }
}

int my_rand(thread_data* data)
{
    if(!data->isinit)
    {
        srand((int)time(NULL));
    }
    if(data->MT_index==0)
    {
        generate(data);
    }
    int y=data->MT[data->MT_index];
    y = y ^ (y >> 11);                 
    y = y ^ ((y << 7) & 2636928640);
    y = y ^ ((y << 15) & 4022730752);
    y = y ^ (y >> 18);

    data->MT_index=(data->MT_index+1) %624;
    return y;

}

void* find_circle(void* input_data)
{
	thread_data* data=(thread_data*)input_data;
	int my_rank=data->rank;
	lli my_total_in_point=0;
	double x,y;
	for(lli t=0;t<total_point;t+=thread_num)
	{
		x=my_rand(data)%200001-100000;
		y=my_rand(data)%200001-100000;

		x/=100000;
		y/=100000;

		if(sqrt(x*x+y*y)<=1)
		{
			my_total_in_point++;
		}
		//printf("%lf %lf %lf %d\n",x,y,y*y,sqrt(x*x+y*y)<=100000);
		if(total_point-t<thread_num) break;
	}

	return (void*)my_total_in_point;
}

int main(int argc,char* argv[])
{
	//int gg=time(NULL);
	srand(time(NULL));
	pthread_t* handle;
	thread_data* handle_data;
	total_point=strtoll(argv[1],NULL,10);
	//thread_num=strtoll(argv[2],NULL,10);
	//printf("%lld %d\n",total_point,thread_num);
	handle=(pthread_t*)malloc(thread_num*sizeof(pthread_t));
	handle_data=(thread_data*)malloc(thread_num*sizeof(thread_data));

	for(int t=0;t<thread_num;t++)
	{
		handle_data[t].rank=t;
		my_srand(rand(),&handle_data[t]);
		//pthread_create(&handle[t],NULL,find_circle,&thread_data[t]);
		pthread_create(&handle[t],NULL,find_circle,&handle_data[t]);
	}

	lli total_in_point=0;
	void* every;

	for(int t=0;t<thread_num;t++)
	{
		pthread_join(handle[t],&every);
		total_in_point+=(lli)every;

	}
	printf("%lf\n",(double)total_in_point/(double)total_point*4);

	//printf("%d\n",time(NULL)-gg);


	return 0;
}
