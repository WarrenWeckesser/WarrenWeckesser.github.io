c
c  rossler_pmap.f
c 
c  by Warren Weckesser, www.warrenweckesser.net
c
c  Fortran 77 program that uses LSODAR to solve the differential equations
c  defined in the vector field 'rossler'.  This program outputs the points
c  where the trajectory crosses the plane y=0 (and x < 0).
c
c
      program rossler_pmap

      implicit none

      external rossler_rhs
      external rossler_jac
      external rossler_func

      double precision atol, rtol, y_, t, tout, tfinal, rwork
      integer iwork
      dimension y_(6), rwork(73), iwork(23)
      integer neq, i, j, nsteps
      integer itol, iopt, itask, istate, jt, lrw, liw
      double precision jroot
      dimension jroot(1)
      double precision a, b, c
      double precision x, y, z
c
      tfinal  = 100.0D0
      nsteps = 500
c     --- Parameters ---
      a = 0.17D0
      b = 0.4D0
      c = 8.5D0
      y_(4) = a
      y_(5) = b
      y_(6) = c
c     --- Initial conditions ---
      x = -10.0D0;
      y = 0.0D0
      z = 1.0D0
      y_(1) = x
      y_(2) = y
      y_(3) = z
c     --- Solver tolerances ---
      rtol = 1.0D-7
      atol = 1.0D-9
      itol = 1
c     --- Other LSODAR parameters ---
      neq = 3
      itask = 1
      iopt = 0
      lrw = 73
      liw = 23
      jt = 1
c     --- Call DLSODAR in a loop to compute the cross-section maps ---
      do 40 i = 1,nsteps
          t    = 0.0D0
          tout = tfinal
          istate = 1
          call DLSODAR(rossler_rhs, neq, y_, t, tout,
     &           itol, rtol, atol, itask, istate, iopt,
     &           rwork, lrw, iwork, liw,
     &           rossler_jac, jt, rossler_func, 1, jroot)
          if (istate .ne. 3) goto 80
          t    = 0.0D0
          tout = tfinal
          istate = 1
          call DLSODAR(rossler_rhs, neq, y_, t, tout,
     &           itol, rtol, atol, itask, istate, iopt,
     &           rwork, lrw, iwork, liw,
     &           rossler_jac, jt, rossler_func, 1, jroot)
          if (istate .ne. 3) goto 80
c         skip the first 20 iterations
          if (i .gt. 20)  write (6,29) (y_(j), j = 1,3)
29        format(1X,F10.6,3E18.10)
40    continue
      stop
80    write (6,89) istate
89    format(1X,"Error: istate=",I3," (did not reach cross-section)")
      stop
      end
