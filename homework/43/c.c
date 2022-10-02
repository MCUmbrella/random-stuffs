#include<stdio.h>

double f(double m, double n)
{
	double result=0;
	for(int i=m; i!=n+1; i++)
		result+=i*i+1.0/i;
	return result;
}

int main()
{
	int m,n;
	scanf("%d%d", &m, &n);
	printf("%lf\n", f(m, n));
} 
