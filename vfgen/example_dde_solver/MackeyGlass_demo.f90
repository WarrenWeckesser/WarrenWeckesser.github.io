!
! MackeyGlass_demo.f90
!
! Fortran 90 program that will use DDE_SOLVER_M to solve the DDEs defined
! in the vector field: MackeyGlass
!
! This file was generated by the program VFGEN, version: 2.5.0-dev
! Generated on 14-May-2014 at 21:03
!
!

PROGRAM MackeyGlass_demo

USE DEFINE_MackeyGlass_DDEs
USE DDE_SOLVER_M

IMPLICIT NONE

INTEGER, DIMENSION(2) :: NVAR = (/NEQN,NLAGS/)

TYPE(DDE_SOL) :: SOL
TYPE(DDE_OPTS) :: OPTS

DOUBLE PRECISION, DIMENSION(1) :: LAGS
DOUBLE PRECISION, DIMENSION(3) :: p_
DOUBLE PRECISION, DIMENSION(2) :: TSPAN

INTEGER :: I,J
CHARACTER(7+6*NEQN) :: F
DOUBLE PRECISION :: relerr, abserr, stoptime

! Set the parameters of the DDE
a = 2.0000000000000001e-01;
b = 1.0000000000000001e-01;
tau = 1.7000000000000000e+01;
! Set the solver parameters: relative error, abs. error, stop time
relerr = 1D-7
abserr = 1D-9
stoptime = 10.0
p_(1) = a;
p_(2) = b;
p_(3) = tau;
! Initialize the array of lags
LAGS(1) = tau

TSPAN(1) = 0.0
TSPAN(2) = stoptime
OPTS = DDE_SET(RE=relerr,AE=abserr)

SOL = DDE_SOLVER(NVAR,MackeyGlass_ddes,LAGS,MackeyGlass_history,TSPAN,OPTIONS=OPTS)

F = "(E17.8"//REPEAT(",E17.8",NEQN)//")"
DO I = 1, SOL%NPTS
    WRITE(*,FMT=F) SOL%T(I), (SOL%Y(I,J),J=1,NEQN)
END DO

END PROGRAM MackeyGlass_demo