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
	double ea[4], a[4], b[4], c[4], x[3], p[3];
	int i, count=0;
	double es=5;

	x[0] = x[1] = x[2] = 0;

	printf("put 3 equation\n");
	for(i=0;i<4;i++)
		scanf("%lf", &a[i]);
	for(i=0;i<4;i++)
		scanf("%lf", &b[i]);
	for(i=0;i<4;i++)
		scanf("%lf", &c[i]);

	ea[0]=ea[1]=ea[2]=ea[3]=100;

	x[0]=x[1]=x[2]=0;

	while(ea[3]>es)
	{
		p[0]=(a[3]-a[1]*x[1]-a[2]*x[2])/a[0];
		p[1]=(b[3]-b[0]*x[0]-b[2]*x[2])/b[1];
		p[2]=(c[3]-c[0]*x[0]-c[1]*x[1])/c[2];

		for(i=0;i<3;i++)
			ea[i] = fabs((x[i]-p[i])/p[i])*100;
	
		x[0] = p[0];
		x[1] = p[1];
		x[2] = p[2];

		ea[3] = f_max(ea[0], ea[1], ea[2]);

		count++;

		printf("=========================================\n");
		printf("iter %d\n", count);
		printf("x1 : %.6lf x2 : %.6lf x3 : %.6lf || ea_1 : %.6lf ea_2 : %.6lf ea_3 : %.6lf|| ea_max : %.6lf\n", x[0], x[1], x[2], ea[0], ea[1], ea[2], ea[3]);
	}
	return 0;
}
		
	
	
