#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

double f(double x)
{
	return pow(x,3)-2*pow(x,2)+1;
}

int main()
{
	double x[100];
	int i=1, n=1;
	double es = 1e-5;
	double ea= 100;
	x[0] = -10;
	x[1] = -9.8;

	
	while(ea>es)
	{
		x[i+1] = x[i] - (f(x[i])*(x[i]-x[i-1])/(f(x[i])-f(x[i-1])));
		ea = fabs((x[i+1]-x[i])/x[i+1])*100;
		printf("iter%d : x%d %.8f, ea %f\n", n, i+1, x[i+1], ea);
		i++; n++;
	}

	return 0;
}




