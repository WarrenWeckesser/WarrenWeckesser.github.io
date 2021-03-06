c
c  AUTO FORTRAN file for the vector field named: vanderpola
c
c  This file was generated by the program VFGEN, version: 2.5.0-dev
c  Generated on 14-May-2014 at 22:51
c
      subroutine func(n_,u_,icp_,par_,ijac_,F_,DFDU_,DFDP_)
      implicit none
      integer n_, icp_, ijac_
      double precision u_, par_, F_, DFDU_, DFDP_
      dimension u_(2), F_(2)
      dimension par_(2)
      dimension DFDU_(2,2), DFDP_(2,2)
      double precision epsilon, a
      double precision x, y

c     --- Parameters ---
      epsilon    = par_(1)
      a          = par_(2)
c     --- State variables ---
      x          = u_(1)
      y          = u_(2)

c     --- The vector field ---
      f_(1) = ( x+-3.3333333333333331D-01*x**(3.0D0)+y)/epsilon
      f_(2) = -x+a

      if (ijac_ .eq. 0) return

c     --- Jacobian ---
      DFDU_(1, 1) = (-x**(2.0D0)+1.0D0)/epsilon
      DFDU_(1, 2) = epsilon**(-1.0D0)
      DFDU_(2, 1) = -1.0D0
      DFDU_(2, 2) = 0.0D0

      if (ijac_ .eq. 1) return

c     --- Derivatives with respect to the parameters ---
      DFDP_(1, 1) = -( x+-3.3333333333333331D-01*x**(3.0D0)+y)/epsilon**
     &(2.0D0)
      DFDP_(1, 2) = 0.0D0
      DFDP_(2, 1) = 0.0D0
      DFDP_(2, 2) = 1.0D0

      return
      end
c
      subroutine stpnt(n_,u_,par_)
      implicit none
      integer n_;
      double precision u_, par_
      dimension u_(2), par_(2)
      double precision epsilon, a
      double precision x, y

c     --- Starting point -- Update these with correct values! ---
      epsilon = 1.0000000000000000D-02
      a = 0.0000000000000000D+00
c
      x = 0.0000000000000000D+00
      y = 0.0000000000000000D+00

      par_(1) = epsilon
      par_(2) = a
      u_(1) = x
      u_(2) = y
c
      return
      end
c
c  The remaining functions are just stubs.
c  You will have to edit these by hand if you need these functions.
c
      subroutine bcnd
      return
      end
c
      subroutine icnd
      return
      end
c
      subroutine fopt
      return
      end
c
      subroutine pvls
      return
      end
