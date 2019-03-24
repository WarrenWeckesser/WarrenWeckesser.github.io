%
% pendulum_energy.m
%
% MATLAB user function for the vector field: pendulum
%
% This file was generated by the program VFGEN, version: 2.5.0-dev
% Generated on 14-May-2014 at 21:03
%
%
function r_ = pendulum_energy(t,x_,p_)
    Pi = pi;
    theta      = x_(1);
    v          = x_(2);
    g          = p_(1);
    b          = p_(2);
    L          = p_(3);
    m          = p_(4);
    r_ = -cos(theta)*L*m*g+1/2*L^2*v^2*m;