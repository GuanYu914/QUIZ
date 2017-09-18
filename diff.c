#include <stdio.h>
#include <math.h>

#define dx 0.0000000001

typedef double (*F)(double);

double function(double x)
{
	return (pow(x, 5.0) + pow(x, 4.0) + 3);
}

double df(F f, double x)
{
	double dy = f(x + dx) - f(x);
	return dy/dx;
}

void showdiff(F f, char *fname, double x)
{
	printf("f(x) is %s\n", fname);
	printf("f(%f) = %f\n", x, f(x));
	printf("f'(%f) = %f\n", x, df(f, x));
}

int main(void)
{
	showdiff(function, "x^5 + x^4 + 3", 1.0);
	return 0;
}
