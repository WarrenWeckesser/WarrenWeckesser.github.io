
%
% File:    wnscript.m
% Author:  Warren Weckesser, www.warrenweckesser.net
%
% MATLAB script to plot the results of the PDDE-CONT calculations for the
% periodically forced weakly nonlinear system defined in wn2.vf.
%

files = {'wn2a.mat','wn2b.mat','wn2c.mat'}

fs = 14;
lw = 2;
figure(1)
clf
hold on

for k = 1:3
    load(files{k})
    %
    % Pull out the x and y coordinates of all the solutions
    %
    x = pdde_prof(1:2:end,:);
    y = pdde_prof(2:2:end,:);
    %
    % Get the values at just the mesh points (and not the collocation points)
    %
    xm = x(1:4:end,:);
    ym = y(1:4:end,:);
    %
    % For each solution, compute max(x)-min(x).
    %
    num = max(find(pdde_par(1,:)>0));
    mx = zeros(1,num);
    for j = 1:num
        mx(j) = max(xm(:,j))-min(xm(:,j));
    end
    %
    % Plot the result vs. omega
    %
    per = pdde_par(1,1:num);
    plot(1.0 ./ per,mx,'b','linewidth',lw)
end

set(gca,'fontsize',fs)
xlabel('\omega')
ylabel('max(x)-min(x)')
axis([0 3 0 8])
grid on
