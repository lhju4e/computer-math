#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

double f(double x)
{
	return 0.6*pow(x,4)-7.533333*pow(x,3)+29.9*pow(x,2)-37.966667*x+5;
}

double ff(double x)
{
	return 2.4*pow(x,3)-7.533333*3*pow(x,2)+29.9*2*pow(x,1)-37.966667; 
}

int main(){
	double x[100];
	int i = 0;
	x[0] = 3.8;

	while(1)	
	{
		i++;
		x[i] =  x[i-1]-f(x[i-1])/ff(x[i-1]);
		printf("x %d : %.6f\n", i, x[i]);
		 
		if(fabs(f(x[i]))<=0.001)
			break;
	}
	return 0;
}
