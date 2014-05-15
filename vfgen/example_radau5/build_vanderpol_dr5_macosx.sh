# Mac OSX  build commands, using gfortran:

gfortran -c radau5.f
gfortran -c dc_lapack.f
gfortran -c vanderpol_rhs.f
gfortran -c vanderpol_dr5.f
gfortran vanderpol_dr5.o vanderpol_rhs.o radau5.o dc_lapack.o -framework vecLib -o vanderpol_dr5
