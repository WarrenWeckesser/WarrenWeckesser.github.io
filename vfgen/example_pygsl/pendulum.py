#
# pendulum.py
#
# Python file for the vector field named: pendulum
# The functions defined here can be used with the ODEIV routines of PyGSL.
#
# This file was generated by the program VFGEN, version: 2.5.0-dev
# Generated on 14-May-2014 at 21:04
#

from math import *
import numpy

#
# The vector field.
#

def vectorfield(t,x_,args):
    """
    The vector field function for the vector field "pendulum"
    """
    Pi = numpy.pi
    theta      = x_[0]
    v          = x_[1]
    g          = args[0]
    b          = args[1]
    L          = args[2]
    m          = args[3]

    f_ = numpy.zeros((2,))
    f_[0] = v
    f_[1] = -sin(theta)/L*g-b/(L*L)*v/m

    return f_

#
#  The Jacobian.
#

def jacobian(t_, y_, args):
    """
    The Jacobian of the vector field "pendulum"
    """
    Pi = numpy.pi
    theta      = y_[0]
    v          = y_[1]
    g          = args[0]
    b          = args[1]
    L          = args[2]
    m          = args[3]

    # Create the Jacobian matrix, initialized with zeros.
    jac_ = numpy.zeros((2,2))
    jac_[0,1] = 1.0
    jac_[1,0] = -cos(theta)/L*g
    jac_[1,1] = -b/(L*L)/m

    dfdt_ = numpy.zeros((2,),dtype=numpy.float)

    return jac_,dfdt_

#
# User function: energy
#

def energy(t_, y_, args):
    """
    The user-defined function "energy" for the vector field "pendulum"
    """
    Pi = numpy.pi
    theta      = y_[0]
    v          = y_[1]
    g          = args[0]
    b          = args[1]
    L          = args[2]
    m          = args[3]

    return -cos(theta)*L*m*g+(L*L)*(v*v)*m/2.0
