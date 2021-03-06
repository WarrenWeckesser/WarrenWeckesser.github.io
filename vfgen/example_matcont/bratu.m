%
% bratu.m
%
% MATLAB file to be used with MATCONT.
%
% This file was generated by the program VFGEN, version: 2.5.0-dev
% Generated on 14-May-2014 at 21:03
%
%
function out = bratu
    out{1} = @bratu_init;
    out{2} = @bratu_vf;
    out{3} = @bratu_jac;
    out{4} = @bratu_jacp;
    out{5} = @bratu_hess;
    out{6} = @bratu_hessp;
    out{7} = @bratu_der3;
    out{8} = [];
    out{9} = [];
    out{10} = @bratu_userf1;

%--------------------------------------------------

function [tspan, y0, options] = bratu_init

    tspan = [0; 10];

    % Get the constants and default parameters, because the default
    % initial conditions can depend on them.
    a = 0;
    % Set the default initial point.
    y0 = zeros(2,1);
    y0(1) = 1;
    y0(2) = 0;

    handles = feval(@bratu);
    options = odeset('Jacobian',handles(3),'JacobianP',handles(4), ...
                     'Hessians',handles(5),'HessiansP',handles(6), ...
                     'Der3',handles(7) );

%--------------------------------------------------
%
% The vector field
%
function vf_ = bratu_vf(t,x_,a)
    x          = x_(1);
    y          = x_(2);

    vf_ = zeros(2,1);
    vf_(1) = a*exp(x)-2*x+y;
    vf_(2) = a*exp(y)+x-2*y;

%--------------------------------------------------
%
% The Jacobian of the vector field with respect to the variables
%
function jac_ = bratu_jac(t,x_,a)
    x          = x_(1);
    y          = x_(2);

    jac_ = zeros(2,2);
    jac_(1,1) = -2+a*exp(x);
    jac_(1,2) = 1;
    jac_(2,1) = 1;
    jac_(2,2) = -2+a*exp(y);

%--------------------------------------------------
%
% The Jacobian of the vector field with respect to the parameters
%
function jacp_ = bratu_jacp(t,x_,a)
    x          = x_(1);
    y          = x_(2);

    jacp_ = zeros(2,1);
    jacp_(1,1) = exp(x);
    jacp_(2,1) = exp(y);

%--------------------------------------------------
%
% The Hessians function.
% This function returns a 3D matrix.
% hess_(n,:,:) is the Hessian of the n-th component of the vector field. That is,
% hess_(n,i,j) is the second partial derivative of the n-th component
% of the vector field, taken with respect to the i-th and j-th variables.
%
function hess_ = bratu_hess(t,x_,a)
    x          = x_(1);
    y          = x_(2);

    hess_ = zeros(2,2,2);

    hess_(1,1,1) = a*exp(x);

    hess_(2,2,2) = a*exp(y);

%--------------------------------------------------
%
% The Hessians with respect to the parameters.
% This function returns a 3D matrix.
% hessp_(n,i,j) is the second partial derivative of the n-th component
% of the vector field, taken with respect to the i-th variable and
% the j-th parameter.
%
function hessp_ = bratu_hessp(t,x_,a)
    x          = x_(1);
    y          = x_(2);

    hessp_ = zeros(2,2,1);

    hessp_(1,1,1) = exp(x);

    hessp_(2,2,1) = exp(y);

%--------------------------------------------------
%
% Third derivatives of the vector field.
% This function returns a 4D matrix.
% der3_(n,i,j,k) is the third partial derivative of the n-th component
% of the vector field, taken with respect to the i-th, j-th and k-th variables.
%
function der3_ = bratu_der3(t,x_,a)
    x          = x_(1);
    y          = x_(2);

    der3_ = zeros(2,2,2,2);

    der3_(1,1,1,1) = a*exp(x);

    der3_(2,2,2,2) = a*exp(y);

%--------------------------------------------------

function r_ = bratu_userf1(t,x_,a)
    x          = x_(1);
    y          = x_(2);
    r_ = -0.2+a;
