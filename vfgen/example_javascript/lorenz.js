/*
 *  lorenz.js
 *
 *  Javascript code with functions for computing the Taylor series approximate solutions
 *  for the vector field named: lorenz
 *  
 *  This file was generated by the program VFGEN, version: 2.5.0-dev
 *  Generated on 14-May-2014 at 21:03
 */

/*
 *  Make several Math functions available without the Math prefix.
 */
acos  = Math.acos
asin  = Math.asin
atan  = Math.atan
atan2 = Math.atan2
cos   = Math.cos
exp   = Math.exp
log   = Math.log
pow   = Math.pow
sin   = Math.sin
sqrt  = Math.sqrt
tan   = Math.tan

/*
 *  The vector field.
 */

function lorenz_vf(t, y_, params)
{
    var x          = y_[0];
    var y          = y_[1];
    var z          = y_[2];

    var sigma      = params[0];
    var rho        = params[1];
    var beta       = params[2];

    var f_ = [];
    f_[0] = -( x-y)*sigma;
    f_[1] =  x*rho-y-z*x;
    f_[2] = -z*beta+x*y;

    return f_;
}


/*
 *     deriv = Df(x)[v1]
 */
function lorenz_diff1(x_, p_,v1_)
{
    var x          = x_[0];
    var y          = x_[1];
    var z          = x_[2];

    var sigma      = p_[0];
    var rho        = p_[1];
    var beta       = p_[2];

    var deriv = [];
    /*
     *  Partial derivatives of vf[0]. 
     *  Any derivative not listed here is zero.
     */
    var vf_x = -sigma;
    var vf_y = sigma;
    deriv[0] = 0.0;
    deriv[0] += vf_x * v1_[0];
    deriv[0] += vf_y * v1_[1];
    /*
     *  Partial derivatives of vf[1]. 
     *  Any derivative not listed here is zero.
     */
    var vf_x = -z+rho;
    var vf_y = -1.0;
    var vf_z = -x;
    deriv[1] = 0.0;
    deriv[1] += vf_x * v1_[0];
    deriv[1] += vf_y * v1_[1];
    deriv[1] += vf_z * v1_[2];
    /*
     *  Partial derivatives of vf[2]. 
     *  Any derivative not listed here is zero.
     */
    var vf_x = y;
    var vf_y = x;
    var vf_z = -beta;
    deriv[2] = 0.0;
    deriv[2] += vf_x * v1_[0];
    deriv[2] += vf_y * v1_[1];
    deriv[2] += vf_z * v1_[2];

    return deriv;
}

/*
 *     deriv = D^2f(x)[v1,v2]
 */
function lorenz_diff2(x_, p_,v1_,v2_)
{
    var x          = x_[0];
    var y          = x_[1];
    var z          = x_[2];

    var sigma      = p_[0];
    var rho        = p_[1];
    var beta       = p_[2];

    var deriv = [];
    /*
     *  Partial derivatives of vf[0]. 
     *  Any derivative not listed here is zero.
     */
    deriv[0] = 0.0;
    /*
     *  Partial derivatives of vf[1]. 
     *  Any derivative not listed here is zero.
     */
    var vf_x_z = -1.0;
    deriv[1] = 0.0;
    deriv[1] += vf_x_z * v1_[0]*v2_[2];
    deriv[1] += vf_x_z * v1_[2]*v2_[0];
    /*
     *  Partial derivatives of vf[2]. 
     *  Any derivative not listed here is zero.
     */
    var vf_x_y = 1.0;
    deriv[2] = 0.0;
    deriv[2] += vf_x_y * v1_[0]*v2_[1];
    deriv[2] += vf_x_y * v1_[1]*v2_[0];

    return deriv;
}

/*
 *     deriv = D^3f(x)[v1,v2,v3]
 */
function lorenz_diff3(x_, p_,v1_,v2_,v3_)
{
    var x          = x_[0];
    var y          = x_[1];
    var z          = x_[2];

    var sigma      = p_[0];
    var rho        = p_[1];
    var beta       = p_[2];

    var deriv = [];
    /*
     *  Partial derivatives of vf[0]. 
     *  Any derivative not listed here is zero.
     */
    deriv[0] = 0.0;
    /*
     *  Partial derivatives of vf[1]. 
     *  Any derivative not listed here is zero.
     */
    deriv[1] = 0.0;
    /*
     *  Partial derivatives of vf[2]. 
     *  Any derivative not listed here is zero.
     */
    deriv[2] = 0.0;

    return deriv;
}

