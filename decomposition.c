#include <stdio.h>
#include <math.h>

int main()
{
	double l[2][2], u[2][2];
	double a[2][2];
	int i=0, j=0;

	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			scanf("%lf", &a[i][j]);
		}
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			if(i==j)
			{
				l[i][j] = 1;
				u[i][j] = 1;
			}
			else
			{
				l[i][j] = 0;
				u[i][j] = 0;
			}
		}


	u[0][0] = a[0][0];
	u[0][1] = a[0][1];
	l[1][0] = a[1][0]/u[0][0];
	u[1][1] = a[1][1]-l[1][0]*u[0][1];

	printf("L is\n");
	for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
				printf("%lf ", l[i][j]);
			printf("\n");
		}

	printf("U is\n");
	for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
				printf("%lf ", u[i][j]);
			printf("\n");
		}
	printf("L*U is\n");
	printf("%lf %lf \n%lf %lf\n", l[0][0]*u[0][0]+l[0][1]*u[1][0], l[0][0]*u[0][1]+l[0][1]*u[1][1], l[1][0]*u[0][0]+l[1][1]*u[1][0], l[1][0]*u[0][1]+l[1][1]*u[1][1]);
	return 0;
}
