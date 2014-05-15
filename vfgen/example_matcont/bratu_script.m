%
% bratu_script.m
%
% This MATLAB script contains the commands from Section 7.4
% of the MATCONT manual "MATCONT and CL_MATCONT: Continuation
% Toolboxes in Matlab" (A. Dhooge, et al, December 2006).
% 
% This script assumes that the MATCONT "init" function has
% already been called.
%

global cds
p=0; ap=1;
[x0,v0] = init_EP_EP(@bratu,[0;0],p,ap);
opt=contset;
opt = contset(opt,'MaxNumPoints',50);
opt = contset(opt,'Userfunctions',1); 
opt = contset(opt,'Singularities',1);
UserInfo.name = 'userf1'; UserInfo.state=1; UserInfo.label='u1';
opt=contset(opt,'UserfunctionsInfo',UserInfo);
[x,v,s,h,f] = cont(@equilibrium,x0,[],opt);
[x,v,s,h,f] = cont(x,v,s,h,f,cds);
cpl(x,v,s,[3 1 2]);
x1 = x(1:2,s(6).index); p(ap)=x(3,s(6).index);
[x0,v0] = init_BP_EP(@bratu,x1,p,s(6),0.01);
opt = contset(opt,'MaxNumPoints',50);
[x1,v1,s1] = cont(@equilibrium,x0,[],opt);
cpl(x1,v1,s1,[3 1 2]);
opt = contset(opt,'Backward',1);
[x2,v2,s2] = cont(@equilibrium,x0,[],opt);
cpl(x2,v2,s2,[3 1 2]);
xlabel('a')
ylabel('x')
zlabel('y')
