#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

#define MASTER 0

typedef long long int lli;

typedef struct data_s
{
	lli max_prime;
	lli count;
} data;



int isprime(long long int n) 
{
	int i,squareroot;

	squareroot = (int) sqrt(n);
	for (i=3; i<=squareroot; i=i+2)
	{
		if (n%i==0)
			return 0;
	}
	return 1;

}

int int_isprime(int n)
{
	int i,squareroot;

	squareroot = (int) sqrt(n);
	for (i=3; i<=squareroot; i=i+2)
	{
		if (n%i==0)
			return 0;
	}
	return 1;

}

int main(int argc, char* argv[])
{
	int pc;       /* prime counter */
   	int foundone; /* most recent prime found */
	long long int n, limit;
	int rank,size;
	
	data d;
	MPI_Datatype datatype,oldtype[1];
	int blockcount[1];
	MPI_Aint offsets[1];
	MPI_Status status;
	

	/* start mpi */
	MPI_Init(&argc,&argv);

	sscanf(argv[1],"%llu",&limit);	

	MPI_Comm_rank( MPI_COMM_WORLD , &rank);
	MPI_Comm_size( MPI_COMM_WORLD , &size);

	/* change MPI type */
	blockcount[0]=2;
	offsets[0]=0;
	oldtype[0]=MPI_LONG_LONG_INT;
	MPI_Type_create_struct(1, blockcount, offsets, oldtype, &datatype);
	MPI_Type_commit(&datatype);

	if(rank==MASTER)
	{
		printf("Starting. Numbers to be scanned= %lld\n",limit);
	}


	d.count=0;
	d.max_prime=0;
  	//pc=0;     
	

	if(limit==2)
	{
		d.max_prime=2;
		
		//foundone=2;
		//pc++;
	}

	for (n=3+2*rank; n<=limit; n=n+2*size)
	{
		if(n<=2147483647)
		{
			if (int_isprime(n)) 
			{
				d.count++;
				d.max_prime= n ;
			//pc++;
			//foundone = n;
			}
		}
		else
		{
			if (isprime(n)) 
			{
				d.count++;
				d.max_prime= n ;
			//pc++;
			//foundone = n;
			}
		}			
	}

	//printf("rank %d of size %d \n",rank,size);

	if(rank != MASTER )
	{
		MPI_Send(&d,1,datatype,0,0,MPI_COMM_WORLD);
	}
	else
	{
		data recv;
		int source;
		for(source=1;source<size;source++)
		{
			MPI_Recv(&recv, 1, datatype, source, 0, MPI_COMM_WORLD, &status);
			d.count+=recv.count;
			d.max_prime= d.max_prime>recv.max_prime?d.max_prime:recv.max_prime;
		}
	}

	MPI_Type_free(&datatype);

	

	MPI_Finalize();
	/* end mpi */

	if(rank==MASTER)
	{
		if(limit>=2) d.count++;
		printf("Done. Largest prime is %lld Total primes %lld\n",d.max_prime,d.count);
		
	}

	//printf("Done. Largest prime is %lld Total primes %lld\n",d.max_prime,d.count);

	return 0;
} 