//
// sys-ShayerCampbell2000.cpp
//
// PDDE-CONT System Definition file for the VFGEN vector field: ShayerCampbell2000
//
// This file was generated by the program VFGEN, version: 2.5.0-dev
// Generated on 14-May-2014 at 20:11
//

#include <cmath>
#include "pddesys.h"

extern "C" {

int sys_ndim()  { return 2; }  // System dimension
int sys_npar()  { return 8; }  // Number of parameters, plus one (for the period)
int sys_ntau()  { return 4; }  // Number of delays, plus one
int sys_nderi() { return 2; }  // Order of derivatives computed here

//
// sys_rhs(...) computes the vector field.
//
// The lags are: {tau1, tau2, taus}
//
// If X(t) is the state vector at time t, then
//    Zlags_ = [ X(t) X(t-tau1) X(t-tau2) X(t-taus) ]
//
void sys_rhs(Vector& out, double t, const Matrix& Zlags_, const Vector& par_)
{
    // State variables
    const double x1         = Zlags_(0,0);
    const double x2         = Zlags_(1,0);
    // Parameters (par_(0) is the period)
    const double kappa      = par_(1);
    const double beta       = par_(2);
    const double a12        = par_(3);
    const double a21        = par_(4);
    const double tau1       = par_(5);
    const double tau2       = par_(6);
    const double taus       = par_(7);
    // Expressions
    const double x1tau1 = Zlags_(0,1);
    const double x2tau2 = Zlags_(1,2);
    const double x1taus = Zlags_(0,3);
    const double x2taus = Zlags_(1,3);
    // Compute the vector field
    out(0) =  tanh(x2tau2)*a12+beta*tanh(x1taus)-x1*kappa;
    out(1) = -x2*kappa+tanh(x1tau1)*a21+beta*tanh(x2taus);

    return;
}

//
// ShayerCampbell2000_jacx
//
// This function computes the Jacobian of the vector field
// with respect to the k-th delayed vector.
//

static inline void ShayerCampbell2000_jacx(Matrix& jac_, double t, int k, const Matrix& Zlags_, const Vector& par_)
{
    // Parameters
    const double kappa      = par_(1);
    const double beta       = par_(2);
    const double a12        = par_(3);
    const double a21        = par_(4);
    const double tau1       = par_(5);
    const double tau2       = par_(6);
    const double taus       = par_(7);

    if (k == 0) {
        // Derivatives wrt the state variables
        jac_(0,0) = -kappa;
        jac_(0,1) = 0.0;
        jac_(1,0) = 0.0;
        jac_(1,1) = -kappa;
    }
    else if (k == 1) {
        // Derivatives wrt state variables with delay tau1
        jac_(0,0) = 0.0;
        jac_(0,1) = 0.0;
        jac_(1,0) = -( pow(tanh(Zlags_(0,1)),2.0)-1.0)*a21;
        jac_(1,1) = 0.0;
    }
    else if (k == 2) {
        // Derivatives wrt state variables with delay tau2
        jac_(0,0) = 0.0;
        jac_(0,1) = -( pow(tanh(Zlags_(1,2)),2.0)-1.0)*a12;
        jac_(1,0) = 0.0;
        jac_(1,1) = 0.0;
    }
    else if (k == 3) {
        // Derivatives wrt state variables with delay taus
        jac_(0,0) = -beta*( pow(tanh(Zlags_(0,3)),2.0)-1.0);
        jac_(0,1) = 0.0;
        jac_(1,0) = 0.0;
        jac_(1,1) = -beta*( pow(tanh(Zlags_(1,3)),2.0)-1.0);
    }
}


//
// ShayerCampbell2000_jacp
//
// This function computes the Jacobian of the vector field
// with respect to the j-th parameter.
//

static inline void ShayerCampbell2000_jacp(Matrix& jac_, double t, int j, const Matrix& Zlags_, const Vector& par_)
{

    // Parameters
    const double kappa      = par_(1);
    const double beta       = par_(2);
    const double a12        = par_(3);
    const double a21        = par_(4);
    const double tau1       = par_(5);
    const double tau2       = par_(6);
    const double taus       = par_(7);

    if (j == 1) {
        // Derivative wrt kappa
        jac_(0,0) = -Zlags_(0,0);
        jac_(1,0) = -Zlags_(1,0);
    }
    else if (j == 2) {
        // Derivative wrt beta
        jac_(0,0) = tanh(Zlags_(0,3));
        jac_(1,0) = tanh(Zlags_(1,3));
    }
    else if (j == 3) {
        // Derivative wrt a12
        jac_(0,0) = tanh(Zlags_(1,2));
        jac_(1,0) = 0.0;
    }
    else if (j == 4) {
        // Derivative wrt a21
        jac_(0,0) = 0.0;
        jac_(1,0) = tanh(Zlags_(0,1));
    }
    else if (j == 5) {
        // Derivative wrt tau1
        jac_(0,0) = 0.0;
        jac_(1,0) = 0.0;
    }
    else if (j == 6) {
        // Derivative wrt tau2
        jac_(0,0) = 0.0;
        jac_(1,0) = 0.0;
    }
    else if (j == 7) {
        // Derivative wrt taus
        jac_(0,0) = 0.0;
        jac_(1,0) = 0.0;
    }
}


//
// ShayerCampbell2000_jacxp
//
// This function computes the Jacobian of the vector field
// with respect to the k-th delayed state vector and the j-th parameter.
//

static inline void ShayerCampbell2000_jacxp(Matrix& jac_, double t, int k, int j, const Matrix& Zlags_, const Vector& par_)
{

    // Parameters
    const double kappa      = par_(1);
    const double beta       = par_(2);
    const double a12        = par_(3);
    const double a21        = par_(4);
    const double tau1       = par_(5);
    const double tau2       = par_(6);
    const double taus       = par_(7);

    if (k == 0) {
        // Derivatives wrt the state variables
        if (j == 1) {
            // Derivative wrt kappa
            jac_(0,0) = -1.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = -1.0;
        }
        else if (j == 2) {
            // Derivative wrt beta
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 3) {
            // Derivative wrt a12
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 4) {
            // Derivative wrt a21
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 5) {
            // Derivative wrt tau1
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 6) {
            // Derivative wrt tau2
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 7) {
            // Derivative wrt taus
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
    }
    else if (k == 1) {
        // Derivatives wrt state variables with delay tau1
        if (j == 1) {
            // Derivative wrt kappa
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 2) {
            // Derivative wrt beta
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 3) {
            // Derivative wrt a12
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 4) {
            // Derivative wrt a21
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = -pow(tanh(Zlags_(0,1)),2.0)+1.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 5) {
            // Derivative wrt tau1
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 6) {
            // Derivative wrt tau2
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 7) {
            // Derivative wrt taus
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
    }
    else if (k == 2) {
        // Derivatives wrt state variables with delay tau2
        if (j == 1) {
            // Derivative wrt kappa
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 2) {
            // Derivative wrt beta
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 3) {
            // Derivative wrt a12
            jac_(0,0) = 0.0;
            jac_(0,1) = -pow(tanh(Zlags_(1,2)),2.0)+1.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 4) {
            // Derivative wrt a21
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 5) {
            // Derivative wrt tau1
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 6) {
            // Derivative wrt tau2
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 7) {
            // Derivative wrt taus
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
    }
    else if (k == 3) {
        // Derivatives wrt state variables with delay taus
        if (j == 1) {
            // Derivative wrt kappa
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 2) {
            // Derivative wrt beta
            jac_(0,0) = -pow(tanh(Zlags_(0,3)),2.0)+1.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = -pow(tanh(Zlags_(1,3)),2.0)+1.0;
        }
        else if (j == 3) {
            // Derivative wrt a12
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 4) {
            // Derivative wrt a21
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 5) {
            // Derivative wrt tau1
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 6) {
            // Derivative wrt tau2
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (j == 7) {
            // Derivative wrt taus
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
    }
}


//
// ShayerCampbell2000_hess_times_v
//
// This function computes the Hessian of the vector field
// with respect to the k1-th and k2-th delayed state vectors,
// then multiplies this by the m-th column of v to obtain a matrix.
//

static inline void ShayerCampbell2000_hess_times_v(Matrix& jac_, double t, int k1, int k2, int m, const Matrix& v_, const Matrix& Zlags_, const Vector& par_)
{

    // Parameters
    const double kappa      = par_(1);
    const double beta       = par_(2);
    const double a12        = par_(3);
    const double a21        = par_(4);
    const double tau1       = par_(5);
    const double tau2       = par_(6);
    const double taus       = par_(7);

    if (k1 == 0) {
        // Derivatives wrt the state variables
        if (k2 == 0) {
            // Derivatives wrt the state variables
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (k2 == 1) {
            // Derivatives wrt state variables with delay tau1
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (k2 == 2) {
            // Derivatives wrt state variables with delay tau2
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (k2 == 3) {
            // Derivatives wrt state variables with delay taus
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
    }
    else if (k1 == 1) {
        // Derivatives wrt state variables with delay tau1
        if (k2 == 0) {
            // Derivatives wrt the state variables
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (k2 == 1) {
            // Derivatives wrt state variables with delay tau1
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = (2.0*( pow(tanh(Zlags_(0,1)),2.0)-1.0)*tanh(Zlags_(0,1))*a21)*v_(0,m);
            jac_(1,1) = 0.0;
        }
        else if (k2 == 2) {
            // Derivatives wrt state variables with delay tau2
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (k2 == 3) {
            // Derivatives wrt state variables with delay taus
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
    }
    else if (k1 == 2) {
        // Derivatives wrt state variables with delay tau2
        if (k2 == 0) {
            // Derivatives wrt the state variables
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (k2 == 1) {
            // Derivatives wrt state variables with delay tau1
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (k2 == 2) {
            // Derivatives wrt state variables with delay tau2
            jac_(0,0) = 0.0;
            jac_(0,1) = (2.0*( pow(tanh(Zlags_(1,2)),2.0)-1.0)*a12*tanh(Zlags_(1,2)))*v_(1,m);
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (k2 == 3) {
            // Derivatives wrt state variables with delay taus
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
    }
    else if (k1 == 3) {
        // Derivatives wrt state variables with delay taus
        if (k2 == 0) {
            // Derivatives wrt the state variables
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (k2 == 1) {
            // Derivatives wrt state variables with delay tau1
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (k2 == 2) {
            // Derivatives wrt state variables with delay tau2
            jac_(0,0) = 0.0;
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = 0.0;
        }
        else if (k2 == 3) {
            // Derivatives wrt state variables with delay taus
            jac_(0,0) = (2.0*beta*( pow(tanh(Zlags_(0,3)),2.0)-1.0)*tanh(Zlags_(0,3)))*v_(0,m);
            jac_(0,1) = 0.0;
            jac_(1,0) = 0.0;
            jac_(1,1) = (2.0*beta*tanh(Zlags_(1,3))*( pow(tanh(Zlags_(1,3)),2.0)-1.0))*v_(1,m);
        }
    }
}

//
// sys_deri(...)
//
// The lags are: {tau1, tau2, taus}
//
// If X(t) is the state vector at time t, then
//    Zlags_ = [ X(t) X(t-tau1) X(t-tau2) X(t-taus) ]
//
// The state vector:
// x1         = Zlags_(0,0);
// x2         = Zlags_(1,0);
//
//
void sys_deri(Matrix& jac_, double t, const Matrix& Zlags_, const Vector& par_, int nx_, const int* vx_, int np_, const int* vp_, const Matrix& v_)
{
    if (nx_ == 1 && np_ == 0) {
        ShayerCampbell2000_jacx(jac_, t, vx_[0], Zlags_, par_);
    }
    else if (nx_ == 0 && np_ == 1) {
        ShayerCampbell2000_jacp(jac_, t, vp_[0], Zlags_, par_);
    }
    else if (nx_ == 1 && np_ == 1) {
        ShayerCampbell2000_jacxp(jac_, t, vx_[0], vp_[0], Zlags_, par_);
    }
    else if (nx_ == 2 && np_ == 0) {
        ShayerCampbell2000_hess_times_v(jac_, t, vx_[0], vx_[1], vx_[0], v_, Zlags_, par_);
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
    // par_(0) is the period.
    const double kappa      = par_(1);
    const double beta       = par_(2);
    const double a12        = par_(3);
    const double a21        = par_(4);
    const double tau1       = par_(5);
    const double tau2       = par_(6);
    const double taus       = par_(7);

    out(0) = 0.0;
    out(1) = tau1;
    out(2) = tau2;
    out(3) = taus;
}

//
// sys_dtau(...) computes the derivatives of the delays with respect to the parameters.
//
// The delays are: tau1, tau2, taus
//

void sys_dtau(Vector& out, double t, const Vector& par_, int p_)
{
    // par_(0) is the period.
    const double kappa      = par_(1);
    const double beta       = par_(2);
    const double a12        = par_(3);
    const double a21        = par_(4);
    const double tau1       = par_(5);
    const double tau2       = par_(6);
    const double taus       = par_(7);

    out(0) = 0.0;
    if (p_ == 0) {
        out(1) = 0.0;
        out(2) = 0.0;
        out(3) = 0.0;
    }
    else if (p_ == 1) {
        // Derivative wrt kappa
        out(1) = 0.0;
        out(2) = 0.0;
        out(3) = 0.0;
    }
    else if (p_ == 2) {
        // Derivative wrt beta
        out(1) = 0.0;
        out(2) = 0.0;
        out(3) = 0.0;
    }
    else if (p_ == 3) {
        // Derivative wrt a12
        out(1) = 0.0;
        out(2) = 0.0;
        out(3) = 0.0;
    }
    else if (p_ == 4) {
        // Derivative wrt a21
        out(1) = 0.0;
        out(2) = 0.0;
        out(3) = 0.0;
    }
    else if (p_ == 5) {
        // Derivative wrt tau1
        out(1) = 1.0;
        out(2) = 0.0;
        out(3) = 0.0;
    }
    else if (p_ == 6) {
        // Derivative wrt tau2
        out(1) = 0.0;
        out(2) = 1.0;
        out(3) = 0.0;
    }
    else if (p_ == 7) {
        // Derivative wrt taus
        out(1) = 0.0;
        out(2) = 0.0;
        out(3) = 1.0;
    }
}

void sys_stpar(Vector& par_)
{
    // VFGEN used the DefaultValues of the Parameters.
    // Change the following values to match your known solution.
    par_(0) = 1.0;
    par_(1) = 5.0000000000000000e-01;
    par_(2) = 1.0000000000000000e+00;
    par_(3) = 1.0000000000000000e+00;
    par_(4) = 1.0000000000000000e+00;
    par_(5) = 1.0000000000000000e+00;
    par_(6) = 1.0000000000000000e+00;
    par_(7) = 1.0000000000000000e+00;
}

void sys_stsol(Vector& out, double t)
{
    // VFGEN used the DefaultInitialConditions of the StateVariables.
    // Change the following values to implement your known solution.
    out(0) = 1.0000000000000000e+00;
    out(1) = 1.0000000000000000e+00;
}

}  // extern "C"
