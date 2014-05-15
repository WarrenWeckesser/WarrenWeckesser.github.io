/*
 *  pend_taylor3_demo.c
 *
 *  This program demonstrates the use of the function created by the
 *  "taylor" mode of VFGEN. 
 *
 *
 *  Copyright (c) 2006-2014 Warren Weckesser, www.warrenweckesser.net
 */

#include <stdio.h>
#include "pendulum_taylor3.h"


void print_solution(double t, double x[])
{
    printf("%8.5f %15.10f %15.10f\n", t, x[0], x[1]);
}

int main(int argc, char *argv[])
{
    double p[4];
    double x0[2], x[2], xderivs[3][2];
    double t, tmin, tmax;
    int numsamples;
    int i;

    /*
     *  Set the pendulum parameters.
     */
    p[0] = 9.81;   /*  g  */
    p[1] = 0.25;   /*  b  */
    p[2] = 1.0;    /*  L  */
    p[3] = 1.0;    /*  m  */

    /*
     *  x0 holds the point where we will do the Taylor expansion.
     */  
    x0[0] =  1.0;      /* theta(0) */
    x0[1] =  1.5;      /* v(0)     */

    pendulum_derivs3(xderivs, x0, p);

    tmin =  0.0;
    tmax =  1.0;
    numsamples = 101;
    for (i = 0; i < numsamples; ++i) {
        t = tmin + i*(tmax - tmin)/(numsamples - 1);
        pendulum_evaltaylor3(x, t, x0, xderivs);
        print_solution(t, x);
    }
}
