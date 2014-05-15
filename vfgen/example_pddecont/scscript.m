
%
% File:    scscript.m
% Author:  Warren Weckesser, www.warrenweckesser.net
%
% MATLAB script to plot the results of the PDDE-CONT calculations for the
% Shayer-Campbell system.
%

load('sc-po-a.mat')

% x1 and x2 coordinates of all the solutions

x1a = pdde_prof(1:2:end,:);
x2a = pdde_prof(2:2:end,:);

% Get the values at just the mesh points (and not the collocation points)

x1am = x1a(1:5:end,:);
x2am = x2a(1:5:end,:);

% For each solution, compute max(x1)-min(x1), and the norm.

mxa = zeros(1,size(x1am,2));
nma = mxa;
for j = 1:size(nma,2)
    nma(j) = norm(x1am(:,j));
    mxa(j) = max(x1am(:,j))-min(x1am(:,j));
end

p1a = pdde_par(1,:);
p5a = pdde_par(5,:);

% Repeat for the data in sc-po-b.mat...

load('sc-po-b.mat')

x1b = pdde_prof(1:2:end,:);
x2b = pdde_prof(2:2:end,:);

x1bm = x1b(1:5:end,:);
x2bm = x2b(1:5:end,:);

nmb = zeros(1,size(x1bm,2));
mxb = nmb;

for j = 1:size(nmb,2)
    nmb(j) = norm(x1bm(:,j));
    mxb(j) = max(x1bm(:,j))-min(x1bm(:,j));
end

p1b = pdde_par(1,:);
p5b = pdde_par(5,:);

% Plot the data...

fs = 14;

figure(1)
plot(p5a,mxa,'b')
set(gca,'fontsize',fs)
xlabel('a_2_1')
ylabel('max(x_1)-min(x_1)')
hold on
plot(p5b,mxb,'b')
hold off

figure(2)
plot(p5a,p1a,'b')
set(gca,'fontsize',fs)
xlabel('a_2_1')
ylabel('Period')
hold on
plot(p5b,p1b,'b')
hold off

figure(3)
plot(pdde_mesh(:,end)*p1b(end),x1bm(:,end),'b')
set(gca,'fontsize',fs)
axis([0, p1b(end),-0.5,0.5])
xlabel('t')
ylabel('x_1')
