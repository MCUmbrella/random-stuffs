#include<malloc.h>
#include<math.h>

#ifndef TRIANGLE_UTIL_H
#define TRIANGLE_UTIL_H

struct triangle
{
    double x1=0, y1=0, x2=0, y2=0, x3=0, y3=0;
};

triangle* parseTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    triangle* t = (triangle*)malloc(sizeof(triangle));
    t->x1 = x1; t->x2 = x2; t->y1 = y1; t->y2 = y2; t->x3 = x3; t->y3 = y3;
    return t;
}

double* sideLength(triangle* t)
{
    double* a = (double*)malloc(sizeof(double) * 3);
    a[0] = sqrt(pow(t->x1 - t->x2, 2) + pow(t->y1 - t->y2, 2));
    a[1] = sqrt(pow(t->x1 - t->x3, 2) + pow(t->y1 - t->y3, 2));
    a[2] = sqrt(pow(t->x2 - t->x3, 2) + pow(t->y2 - t->y3, 2));
    return a;
}

char isValidTriangle(triangle* t)
{
    double* sl = sideLength(t);
    if(sl[0] && sl[1] && sl[2]) return 1;
    return 0;
}

double area(triangle* t)
{
    double* sl = sideLength(t);
    double s = (sl[0] + sl[1] + sl[2]) / 2;
    return sqrt(s * (s - sl[0]) * (s - sl[1]) * (s - sl[2]));
}

#endif
