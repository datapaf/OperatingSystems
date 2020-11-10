#include <stdio.h>
#include <string.h>

#define FILE_NAME "input_dl1.txt"
#define NUM_OF_PROC 3
#define NUM_OF_RES 4

void update_A(int A[NUM_OF_RES], int C_i[NUM_OF_RES])
{
	for ( int i = 0 ; i < NUM_OF_RES ; i++ )
		A[i] += C_i[i];
}

int can_allocate(int A[NUM_OF_RES], int R_i[NUM_OF_RES], int is_terminated)
{
	if (is_terminated)
		return 0;

	for ( int i = 0 ; i < NUM_OF_RES ; i++ )
	{
		if ( A[i] < R_i[i] )
			return 0;
	}	

	return 1;
}

int main()
{
	FILE* fh = fopen(FILE_NAME, "r");

	int E[NUM_OF_RES];
	int A[NUM_OF_RES];

	int C[NUM_OF_PROC][NUM_OF_RES];
	int R[NUM_OF_PROC][NUM_OF_RES];
	

	// initialization

	for ( int i = 0 ; i < NUM_OF_RES ; i++ )
	{
		fscanf(fh, "%1d", &E[i]);
	} 
	
	for ( int i = 0 ; i < NUM_OF_RES ; i++ )
	{
		fscanf(fh, "%1d", &A[i]);
	}	 

	for ( int i = 0 ; i < NUM_OF_PROC ; i++ )
	{
		for ( int j = 0 ; j < NUM_OF_RES ; j++ )
		{
			fscanf(fh, "%1d", &C[i][j]);	
		}
	}	

	for ( int i = 0 ; i < NUM_OF_PROC ; i++ )
	{
		for ( int j = 0 ; j < NUM_OF_RES ; j++ )
		{
			fscanf(fh, "%1d", &R[i][j]);	
		}
	}


    FILE* out = fopen("output.txt", "w");

	// algorithm

	int is_terminated[NUM_OF_PROC] = {0};

	for ( int j = 0 ; j < NUM_OF_PROC ; j++ )
	{
		int is_possible_to_allocate;
		for ( int i = 0 ; i < NUM_OF_PROC ; i++ )
		{
			is_possible_to_allocate = can_allocate(A, R[i], is_terminated[i]);
			if (is_possible_to_allocate) {
				memset(R[i], 0, sizeof(R[i]));
				update_A(A, C[i]);
				memset(C[i], 0, sizeof(C[i]));
				is_terminated[i] = 1;
			}
		}

		if ( !is_possible_to_allocate )
		{
			fprintf(out, "deadlock with processes ");
			for ( int i = 0 ; i < NUM_OF_PROC ; i++ )
			{
				if ( !is_terminated[i] )
					fprintf(out, "%d ", i);
			} 
			return 0;
		}
	}

	fprintf(out, "no deadlock");

	fclose(fh);	

	return 0;
}