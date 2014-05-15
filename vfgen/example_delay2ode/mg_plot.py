
from numpy import loadtxt
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties


data = loadtxt('mg.dat')
t      = data[:,0]
x      = data[:,1]
xdelay = data[:,74]

plt.figure(figsize=(8, 4.5)).subplots_adjust(bottom=0.12)

plt.xlabel('t')
plt.grid(True)
plt.hold(True)

lw = 1.5
plt.plot(t, x, 'b', linewidth=lw)
plt.plot(t, xdelay, 'g', linewidth=lw)

plt.ylim(ymin=0.0, ymax=1.4)

plt.legend((r'$x(t)$', r'$x(t-17)$'), loc='lower right', prop=FontProperties(size=14), labelspacing=0.3)
plt.savefig('mg.png', dpi=72, transparent=True)

# show()
