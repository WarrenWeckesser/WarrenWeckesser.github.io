/*
 *  vanderpol_adaptive8.c
 *
 *  This program demonstrates the use of the function created by the
 *  "taylor" mode of VFGEN.
 *
 *
 *  Copyright (c) 2006, 2008 Warren Weckesser, www.warrenweckesser.net
 *  
 */

#include <stdio.h>
#include <math.h>
#include "vanderpol_taylor8.h"

void print_solution(double t, double x[])
{
    printf("%12.8f %18.10g %18.10g\n",t,x[0],x[1]);
}

int main(int argc, char *argv[])
{
    double p[4];
    double x[2], xnew[2], xback[2], xhalf[2], xbackhalf[2];
    double xd1[8][2], xd2[8][2];
    double (*pd1)[2], (*pd2)[2], (*tmp)[2];
    double t, tstop;
    double h, hmin, hmax;
    double tol;
    double mintol;
    int i;

    /*
     *  Parameters.
     */
    p[0] = 0.001;   /*  epsilon  */

    /*
     *  Initial conditions.
     */
    x[0] = 0.01;   /* x(0) */
    x[1] = 0.0;    /* y(0) */

    tol = 1.0e-8;
    mintol = 1.0e-10;

    hmin = 0.00001;
    hmax = 2.0;
    h = 0.01;

    t = 0.0;
    tstop = 10.0;

    pd1 = xd1;
    pd2 = xd2;
    vanderpol_derivs8(pd1,x,p);
    print_solution(t,x);
    while (t < tstop) {
        vanderpol_evaltaylor8(xnew,h,x,pd1);
        vanderpol_derivs8(pd2,xnew,p);
        vanderpol_evaltaylor8(xback,-h,xnew,pd2);
        double e = sqrt(pow(x[0]-xback[0],2)+pow(x[1]-xback[1],2));
        if (e > tol) {
            if  (h > hmin) {
                h = (2.0/3.0)*h;
                if (h < hmin) {
                    h = hmin;
                }
                // fprintf(stderr,"t=%f  decreasing step size to %f\n",t,h);
            }
            else {
                fprintf(stderr,"Minimum step size reached without achieving tolerance.\n");
                break;
            }
        }
        else {
            x[0] = xnew[0];
            x[1] = xnew[1];
            tmp = pd1;
            pd1 = pd2;
            pd2 = tmp;
            t = t + h;
            print_solution(t,x);
            if (e < mintol && h < hmax) {
                h = 1.5*h;
                if (h > hmax) {
                    h = hmax;
                }
                // fprintf(stderr,"t=%f  increasing step size to %f\n",t,h);
            }
            if (t+h > tstop) {
                h = tstop - t;
            }
        }
    }
}
