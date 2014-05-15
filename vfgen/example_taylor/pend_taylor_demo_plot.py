
from numpy import loadtxt
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

data = loadtxt('demo_gsl.dat')
t      = data[:,0]
theta  = data[:,1]
data = loadtxt('demo3.dat')
t3      = data[:,0]
theta3  = data[:,1]
data = loadtxt('demo7.dat')
t7      = data[:,0]
theta7  = data[:,1]
data = loadtxt('demo15.dat')
t15      = data[:,0]
theta15  = data[:,1]

plt.figure(figsize=(6, 4)).subplots_adjust(bottom=0.12)

plt.xlabel('t')
plt.ylabel(r'$\theta$', fontsize=18)
plt.grid(True)
plt.hold(True)

lw = 1.5
plt.plot(t,theta, 'k--', linewidth=lw)
plt.plot(t3,theta3, 'r', linewidth=lw)
plt.plot(t7,theta7, linewidth=lw, color=(0.6, 0.7, 0))
plt.plot(t15,theta15, linewidth=lw, color=(0.6, 0, 0.6))
plt.xlim(0, 1.0)
plt.ylim(-0.75, 1.25)

plt.legend(('GSL', 'Order 3', 'Order 7', 'Order 15'),
    prop=FontProperties(size=14), loc='lower left')

plt.savefig('pend_taylor_demo.png', dpi=72, transparent=True)
# plt.show()
