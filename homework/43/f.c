#include<stdio.h>

double fact(int x)
{
    double a=1;
    for(int b=1; b!=x;) a*=++b;
    return a;
}

int main()
{
	double result;
	int n;
	scanf("%d", &n);
	for(int i=1; i!=n+1; i++)
		result += fact(i);
	printf("%lf\n", result);
} 
