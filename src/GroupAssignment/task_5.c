/**
 * 
 * Written by Sukhrobbek Ilyosbekov
 * Source code available in https://github.com/suxrobGM/CCourseworkAssignments
 * 
 **/
#include <stdio.h>

int main()
{   
    short int si = 10;
    int i = 25;
    long int li = 50;
    float f = 0.5;
    double d = 1.5;

    float x1 = f + si*i - li;
    float x2 = i/f + si*d;
    float x3 = (double)i/si * f;
    float x4 = li/i + (int)d/f;

    printf("%f\n", x1);
    printf("%f\n", x2);
    printf("%f\n", x3);
    printf("%f\n", x4);

    return 0;
}