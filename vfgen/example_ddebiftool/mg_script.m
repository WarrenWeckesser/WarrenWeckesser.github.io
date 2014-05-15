%
% File:   mg_script.m
% Author: Warren Weckesser
%
% This script uses DDE-BIFTOOL to compute several branches
% of periodic orbits for the Mackey-Glass equations.
%
% First it computes a branch of equilibria (branch1). (This
% is actually an unnecessary computation, since we know that
% x=1 is an equilibrium for all tau.)
%

disp('Setting up starting points.')

[name,n] = sys_init;
stst.kind = 'stst';
stst.parameter = [.2 .1 1];
stst.x = [1];
stst.stability = [];
method = df_mthod('stst');
[stst,success] = p_correc(stst,[],[],method.point);

disp('Computing branch1, the branch of steady state solutions.')

branch1 = df_brnch(3,'stst');
branch1.parameter.max_bound(1,:) = [3 20];
branch1.parameter.max_step(1,:) = [3 0.1];
branch1.point = stst;
stst.parameter(3) = 1.1;
[stst,success] = p_correc(stst,[],[],method.point);
branch1.point(2) = stst;
branch1.method.continuation.plot = 0;
[branch1,s,f,r] = br_contn(branch1,200);

disp('Computing stability of the steady state solutions.')

branch1.method.stability.max_number_of_eigenvalues = 2;
branch1 = br_stabl(branch1,0,1);
[xm,ym] = df_measr(1,branch1);

k = 1;
while (real(branch1.point(k).stability.l0(1)) < 0) & k < length(branch1.point)
    k = k + 1;
end

if (k == length(branch1.point))
    disp('Failed to find the Hopf bifurcation point in branch1.')
    return
end

str = sprintf('Found the Hopf bifurcation near point %d in branch1.',k);
disp(str)

disp('Computing branch2, the periodic orbits that arise from the Hopf point.')

hopf = p_tohopf(branch1.point(k));
method = df_mthod('hopf');
[hopf,success] = p_correc(hopf,3,[],method.point);
intervals = 18;
degree = 3;
[psol,stepcond] = p_topsol(hopf,1e-2,degree,intervals);
method = df_mthod('psol');
[psol,success] = p_correc(psol,3,stepcond,method.point);
branch2 = df_brnch(3,'psol');
branch2.parameter.max_bound(1,:) = [3 20];
branch2.parameter.max_step(1,:) = [3 .02];
deg_psol = p_topsol(hopf,0,degree,intervals);
deg_psol.mesh = [];
branch2.point = deg_psol;
psol.mesh = [];
branch2.point(2) = psol;
branch2.method.continuation.plot = 0;
[branch2,s,f,r] = br_contn(branch2,1000);

disp('Computing stability of the periodic orbits in branch2.')

branch2.method.stability.max_number_of_eigenvalues = 2;
branch2 = br_stabl(branch2,0,1);

disp('Searching for period doubling bifurcation point in branch2.')

k = 1;
q = branch2.point(k).stability.mu;
while (q(1)*q(2) > -1 & k < length(branch2.point))
    k = k + 1;
    q = branch2.point(k).stability.mu;
end

if (k == length(branch2.point))
    disp('Failed to find period doubling point.')
    return
else
    str = sprintf('Period doubling occurs neat point %d of branch2.',k);
    disp(str)
end

% pdsol1 is close to the period-doubling point.
pdsol1 = branch2.point(k);

[pdsol2,stepcond] = p_topsol(pdsol1,1e-2,[]);
[pdsol2,success] = p_correc(pdsol2,3,stepcond,method.point);

[pdsol3,stepcond] = p_topsol(pdsol1,2e-2,[]);
[pdosl3,success] = p_correc(pdsol3,3,stepcond,method.point);

branch3 = df_brnch(3,'psol');
branch3.parameter.max_bound(1,:) = [3 20];
branch3.parameter.max_step(1,:) = [3 .02];

disp('Computing branch3.')

branch3.point = pdsol2;
branch3.point(2) = pdsol3;
branch3.method.continuation.plot = 0;
[branch3,s,f,r] = br_contn(branch3,500);

disp('Computing stability of branch3.');
branch3.method.stability.max_number_of_eigenvalues = 2;
branch3 = br_stabl(branch3,0,1);

disp('Searching for period doubling bifurcation point in branch3.')
k = 1;
q = branch3.point(k).stability.mu;
while (q(1)*q(2) > -1 & k < length(branch2.point))
    k = k + 1;
    q = branch3.point(k).stability.mu;
end

if (k == length(branch3.point))
    disp('Failed to find period doubling point.')
    return
else
    str = sprintf('Period doubling occurs neat point %d of branch3.',k);
    disp(str)
end

% pdsol1 is close to the period-doubling point.
pdsol1 = branch3.point(k);

[pdsol2,stepcond] = p_topsol(pdsol1,1e-2,[]);
[pdsol2,success] = p_correc(pdsol2,3,stepcond,method.point);

[pdsol3,stepcond] = p_topsol(pdsol1,3e-2,[]);
[pdosl3,success] = p_correc(pdsol3,3,stepcond,method.point);

branch4 = df_brnch(3,'psol');
branch4.parameter.max_bound(1,:) = [3 20];
branch4.parameter.max_step(1,:) = [3 .02];

disp('Computing branch4.')

branch4.point = pdsol2;
branch4.point(2) = pdsol3;
branch4.method.continuation.plot = 0;
[branch4,s,f,r] = br_contn(branch4,500);

disp('Plotting all the branches of periodic orbits.')

figure(1)
clf
[xm2,ym2] = df_measr(0,branch2);
br_plot(branch2,xm2,ym2,'b')
[xm3,ym3] = df_measr(0,branch3);
br_plot(branch3,xm3,ym3,'b')
[xm4,ym4] = df_measr(0,branch4);
br_plot(branch4,xm4,ym4,'b')
xlabel('tau')
title('Bifurcation Diagram for the Mackey-Glass equation (a=0.2, b=0.1)')

