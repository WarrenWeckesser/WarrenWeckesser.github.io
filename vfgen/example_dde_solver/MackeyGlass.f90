!
! MackeyGlass.f90
!
! Vector field function for: MackeyGlass
! These functions are to be used with DDE_SOLVER_M.
!
! This file was generated by the program VFGEN, version: 2.5.0-dev
! Generated on 14-May-2014 at 21:03
!
!
! The lags are: {tau}

MODULE DEFINE_MackeyGlass_DDEs

    IMPLICIT NONE
    INTEGER, PARAMETER :: NEQN=1, NLAGS=1
    ! Parameters
    DOUBLE PRECISION a, b, tau

CONTAINS

    SUBROUTINE MackeyGlass_ddes(t,x_,Zlags_,vf_)
    ! Arguments
    DOUBLE PRECISION :: t
    DOUBLE PRECISION, DIMENSION(NEQN) :: x_, vf_
    DOUBLE PRECISION, DIMENSION(NEQN,NLAGS) :: Zlags_
    INTENT(IN) :: t, x_, Zlags_
    INTENT(OUT) :: vf_
    ! Local variables
    DOUBLE PRECISION delayedx
    DOUBLE PRECISION x
    ! State variables
    x          = x_(1)
    ! Expressions
    delayedx = Zlags_(1,1)

    ! The vector field
    vf_(1) =  a/( delayedx**(10.0)+1.0)*delayedx-x*b


    RETURN
    END SUBROUTINE MackeyGlass_ddes

    SUBROUTINE MackeyGlass_history(t,x_)
    DOUBLE PRECISION :: t
    DOUBLE PRECISION, DIMENSION(NEQN) :: x_
    INTENT(IN) :: t
    INTENT(OUT) :: x_

    x_(1) =  2.0000000000000000e-02*t+5.0000000000000000e-01


    RETURN
    END SUBROUTINE MackeyGlass_history

END MODULE DEFINE_MackeyGlass_DDEs