#
# File:   MorrisLecar_cont.py
# Author: Warren Weckesser, www.warrenweckesser.net
#

import matplotlib.pyplot as plt
import PyDSTool
import MorrisLecar

# Use the function created by VFGEN to define the 'args' object for
# the Morris-Lecar system.
ds = MorrisLecar.args()

# Set ics to (1.5,0).  This is not an equilibrium point, but
# with these values, the PyCont code will find one.
ds.ics = {'v': 1.5, 'w': 0.0}

ode = PyDSTool.Generator.Vode_ODEsystem(ds)

cont = PyDSTool.ContClass(ode)

print "Setting up for one parameter continuation of an equilibrium point."
PCargs = PyDSTool.args(name='EQ1', type='EP-C')
PCargs.freepars = ['ic']
PCargs.StepSize = 1e-3
PCargs.MaxNumPoints = 200
PCargs.MaxStepSize = 0.2
PCargs.LocBifPoints = ['LP', 'H', 'BP']

print "Computing the curve."
cont.newCurve(PCargs)
cont['EQ1'].forward()

print "Setting up for two parameter continuation of the Hopf point."
PCargs = PyDSTool.args(name='Hopf', type='H-C2')
PCargs.initpoint = 'EQ1:H1'
PCargs.freepars = ['ic', 'gca']
PCargs.MaxStepSize = 1.0
PCargs.LocBifPoints = ['GH', 'BT', 'ZH']
PCargs.MaxNumPoints = 400

print "Computing the curve."
cont.newCurve(PCargs)
print "...forward"
cont['Hopf'].forward()
cont['Hopf'].MaxNumPoints = 75
print "...backward"
cont['Hopf'].backward()

print "Setting up for two parameter continuation of the first limit point."
PCargs = PyDSTool.args(name='SN', type='LP-C')
PCargs.initpoint = 'EQ1:LP1'
PCargs.freepars = ['ic', 'gca']
PCargs.MaxStepSize = 1.0
PCargs.LocBifPoints = ['CP', 'BT', 'ZH']
PCargs.MaxNumPoints = 100

print "Computing the curve."
cont.newCurve(PCargs)
print "...forward"
cont['SN'].forward()
print "...backward"
cont['SN'].backward()

print "Generating the plot in MorrisLecar_cont.png."
cont['Hopf'].display(('ic', 'gca'))
cont['SN'].display(('ic', 'gca'))
cont.plot.fig1.toggleAll('off', bytype='P')
plt.axis([40, 200, 3, 9])
plt.title('Morris-Lecar Bifurcation Diagram')
plt.grid(True)
plt.legend()
plt.savefig('MorrisLecar_cont.png', dpi=72)
#plt.show()