/*
 *     deriv = D^4f(x)[v1,...,v4]
 */
function lorenz_diff4(x_, p_,v1_,v2_,v3_,v4_)
{
    var x          = x_[0];
    var y          = x_[1];
    var z          = x_[2];

    var sigma      = p_[0];
    var rho        = p_[1];
    var beta       = p_[2];

    var deriv = [];
    /*
     *  Partial derivatives of vf[0]. 
     *  Any derivative not listed here is zero.
     */
    deriv[0] = 0.0;
    /*
     *  Partial derivatives of vf[1]. 
     *  Any derivative not listed here is zero.
     */
    deriv[1] = 0.0;
    /*
     *  Partial derivatives of vf[2]. 
     *  Any derivative not listed here is zero.
     */
    deriv[2] = 0.0;

    return deriv;
}

/*
 *     deriv = D^5f(x)[v1,...,v5]
 */
function lorenz_diff5(x_, p_,v1_,v2_,v3_,v4_,v5_)
{
    var x          = x_[0];
    var y          = x_[1];
    var z          = x_[2];

    var sigma      = p_[0];
    var rho        = p_[1];
    var beta       = p_[2];

    var deriv = [];
    /*
     *  Partial derivatives of vf[0]. 
     *  Any derivative not listed here is zero.
     */
    deriv[0] = 0.0;
    /*
     *  Partial derivatives of vf[1]. 
     *  Any derivative not listed here is zero.
     */
    deriv[1] = 0.0;
    /*
     *  Partial derivatives of vf[2]. 
     *  Any derivative not listed here is zero.
     */
    deriv[2] = 0.0;

    return deriv;
}

/*
 *     deriv = D^6f(x)[v1,...,v6]
 */
function lorenz_diff6(x_, p_,v1_,v2_,v3_,v4_,v5_,v6_)
{
    var x          = x_[0];
    var y          = x_[1];
    var z          = x_[2];

    var sigma      = p_[0];
    var rho        = p_[1];
    var beta       = p_[2];

    var deriv = [];
    /*
     *  Partial derivatives of vf[0]. 
     *  Any derivative not listed here is zero.
     */
    deriv[0] = 0.0;
    /*
     *  Partial derivatives of vf[1]. 
     *  Any derivative not listed here is zero.
     */
    deriv[1] = 0.0;
    /*
     *  Partial derivatives of vf[2]. 
     *  Any derivative not listed here is zero.
     */
    deriv[2] = 0.0;

    return deriv;
}

/*
 *  lorenz_derivs7
 *
 *  Compute the coefficients in the Taylor polynomial at X.
 *  These are just the derivatives; they have not been scaled
 *  by the appropriate factorial.
 *
 */

