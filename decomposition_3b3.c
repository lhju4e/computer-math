#include <stdio.h>

int main()
{
	double A[9];
	double L[9];
	double U[9];
	int i=0;

	for(i=0;i<9;i++)
	{
		scanf("%lf", &A[i]);
	}

	for(i=0;i<9;i++)
	{
		L[i] = 0;
		U[i] = 0;	
	}

	L[0] = L[4] = L[8] = 1;

	U[0] = A[0];
	U[1] = A[1];
	U[2] = A[2];
	L[3] = A[3]/U[0];
	L[6] = A[6]/U[0];
	U[4] = A[4]-L[3]*U[1];
	U[5] = A[5]-L[3]*U[2];
	L[7] = (A[7]-L[6]*U[1])/U[4];
	U[8] = A[8]-L[6]*U[2]-L[7]*U[5];

	printf("L is\n");
	for(i=0;i<9;i++)
	{
		printf("%.5lf ", L[i]);
		if(i==2|i==5)
			printf("\n");
	}
	printf("\n");
	printf("U is\n");
	for(i=0;i<9;i++){
		printf("%.5lf ", U[i]);
		if(i==2|i==5)
			printf("\n");
	}
	return 0;
}
