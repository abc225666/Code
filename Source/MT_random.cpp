#include <bits/stdc++.h>
 
using namespace std;

bool isinit=false;
int MT_index=0;
int MT[625];


void srand(int seed)
{
    MT_index=0;
    isinit=true;
    MT[0]=seed;
    // init other element in sequence
    for(int t=1;t<624;t++)
    {
        int i=1812433253 * (MT[t - 1] ^ (MT[t - 1] >> 30)) + i; 
        MT[t]=i & 0xffffffff; //32 bits
    }
}

void generate()
{
    for(int t=0;t<624;t++)
    {
        int y=(MT[t] & 0x80000000 ) + (MT[(t+1)%624] & 0x7fffffff);
        MT[t]=MT[(t+397)%624] ^(y>>1);
        if(y&1)
        {
            MT[t] ^=2567483615;
        }
    }

}

int rand()
{
    if(!isinit)
    {
        srand((int)time(NULL));
    }
    if(MT_index==0)
    {
        generate();
    }
    int y=MT[MT_index];
    y = y ^ (y >> 11);                 
    y = y ^ ((y << 7) & 2636928640);
    y = y ^ ((y << 15) & 4022730752);
    y = y ^ (y >> 18);

    MT_index=(MT_index+1) %624;
    return y;

}

int main()
{
    //set rand seed
    srand((int)time(NULL));
    
    for(int t=0;t<10;t++)
    {
        printf("%d\n",rand());
    }


    return 0;
}