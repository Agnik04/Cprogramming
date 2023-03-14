#include <stdio.h>

int main()
{
    float p,t,r,si,ci;
    printf("Enter the principal amount (p):");
    scanf("%f", &p);
    printf("Enter the time in year (t):");
    scanf("%f", &t);
    printf("Enter the rate in percent (r):");
    scanf("%f", &r);
    
    /*Calculating simple interest*/
    si=(p*t*r)/100.0;
    
    /*Calculating compound interest*/
    ci=p*(pow(1+r/100,t)-1);
    
    printf("Simple Interest = %f\n",si);
    printf("compound Interest = %f\n",ci);
    return 0;
}