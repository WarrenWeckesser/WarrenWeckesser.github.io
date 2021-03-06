c
c vanderpol_demo.f
c
c Fortran 77 program that uses LSODA to solve the differential equations
c defined in the vector field 'vanderpol'
c
c This file was generated by the program VFGEN, version: 2.5.0-dev
c Generated on 14-May-2014 at 21:03
c
      program vanderpol

      implicit none

      external vanderpol_rhs
      external vanderpol_jac

      double precision atol_, rtol_, y_, t_, tout_, tfinal_, rwork_
      integer iwork_
      dimension y_(3), rwork_(52), iwork_(22)
      integer neq_, i_, j_, nsteps_
      integer itol_, iopt_, itask_, istate_, jt_, lrw_, liw_
      double precision epsilon
      double precision x, y
c     --- t range ---
      t_ = 0.0D0
      tfinal_  = 10.0D0
      nsteps_ = 100
c     --- Parameters ---
      epsilon = 2.0000000000000001D-01
      y_(3) = epsilon
c     --- Initial conditions ---
      x = 1.0000000000000000D-02
      y = 0.0D0
      y_(1) = x
      y_(2) = y
c     --- Solver tolerances ---
      rtol_ = 1.0D-6
      atol_ = 1.0D-8
      itol_ = 1
c     --- Other LSODA parameters ---
      neq_ = 2
      itask_ = 1
      istate_ = 1
      iopt_ = 0
      lrw_ = 52
      liw_ = 22
c
c     LSODE and LSODA take the same arguments, so either may
c     be used in the loop below.  jt_ must be set as follows:
c     jt_ =  1 for LSODA
c     jt_ = 10 for LSODE, non-stiff (Adams) method
c     jt_ = 21 for LSODE, stiff (BDF) method
c     See the documentation in the Fortran file for more details.
      jt_ = 1
c     --- Print the first point ---
      write (6,49) t_, (y_(j_), j_ = 1,2)
c     --- Call DLSODA in a loop to compute the solution ---
      do 40 i_ = 1,nsteps_
          tout_ = (i_*tfinal_)/nsteps_
          call DLSODA(vanderpol_rhs, neq_, y_, t_, tout_,
     &           itol_, rtol_, atol_, itask_, istate_, iopt_,
     &           rwork_, lrw_, iwork_, liw_,
     &           vanderpol_jac, jt_)
          if (istate_ .lt. 0) goto 80
40        write (6,49) t_, (y_(j_), j_ = 1,2)
49        format(1X,F10.6,2E18.10)
      stop
80    write (6,89) istate_
89    format(1X,"Error: istate=",I3)
      stop
      end

