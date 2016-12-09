/********************************************************************** 
* DESCRIPTION:
* Serial Concurrent Wave Equation - C Version
* This program implements the concurrent wave equation
 *********************************************************************/
#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
#include <time.h>
#include <cuda_runtime.h>
#define MAXPOINTS 1000000 
#define MAXSTEPS 1000000 
#define MINPOINTS 20 
#define PI 3.14159265

#define thread_num 1008
void check_param(void); 
void init_line(void); 
void update (void); 
void printfinal (void);
int nsteps , tpoints ,rcode;
float values[MAXPOINTS+2],oldval[MAXPOINTS+2], newval[MAXPOINTS+2];
/* number of time steps */
/* total points along string */ /* generic return code */
/* values at time t */
/* values at time (t-dt) */
/* values at time (t+dt) */
/********************************************************************** * Checks input values from parameters *********************************************************************/
void check_param(void) 
{
	char tchar [20];
/* check number of points, number of iterations */
	while ((tpoints < MINPOINTS) || (tpoints > MAXPOINTS)) 
	{
		printf("Enter number of points along vibrating string [%d-%d]: "
			,MINPOINTS , MAXPOINTS); scanf("%s", tchar);
		tpoints = atoi(tchar);
		if ((tpoints < MINPOINTS) || (tpoints > MAXPOINTS))
			printf("Invalid. Please enter value between %d and %d\n", MINPOINTS , MAXPOINTS);
	}
	while ((nsteps < 1) || (nsteps > MAXSTEPS)) 
	{
		printf("Enter number of time steps [1-%d]: ", MAXSTEPS); 
		scanf("%s", tchar);
		

		nsteps = atoi(tchar);
		if ((nsteps < 1) || (nsteps > MAXSTEPS))
			printf("Invalid. Please enter value between 1 and %d\n", MAXSTEPS);
	}
	printf("Using points = %d, steps = %d\n", tpoints, nsteps); 

}

/********************************************************************** * Initialize points on line *********************************************************************/
void init_line(void) 
{
	int  j;
	float x, fac, k, tmp;
/* Calculate initial values based on sine curve */
	fac = 2.0 * PI;
	k = 0.0;
	tmp = tpoints - 1;
	for (j = 1; j <= tpoints; j++) 
	{
		x = k/tmp;
		values[j] = sin (fac * x); 
		k = k + 1.0;

		oldval[j]=values[j];
	}
/* Initialize old values array */
	/*for (i = 1; i <= tpoints; i++) 
		oldval[i] = values[i];*/
}
/********************************************************************** * Calculate new values using wave equation *********************************************************************/
void do_math(int i) 
{
	float dtime, c, dx, tau, sqtau;
	dtime = 0.3;
	c = 1.0;
	dx = 1.0;
	tau = (c * dtime / dx);
	sqtau = tau * tau;
	newval[i] = (2.0 * values[i]) - oldval[i] + (sqtau * (-2.0)*values[i]); 
}

//cuda update
__global__ void cuda_update(int *cuda_nsteps, int *cuda_tpoints,
	float *cuda_values,float *cuda_oldval)
{
	const int idx=blockIdx.x*thread_num+threadIdx.x+1;
	//__shared__ float test_newval[MAXPOINTS+2];
	int i;
	float dtime, c, dx, tau, sqtau;

	const int num=*cuda_tpoints;
	const int step=*cuda_nsteps;
	float reg_values, reg_newval, reg_oldval;
	
	if(idx==1 || idx==num) cuda_values[idx]=0.0;
	else if(idx<*cuda_tpoints)
	{
		reg_oldval=cuda_oldval[idx];
		reg_values=cuda_values[idx];
		
		for(i=1;i<=step;i++)
		{
			dtime = 0.3;
			c = 1.0;
			dx = 1.0;
			tau = (c * dtime / dx);
			sqtau = tau * tau;
			//share_newval[k] = (2.0 * share_values[k]) - share_oldval[k] + (sqtau * (-2.0) * share_values[k]);
			reg_newval=(2.0 * reg_values) - reg_oldval + (sqtau * (-2.0) * reg_values );
			reg_oldval=reg_values;
			reg_values=reg_newval;
		}
		cuda_values[idx]=reg_values;
		
	}






}
/********************************************************************** * Update all values along line a specified number of times *********************************************************************/
void update () 
{
	int i, j;
/* Update values for each time step */
	for (i = 1; i<= nsteps; i++) 
	{

  /* Update points along line for this time step */
		for (j = 1; j <= tpoints; j++) 
		{
/* global endpoints */
			if ((j == 1) || (j == tpoints)) newval[j] = 0.0;
			else do_math(j);
			/* Update old values with new values */
			oldval[j] = values[j]; 
			values[j] = newval[j];
		} 
	}
}
/********************************************************************** * Print final results *********************************************************************/
void printfinal () 
{
	int i;
	for (i = 1; i <= tpoints; i++) 
	{
		printf("%6.4f ", values[i]); if (i%10 == 0)
		printf("\n");
	} 
}
/********************************************************************** * Main program *********************************************************************/
int main(int argc, char *argv[]) 
{
	sscanf(argv[1],"%d",&tpoints); sscanf(argv[2],"%d",&nsteps);
	check_param();
	
	printf("Initializing points on the line...\n"); 
	init_line();
	
	float *cuda_values , *cuda_oldval;
	int *cuda_nsteps, *cuda_tpoints;

	const int block_num=(tpoints+thread_num-1)/thread_num;

	


	/* cuda Malloc */
	cudaMalloc((void**) &cuda_values, sizeof(float) * (MAXPOINTS+2));
	cudaMalloc((void**) &cuda_oldval, sizeof(float) * (MAXPOINTS+2));
	cudaMalloc((void**) &cuda_tpoints, sizeof(int));
	cudaMalloc((void**) &cuda_nsteps, sizeof(int));

	/* cuda Memory copy */
	cudaMemcpy(cuda_values, values, sizeof(float) * (MAXPOINTS+2), cudaMemcpyHostToDevice);
	cudaMemcpy(cuda_oldval, oldval, sizeof(float) * (MAXPOINTS+2), cudaMemcpyHostToDevice);
	cudaMemcpy(cuda_nsteps, &nsteps, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(cuda_tpoints, &tpoints, sizeof(int), cudaMemcpyHostToDevice);

	//cuda_init_line<<<block_num,thread_num>>>(cuda_tpoints,cuda_values,cuda_oldval);

	//cudaMemcpy(values,cuda_values,sizeof(float) * (MAXPOINTS+2), cudaMemcpyDeviceToHost);
	
	//printfinal();
	
	printf("Updating all points for all time steps...\n");
	
	cuda_update<<<block_num,thread_num>>>(cuda_nsteps,cuda_tpoints,cuda_values,cuda_oldval);


	//return result
	cudaMemcpy(values, cuda_values, sizeof(float) * (MAXPOINTS+2), cudaMemcpyDeviceToHost);

	//update();
	
	printf("Printing final results...\n");
	printfinal();
	printf("\nDone.\n\n"); return 0;
}