function lorenz_derivs7(X, params)
{
    var i;
    var s;
    var Q = [];

    var Xderiv = [];
    Xderiv[0] = lorenz_vf(0.0,X,params);

    Xderiv[1] = []
    for (i = 0; i < 3; ++i) {
        Xderiv[1][i] = 0.0;
    }
    /*    [ 1]  coeff = 1.  */
    Q = lorenz_diff1(X, params, Xderiv[0]);
    for (i = 0; i < 3; ++i) {
        Xderiv[1][i] += Q[i];
    }

    Xderiv[2] = []
    for (i = 0; i < 3; ++i) {
        Xderiv[2][i] = 0.0;
    }
    /*    [ 0 1]  coeff = 1.  */
    Q = lorenz_diff1(X, params, Xderiv[1]);
    for (i = 0; i < 3; ++i) {
        Xderiv[2][i] += Q[i];
    }
    /*    [ 2]  coeff = 1.  */
    Q = lorenz_diff2(X, params, Xderiv[0], Xderiv[0]);
    for (i = 0; i < 3; ++i) {
        Xderiv[2][i] += Q[i];
    }

    Xderiv[3] = []
    for (i = 0; i < 3; ++i) {
        Xderiv[3][i] = 0.0;
    }
    /*    [ 0 0 1]  coeff = 1.  */
    Q = lorenz_diff1(X, params, Xderiv[2]);
    for (i = 0; i < 3; ++i) {
        Xderiv[3][i] += Q[i];
    }
    /*    [ 1 1]  coeff = 3.  */
    Q = lorenz_diff2(X, params, Xderiv[0], Xderiv[1]);
    for (i = 0; i < 3; ++i) {
        Xderiv[3][i] += 3.*Q[i];
    }
    /*    [ 3]  coeff = 1.  */
    Q = lorenz_diff3(X, params, Xderiv[0], Xderiv[0], Xderiv[0]);
    for (i = 0; i < 3; ++i) {
        Xderiv[3][i] += Q[i];
    }

    Xderiv[4] = []
    for (i = 0; i < 3; ++i) {
        Xderiv[4][i] = 0.0;
    }
    /*    [ 0 0 0 1]  coeff = 1.  */
    Q = lorenz_diff1(X, params, Xderiv[3]);
    for (i = 0; i < 3; ++i) {
        Xderiv[4][i] += Q[i];
    }
    /*    [ 1 0 1]  coeff = 4.  */
    Q = lorenz_diff2(X, params, Xderiv[0], Xderiv[2]);
    for (i = 0; i < 3; ++i) {
        Xderiv[4][i] += 4.*Q[i];
    }
    /*    [ 0 2]  coeff = 3.  */
    Q = lorenz_diff2(X, params, Xderiv[1], Xderiv[1]);
    for (i = 0; i < 3; ++i) {
        Xderiv[4][i] += 3.*Q[i];
    }
    /*    [ 2 1]  coeff = 6.  */
    Q = lorenz_diff3(X, params, Xderiv[0], Xderiv[0], Xderiv[1]);
    for (i = 0; i < 3; ++i) {
        Xderiv[4][i] += 6.*Q[i];
    }
    /*    [ 4]  coeff = 1.  */
    Q = lorenz_diff4(X, params, Xderiv[0], Xderiv[0], Xderiv[0], Xderiv[0]);
    for (i = 0; i < 3; ++i) {
        Xderiv[4][i] += Q[i];
    }

    Xderiv[5] = []
    for (i = 0; i < 3; ++i) {
        Xderiv[5][i] = 0.0;
    }
    /*    [ 0 0 0 0 1]  coeff = 1.  */
    Q = lorenz_diff1(X, params, Xderiv[4]);
    for (i = 0; i < 3; ++i) {
        Xderiv[5][i] += Q[i];
    }
    /*    [ 1 0 0 1]  coeff = 5.  */
    Q = lorenz_diff2(X, params, Xderiv[0], Xderiv[3]);
    for (i = 0; i < 3; ++i) {
        Xderiv[5][i] += 5.*Q[i];
    }
    /*    [ 0 1 1]  coeff = 10.  */
    Q = lorenz_diff2(X, params, Xderiv[1], Xderiv[2]);
    for (i = 0; i < 3; ++i) {
        Xderiv[5][i] += 10.*Q[i];
    }
    /*    [ 2 0 1]  coeff = 10.  */
    Q = lorenz_diff3(X, params, Xderiv[0], Xderiv[0], Xderiv[2]);
    for (i = 0; i < 3; ++i) {
        Xderiv[5][i] += 10.*Q[i];
    }
    /*    [ 1 2]  coeff = 15.  */
    Q = lorenz_diff3(X, params, Xderiv[0], Xderiv[1], Xderiv[1]);
    for (i = 0; i < 3; ++i) {
        Xderiv[5][i] += 15.*Q[i];
    }
    /*    [ 3 1]  coeff = 10.  */
    Q = lorenz_diff4(X, params, Xderiv[0], Xderiv[0], Xderiv[0], Xderiv[1]);
    for (i = 0; i < 3; ++i) {
        Xderiv[5][i] += 10.*Q[i];
    }
    /*    [ 5]  coeff = 1.  */
    Q = lorenz_diff5(X, params, Xderiv[0], Xderiv[0], Xderiv[0], Xderiv[0], Xderiv[0]);
    for (i = 0; i < 3; ++i) {
        Xderiv[5][i] += Q[i];
    }

    Xderiv[6] = []
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] = 0.0;
    }
    /*    [ 0 0 0 0 0 1]  coeff = 1.  */
    Q = lorenz_diff1(X, params, Xderiv[5]);
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] += Q[i];
    }
    /*    [ 1 0 0 0 1]  coeff = 6.  */
    Q = lorenz_diff2(X, params, Xderiv[0], Xderiv[4]);
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] += 6.*Q[i];
    }
    /*    [ 0 1 0 1]  coeff = 15.  */
    Q = lorenz_diff2(X, params, Xderiv[1], Xderiv[3]);
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] += 15.*Q[i];
    }
    /*    [ 2 0 0 1]  coeff = 15.  */
    Q = lorenz_diff3(X, params, Xderiv[0], Xderiv[0], Xderiv[3]);
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] += 15.*Q[i];
    }
    /*    [ 0 0 2]  coeff = 10.  */
    Q = lorenz_diff2(X, params, Xderiv[2], Xderiv[2]);
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] += 10.*Q[i];
    }
    /*    [ 1 1 1]  coeff = 60.  */
    Q = lorenz_diff3(X, params, Xderiv[0], Xderiv[1], Xderiv[2]);
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] += 60.*Q[i];
    }
    /*    [ 3 0 1]  coeff = 20.  */
    Q = lorenz_diff4(X, params, Xderiv[0], Xderiv[0], Xderiv[0], Xderiv[2]);
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] += 20.*Q[i];
    }
    /*    [ 0 3]  coeff = 15.  */
    Q = lorenz_diff3(X, params, Xderiv[1], Xderiv[1], Xderiv[1]);
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] += 15.*Q[i];
    }
    /*    [ 2 2]  coeff = 45.  */
    Q = lorenz_diff4(X, params, Xderiv[0], Xderiv[0], Xderiv[1], Xderiv[1]);
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] += 45.*Q[i];
    }
    /*    [ 4 1]  coeff = 15.  */
    Q = lorenz_diff5(X, params, Xderiv[0], Xderiv[0], Xderiv[0], Xderiv[0], Xderiv[1]);
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] += 15.*Q[i];
    }
    /*    [ 6]  coeff = 1.  */
    Q = lorenz_diff6(X, params, Xderiv[0], Xderiv[0], Xderiv[0], Xderiv[0], Xderiv[0], Xderiv[0]);
    for (i = 0; i < 3; ++i) {
        Xderiv[6][i] += Q[i];
    }

    return Xderiv;
}

