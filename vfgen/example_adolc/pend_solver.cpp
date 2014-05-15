//
//  pend_solver.cpp
//
//  This program demonstrates the use of the function created by the
//  "adolc" mode of VFGEN.  It is a simple ODE solver with a fixed
//  step size.
//
//
//  Copyright (c) 2008 Warren Weckesser, www.warrenweckesser.net
//

#include <iostream>
#include <iomanip>

#include "adolc/drivers/odedrivers.h"
#include "adolc/adalloc.h"

#include "pendulum_adolc.h"

using namespace std;

void print_solution(double t, double x[])
    {
    cout << setprecision(5) << fixed << setw(8) << t;
    cout << setprecision(10) << setw(15) << x[0] << setw(15) << x[1] << endl;
    }

int main(int argc, char *argv[])
    {
    double p[4];
    double x[2], xnew[2];
    double f[2];
    double t;
    double h;
    int numsteps;
    int deg = 7;
    const int tag = 1;

    double **taylorcoeffs = myalloc2(2,deg+1);

    //
    // Set the pendulum parameters.
    //
    p[0] = 9.81;   //  g
    p[1] = 0.25;   //  b
    p[2] = 1.0;    //  L
    p[3] = 1.0;    //  m

    //
    // Initial conditions.
    //
    x[0] = 3.1415;   // theta(0)
    x[1] = 0.0;      // v(0)

    h = 0.05;        // step size
    numsteps = 400;
    t = 0.0;
    pendulum_vf(tag,x,f,p); // Call pendulum_vf once to compute the ADOL-C data
    print_solution(t,x);
    for (int i = 0; i < numsteps; ++i)
        {
        // Call forode to compute the Taylor coefficients at the current x
        taylorcoeffs[0][0] = x[0];
        taylorcoeffs[1][0] = x[1];
        forode(tag,2,deg,taylorcoeffs);
        // Use the Taylor coefficients to compute the approximate value xnew = x(t+h)
        double hj = 1.0;
        xnew[0] = 0.0;
        xnew[1] = 0.0;
        for (int j = 0; j < deg+1; ++j)
            {
            for (int i = 0; i < 2; ++i)
                xnew[i] += taylorcoeffs[i][j]*hj;
            hj = hj*h;
            }
        x[0] = xnew[0];
        x[1] = xnew[1];
        t = t + h;
        print_solution(t,x);
        }
    }
