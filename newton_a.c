#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

double f(double x)
{
	return x*pow(M_E,x)-1;
}

double ff(double x)
{
	return (x+1)*pow(M_E,x);
}
int main(){
	double x[50];
	int i = 0;
	double ea = 1;
	x[0] = 0.5;

	while(ea>0)	
	{
		i++;
		x[i] =  x[i-1]-f(x[i-1])/ff(x[i-1]);
		printf("x %d : %.6f\n", i, x[i]);
		ea = fabs((x[i]-x[i-1])/x[i]);
	}
	return 0;
}