/*
 *  lorenz_evaltaylor7
 *
 *  Use the Taylor method to approximate X(t+h) given X(t).
 *  This function uses a Taylor polynomial of order 7.
 *  Xderiv must be created by calling lorenz_derivs7(...).
 */

function lorenz_evaltaylor7(h, X, Xderiv)
{
    var i;
    var s;
    var Xnew = X
    s = h;
    /* Add order 1 term to Xnew */
    for (i = 0; i < 3; ++i) {
        Xnew[i] += (1.0/1.0)*Xderiv[0][i]*s;
    }
    s = s * h;
    /* Add order 2 term to Xnew */
    for (i = 0; i < 3; ++i) {
        Xnew[i] += (1.0/2.0)*Xderiv[1][i]*s;
    }
    s = s * h;
    /* Add order 3 term to Xnew */
    for (i = 0; i < 3; ++i) {
        Xnew[i] += (1.0/6.0)*Xderiv[2][i]*s;
    }
    s = s * h;
    /* Add order 4 term to Xnew */
    for (i = 0; i < 3; ++i) {
        Xnew[i] += (1.0/24.0)*Xderiv[3][i]*s;
    }
    s = s * h;
    /* Add order 5 term to Xnew */
    for (i = 0; i < 3; ++i) {
        Xnew[i] += (1.0/120.0)*Xderiv[4][i]*s;
    }
    s = s * h;
    /* Add order 6 term to Xnew */
    for (i = 0; i < 3; ++i) {
        Xnew[i] += (1.0/720.0)*Xderiv[5][i]*s;
    }
    s = s * h;
    /* Add order 7 term to Xnew */
    for (i = 0; i < 3; ++i) {
        Xnew[i] += (1.0/5040.0)*Xderiv[6][i]*s;
    }
    return Xnew;
}