//
//  pendulum_adolc.cpp
//
//  ADOLC C++ file for the vector field named: pendulum
//
//  This file was generated by the program VFGEN, version: 2.5.0-dev
//  Generated on 14-May-2014 at 21:03
//

#include <math.h>
#include "adolc/adolc.h"

//
//  The vector field.
//

void pendulum_vf(short int tag, double *y_, double *f_, double *params_)
{
    adouble ay_[2];
    adouble af_[2];

    const adouble Pi = M_PI;
    adouble theta, v;
    adouble g, b, L, m;

    trace_on(tag);
    for (int i = 0; i < 2; i++) {
        ay_[i] <<= y_[i];
    }
    theta      = ay_[0];
    v          = ay_[1];

    g          = params_[0];
    b          = params_[1];
    L          = params_[2];
    m          = params_[3];

    af_[0] = v;
    af_[1] = -v/m*b/(L*L)-g*sin(theta)/L;
    for (int i = 0; i < 2; i++) {
        af_[i] >>= f_[i];
    }
    trace_off(tag);
}

