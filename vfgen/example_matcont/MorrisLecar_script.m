%
% File:   MorrisLecar_script.m
% Author: Warren Weckesser
% 

% init
global cds
% gca,gk,gl,vca,vk,vl,c,phi,ic,v1,v2,v3,v4
gca = 5.5;
gk  = 8.0;
gl  = 2.0;
vca = 115.0;
vk  = -84.0;
vl  = -55.0;
c   = 20.0;
phi = 0.22;
ic  = 90.0;
v1  = -1.2;
v2  = 18.0;
v3  = 2.0;
v4  = 30.0;
p = zeros(13,1);
p(1) = gca;
p(2) = gk;
p(3) = gl;
p(4) = vca;
p(5) = vk;
p(6) = vl;
p(7) = c;
p(8) = phi;
p(9) = ic;
p(10) = v1;
p(11) = v2;
p(12) = v3;
p(13) = v4;

ap=9;
[x0,v0] = init_EP_EP(@MorrisLecar,[1.3;0],p',ap);
opt=contset;
opt = contset(opt,'MaxNumPoints',200);
% opt = contset(opt,'Userfunctions',1); 
opt = contset(opt,'Singularities',1);
% UserInfo.name = 'userf1'; UserInfo.state=1; UserInfo.label='u1';
% opt=contset(opt,'UserfunctionsInfo',UserInfo);
[x,v,s,h,f] = cont(@equilibrium,x0,[],opt);
[x,v,s,h,f] = cont(x,v,s,h,f,cds);
figure(1)
cpl(x,v,s,[3 1]);
xlabel('ic')
ylabel('x')
title('x coordinate of equilibrium solutions')
%
x1 = x(1:2,s(2).index);
p(ap)=x(3,s(2).index);
ap2 = [9 1];
[x0,v0] = init_LP_LP(@MorrisLecar,x1,p,ap2);
opt = contset;
opt = contset(opt,'MaxNumPoints',800);
opt = contset(opt,'Singularities',1);
[x1,v1,s1,h1,f1] = cont(@limitpoint,x0,v0,opt);
figure(2)
cpl(x1,v1,s1,[3 4]);
opt = contset(opt,'Backward',1);
[x2,v2,s2] = cont(@limitpoint,x0,v0,opt);
cpl(x2,v2,s2,[3 4]);
%
xh = x(1:2,s(3).index);
p(ap) = x(3,s(3).index);
[x3_0,v3_0] = init_H_H(@MorrisLecar,xh,p,ap2);
opt = contset;
opt = contset(opt,'MaxNumPoints',3000);
opt = contset(opt,'Singularities',1);
[x3,v3,s3,h3,f3] = cont(@hopf,x3_0,v3_0,opt);
cpl(x3,v3,s3,[3 4]);
opt = contset(opt,'Backward',1);
opt = contset(opt,'MaxNumPoints',1000);
[x4,v4,s4] = cont(@hopf,x3_0,v3_0,opt);
cpl(x4,v4,s4,[3 4]);
%
axis([20 200 3 9])
xlabel('ic')
ylabel('gca')

