#include<stdio.h>
#include<math.h>

double f(int n)
{
	double result=0;
	for(int i=0; i!=n; i++)
		result += sqrt(i+1);
	return result;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%lf\n", f(n));
} 
