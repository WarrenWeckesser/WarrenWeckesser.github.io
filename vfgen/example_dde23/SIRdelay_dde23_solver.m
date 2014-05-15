%
% SIRdelay_dde23_solver.m
%
% MATLAB function for the vector field "SIRdelay"
%
% Copyright (c) 2007 Warren Weckesser, www.warrenweckesser.net
%

%
% This code assumes that stoptime > tau.
%

function SIRdelay_dde23_demo_solver(stoptime)
    alpha = 0.5;
    tau = 4.0;
    p = zeros(2,1);
    p(1) = alpha;
    p(2) = tau;

    lags = [tau];

    %
    % The initial condition is x0 = [S0, In0, R0].
    % This model assumes that for t < 0, S=1, In=0 and R=0. Then, at t=0,
    % S jumps from 1 to S0, and In jumps from 0 to In0.
    %
    x0 = [0.999, 0.001, 0];
    In0 = x0(2);
    %
    % Compute the exact solution for the interval [0,tau].
    %
    xf = SIRdelay_step1sol(tau,In0,p);
    %
    % At t=tau, the initial cohort that was infected at t=0 recovers.
    % This means S and In have discontinuities, which we handle explicitly here.
    %
    xf(2) = xf(2) - In0;
    xf(3) = xf(3) + In0;
    %
    % For t > tau, we use DDE23 to solve the problem.
    %
    % I include a few multiples of tau in the 'Jumps' option, since there
    % will be discontinuities in low order derivatives at the first few
    % multiples of tau.  This appears to make a negligible difference in
    % solution, so the 'Jumps' option could probably be removed.
    %
    opts = ddeset('reltol',1e-8,'abstol',1e-11,'InitialY',xf,'Jumps',[2*tau 3*tau 4*tau]);
    sol = dde23(@(t_,y_,Z_) SIRdelay_dde23(t_,y_,Z_,p),lags,@(t_) SIRdelay_step1sol(t_,In0,p),[tau stoptime],opts);

    %
    % Plot the solution.
    % First create vectors for the solution in the interval [0,tau]
    %
    num_init_samples = 40;
    tt = linspace(0,tau,num_init_samples);
    xx = zeros(3,num_init_samples);
    for k = 1:num_init_samples
        x = SIRdelay_step1sol(tt(k),In0,p);
        xx(:,k) = x;
    end
    %
    % Next get the vector for the solution in the interval [tau,stoptime]
    %
    num_plot_samples = 500;
    tsol = linspace(tau,stoptime,num_plot_samples);
    xsol = deval(sol,tsol);
    %
    % Plot both intervals in one plot.
    %
    clf
    hold on
    lw = 2;
    set(gca,'Fontsize',12,'Fontweight','bold')
    h1 = plot(tt,xx(1,:),'g',tsol,xsol(1,:),'g','linewidth',lw);
    h2 = plot(tt,xx(2,:),'r',tsol,xsol(2,:),'r','linewidth',lw);
    h3 = plot(tt,xx(3,:),'b',tsol,xsol(3,:),'b','linewidth',lw);
    grid on
    xlabel('t');
    legend([h1(1) h2(1) h3(1)],'S','I','R','Location','Best')
    str1 = sprintf('SIR Delay Model (alpha=%g, tau=%g, S(0)=%g, I(0)=%g)', ...
             alpha, tau, x0(1), x0(2));
    title(str1)

    str1 = sprintf('Final values: S(%.1f)=%g, I(%.1f)=%g, R(%.1f)=%g', ...
             stoptime,xsol(1,end),stoptime,xsol(2,end),stoptime,xsol(3,end));
    disp(str1)
end

%
% The exact solution in the interval [0,tau].
%
function x = SIRdelay_step1sol(t,I0,p)
    alpha = p(1);
    tau   = p(2);
    In = I0/(I0+(1-I0)*exp(-alpha*t));
    x = [1-In; In; 0];
end
