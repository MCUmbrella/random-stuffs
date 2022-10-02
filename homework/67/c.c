#include<stdio.h>
#include<assert.h>
#include "CommonUtil.h"

int getCost(double km, double minute)
{
    double result = 0;
    result += (km > 13 ? (int)(km-13) * 3 + 20 + 10 :
        km > 3 ? (int)(km-3) * 2 + 10 :
        10) + (int)minute / 5 * 2;
    return round(result);
}

int main(int argc, char** argv)
{
    double k, m;
    scanf("%lf%lf", &k, &m);
    assert(k >= 0 && m >= 0);
    printf("%d\n", getCost(k, m));
    return 0;
}
