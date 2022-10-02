#include<stdio.h>

float f(float x)
{
	return x<=50 ? 0.53*x : 50*0.53+(x-50)*0.58;
}

int main()
{
	float x;
	scanf("%f", &x);
	if(x<0)
	{
		puts("Invalid Value!");
		return -1;
	}
	printf("%f\n", f(x));
	return 0;
}
