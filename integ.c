#include <stdio.h>
#include <math.h>

#define dx 0.0000001

typedef double (*F)(double);

double function(double x)
{
	return (pow(x, 5) + pow(x, 4) + 3);
}

double integral(F f, double a, double b)
{
	double sum = 0.0;
	double x;
	for(x = a; x <= b; x+=dx)
	{
		sum += f(x) * dx;
	}
	return sum;
}

void showintegral(F f, char *fname, double a, double b)
{
	printf("f(x) is %s\n", fname);
	printf("f(%f) = %f, f(%f) = %f\n", a, f(a), b, f(b));
	printf("integral(f,%f,%f) = %f\n", a, b, integral(f, a, b));
}

int main(void)
{
	showintegral(function, "x^5 + x^4 + 3", 1, 3);
	return 0;
}
