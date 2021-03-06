%
% pendulum_jac.m
%
% This MATLAB function computes the Jacobian of the vector field
% defined in pendulum_vf.m.
%
% This file was generated by the program VFGEN, version: 2.5.0-dev
% Generated on 14-May-2014 at 21:03
%
%
function jac_ = pendulum_jac(t,x_,p_)
    Pi = pi;
    theta      = x_(1);
    v          = x_(2);
    g          = p_(1);
    b          = p_(2);
    L          = p_(3);
    m          = p_(4);
    jac_ = zeros(2,2);
    jac_(1,2) = 1;
    jac_(2,1) = -cos(theta)*L^(-1)*g;
    jac_(2,2) = -b*L^(-2)*m^(-1);

