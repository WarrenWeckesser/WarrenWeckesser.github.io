//
// sys-wn2-edit.cpp -- Edited to add an approximate solution in sys_stsol
//
// PDDE-CONT System Definition file for the VFGEN vector field: wn2
//
// This file was generated by the program VFGEN, version: 2.5.0-dev
// Generated on 14-May-2014 at 20:11
//

#include <cmath>
#include "pddesys.h"

extern "C" {

int sys_ndim()  { return 2; }  // System dimension
int sys_npar()  { return 4; }  // Number of parameters, plus one (for the period)
int sys_ntau()  { return 1; }  // Number of delays, plus one
int sys_nderi() { return 2; }  // Order of derivatives computed here

//
// sys_rhs(...) computes the vector field.
//
// The lags are: {}
//
// If X(t) is the state vector at time t, then
//    Zlags_ = [ X(t)  ]
//
void sys_rhs(Vector& out, double t, const Matrix& Zlags_, const Vector& par_)
{
    const double Pi = M_PI;
    // State variables
    const double x          = Zlags_(0,0);
    const double y          = Zlags_(1,0);
    // Parameters (par_(0) is the period)
    const double epsilon    = par_(1);
    const double a          = par_(2);
    const double T          = par_(3);
    // Compute the vector field
    out(0) = y*T;
    out(1) = -( x+epsilon*( y-a*cos(2.0*t*Pi)+(x*x*x)))*T;

    return;
}

//
// wn2_jacx
//
// This function computes the Jacobian of the vector field
// with respect to the k-th delayed vector.
//

static inline void wn2_jacx(Matrix& jac_, double t, int k, const Matrix& Zlags_, const Vector& par_)
{
    const double Pi = M_PI;
    // Parameters
    const double epsilon    = par_(1);
    const double a          = par_(2);
    const double T          = par_(3);

    if (k == 0) {
        // Derivatives wrt the state variables
        jac_(0,0) = 0.0;
        jac_(0,1) = T;
        jac_(1,0) = -T*( 3.0*pow(Zlags_(0,0),2.0)*epsilon+1.0);
        jac_(1,1) = -T*epsilon;
    }
}


//
// wn2_jacp
//
// This function computes the Jacobian of the vector field
// with respect to the j-th parameter.
//

static inline void wn2_jacp(Matrix& jac_, double t, int j, const Matrix& Zlags_, const Vector& par_)
{
    const double Pi = M_PI;

    // Parameters
    const double epsilon    = par_(1);
    const double a          = par_(2);
    const double T          = par_(3);

    if (j == 1) {
        // Derivative wrt epsilon
        jac_(0,0) = 0.0;
        jac_(1,0) = -( Zlags_(1,0)-a*cos(2.0*t*Pi)+pow(Zlags_(0,0),3.0))*T;
    }
    else if (j == 2) {
        // Derivative wrt a
        jac_(0,0) = 0.0;
        jac_(1,0) = cos(2.0*t*Pi)*T*epsilon;
    }
    else if (j == 3) {
        // Derivative wrt T
        jac_(0,0) = Zlags_(1,0);
        jac_(1,0) = -Zlags_(0,0)-( Zlags_(1,0)-a*cos(2.0*t*Pi)+pow(Zlags_(0,0),3.0))*epsilon;
    }
}


//
// wn2_jacxp
//
// This function computes the Jacobian of the vector field
// with respect to the k-th delayed state vector and the j-th parameter.
//

static inline void wn2_jacxp(Matrix& jac_, double t, int k, int j, const Matrix& Zlags_, const Vector& par_)
{
    const double Pi = M_PI;

    // Parameters
    const double epsilon    = par_(1);
    const double a          = par_(2);
    const double T          = par_(3);

    if (k == 0) {
        // Derivatives wrt the state variables
        if (j == 1) {
            // Derivative wrt epsilon
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = -3.0*pow(Zlags_(0,0),2.0)*T;
            jac_(1,1) = -T;
        }
        else if (j == 2) {
            // Derivative wrt a
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 3) {
            // Derivative wrt T
            jac_(0,0) = 0.0;
            jac_(0,1) = 1.0;
            jac_(1,0) =  -3.0*pow(Zlags_(0,0),2.0)*epsilon-1.0;
            jac_(1,1) = -epsilon;
        }
    }
}


//
// wn2_hess_times_v
//
// This function computes the Hessian of the vector field
// with respect to the k1-th and k2-th delayed state vectors,
// then multiplies this by the m-th column of v to obtain a matrix.
//

static inline void wn2_hess_times_v(Matrix& jac_, double t, int k1, int k2, int m, const Matrix& v_, const Matrix& Zlags_, const Vector& par_)
{
    const double Pi = M_PI;

    // Parameters
    const double epsilon    = par_(1);
    const double a          = par_(2);
    const double T          = par_(3);

    if (k1 == 0) {
        // Derivatives wrt the state variables
        if (k2 == 0) {
            // Derivatives wrt the state variables
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = (-6.0*Zlags_(0,0)*T*epsilon)*v_(0,m);
            jac_(1,1) = 0.0;
        }
    }
}

//
// sys_deri(...)
//
// The lags are: {}
//
// If X(t) is the state vector at time t, then
//    Zlags_ = [ X(t)  ]
//
// The state vector:
// x          = Zlags_(0,0);
// y          = Zlags_(1,0);
//
//
void sys_deri(Matrix& jac_, double t, const Matrix& Zlags_, const Vector& par_, int nx_, const int* vx_, int np_, const int* vp_, const Matrix& v_)
{
    if (nx_ == 1 && np_ == 0) {
        wn2_jacx(jac_, t, vx_[0], Zlags_, par_);
    }
    else if (nx_ == 0 && np_ == 1) {
        wn2_jacp(jac_, t, vp_[0], Zlags_, par_);
    }
    else if (nx_ == 1 && np_ == 1) {
        wn2_jacxp(jac_, t, vx_[0], vp_[0], Zlags_, par_);
    }
    else if (nx_ == 2 && np_ == 0) {
        wn2_hess_times_v(jac_, t, vx_[0], vx_[1], vx_[0], v_, Zlags_, par_);
    }
    else {
        std::cerr << "sys_deri: Requested derivative has not been implemented.\n";
        exit(-1);
    }
    return;
}

//
// sys_tau(...) computes the vector of delays.
//

void sys_tau(Vector& out, double t, const Vector& par_)
{
    const double Pi = M_PI;
    // par_(0) is the period.
    const double epsilon    = par_(1);
    const double a          = par_(2);
    const double T          = par_(3);

    out(0) = 0.0;
}

//
// sys_dtau(...) computes the derivatives of the delays with respect to the parameters.
//
// The delays are: 
//

void sys_dtau(Vector& out, double t, const Vector& par_, int p_)
{
    const double Pi = M_PI;
    // par_(0) is the period.
    const double epsilon    = par_(1);
    const double a          = par_(2);
    const double T          = par_(3);

    out(0) = 0.0;
    if (p_ == 0) {
    }
    else if (p_ == 1) {
        // Derivative wrt epsilon
    }
    else if (p_ == 2) {
        // Derivative wrt a
    }
    else if (p_ == 3) {
        // Derivative wrt T
    }
}

void sys_stpar(Vector& par_)
{
    const double Pi = M_PI;
    // VFGEN used the DefaultValues of the Parameters.
    // Change the following values to match your known solution.
    par_(0) = 1.0;
    par_(1) = 1.0000000000000001e-01;
    par_(2) = 5.0;
    par_(3) = 2.0*Pi;
}

void sys_stsol(Vector& out, double t)
{
    const double Pi = M_PI;
    // VFGEN used the DefaultInitialConditions of the StateVariables.
    // Change the following values to implement your known solution.
    out(0) = 1.85*cos(t-0.34);
    out(1) = 1.79*cos(t+1.2);
}

}  // extern "C"
