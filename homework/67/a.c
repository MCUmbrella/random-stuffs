#include<stdio.h>
#include<malloc.h>
#include "CommonUtil.h"

int main(int argc, char** argv)
{
    int* a;
    a=(int*)malloc(sizeof(int)*3);
    for(int i=0; i!=3; i++)
        scanf("%d", &a[i]);
    sortInt(a, 3);
    for(int i=0; i!=3; i++)
        printf("%d ", a[i]);
    return 0;
}
