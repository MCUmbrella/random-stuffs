#include<stdio.h>

double f(int n)
{
	double result=1;
	int sign=-1;
	if(n==1) return 1;
	for(double i=2; i!=n+1; i++)
	{
		result += sign * i / (2*i-1);
		sign *= -1;
	}
	return result;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%lf\n", f(n));
} 
