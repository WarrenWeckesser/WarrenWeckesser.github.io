/*
 *  pend_main.c
 *
 *  This program demonstrates the use of the function created by the
 *  "taylor" mode of VFGEN.  It is a simple ODE solver with a fixed
 *  step size.
 *
 *  Copyright (c) 2006-2014  Warren Weckesser
 */

#include <stdio.h>
#include "pendulum_taylor7.h"

void print_solution(double t, double x[])
{
    printf("%8.5f %15.10f %15.10f\n", t, x[0], x[1]);
}

int main(int argc, char *argv[])
{
    double p[4];
    double x[2], xnew[2], xderivs[7][2];
    double t;
    double h;
    int numsteps;
    int i;

    /*
     *  Set the pendulum parameters.
     */
    p[0] = 9.81;   /*  g  */
    p[1] = 0.25;   /*  b  */
    p[2] = 1.0;    /*  L  */
    p[3] = 1.0;    /*  m  */

    /*
     *  Initial conditions.
     */
    x[0] = 3.1415;   /* theta(0) */
    x[1] = 0.0;      /* v(0)     */

    h = 0.05;        /* step size */
    numsteps = 400;
    t = 0.0;
    print_solution(t, x);
    for (i = 0; i < numsteps; ++i) {
        pendulum_derivs7(xderivs, x, p);
        pendulum_evaltaylor7(xnew, h, x, xderivs);
        x[0] = xnew[0];
        x[1] = xnew[1];
        t = t + h;
        print_solution(t, x);
    }
}
