#include <stdio.h>
#include <math.h>

double f_max(double a, double b, double c)
{
	if(a>b)
		if(a>c)
			return a;
		else 
			return c;
	else
		if(b>c)
			return b;
		else
			return c;
}

int main()
{
	double ea[4], a[4], b[4], c[4], x[3], xr[3], xold[3];
	int i, count=0;
	double es=5, ram;

	x[0] = x[1] = x[2] = 0;
	xold[0] = xold[1] = xold[2] = 0;

	printf("put 3 equation\n");
	for(i=0;i<4;i++)
		scanf("%lf", &a[i]);
	for(i=0;i<4;i++)
		scanf("%lf", &b[i]);
	for(i=0;i<4;i++)
		scanf("%lf", &c[i]);

	printf("put ramda value\n");
	scanf("%lf", &ram);

	ea[0]=ea[1]=ea[2]=ea[3]=100;

	while(ea[3]>es)
	{
		x[0] = (a[3]-a[1]*xr[1]-a[2]*xr[2])/a[0];

		if(ram==0)
			xr[0] = x[0];
		else
			xr[0] = ram*x[0]+(1-ram)*xr[0];

		x[1] = (b[3]-b[0]*xr[0]-b[2]*xr[2])/b[1];

		if(ram==0)
			xr[1] = x[1];
		else
			xr[1] = ram*x[1]+(1-ram)*xr[1];
		
		x[2] = (c[3]-c[0]*xr[0]-c[1]*xr[1])/c[2];

		if(ram==0)
			xr[2] = x[2];
		else
			xr[2] = ram*x[2]+(1-ram)*xr[2];

		for(i=0;i<3;i++)
			ea[i] = fabs((xr[i]-xold[i])/xr[i])*100;

		xold[0] = xr[0];
		xold[1] = xr[1];
		xold[2] = xr[2];

		ea[3] = f_max(ea[0], ea[1], ea[2]);

		count++;

		printf("=========================================\n");
		printf("iter %d\n", count);
		printf("x1 : %.6lf x2 : %.6lf x3 : %.6lf ||\nxr1 : %.6lf xr2 : %.6lf xr3 : %.6lf ||\nea_1 : %.6lf ea_2 : %.6lf ea_3 : %.6lf|| ea_max : %.6lf\n", x[0], x[1], x[2], xr[0], xr[1], xr[2],  ea[0], ea[1], ea[2], ea[3]);
	}
	return 0;
}
		
	
	
