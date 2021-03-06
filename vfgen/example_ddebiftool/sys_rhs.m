%
% sys_rhs.m
%
% DDEBIFTOOL MATLAB vector field function for: mg
%
% This file was generated by the program VFGEN, version: 2.5.0-dev
% Generated on 14-May-2014 at 21:03
%
%
% The lags are: {tau}
%
% If X(t) is the state vector at time t, then
%    Zlags_ = [ X(t) X(t-tau) ]
%
function vf_ = sys_rhs(Zlags_,par_)
    % State variables
    x          = Zlags_(1,1);
    % Parameters
    a          = par_(1);
    b          = par_(2);
    tau        = par_(3);

    delayedx = Zlags_(1,2);
    vf_ = zeros(1,1);
    vf_(1) = delayedx*(1+delayedx^10)^(-1)*a-b*x;

    return
