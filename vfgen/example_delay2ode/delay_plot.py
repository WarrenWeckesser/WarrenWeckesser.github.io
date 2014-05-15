
from numpy import loadtxt
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

data = loadtxt('outp2n12.dat')
t      = data[:,0]
x      = data[:,1]
xdelay = data[:,24]

plt.figure(figsize=(6, 4.5)).subplots_adjust(bottom=0.12)

plt.xlabel('t')
plt.grid(True)
plt.hold(True)

lw = 1.5
plt.plot(t,x, 'b', linewidth=lw)
plt.plot(t,xdelay, 'g', linewidth=lw)

plt.ylim(ymin=0.75, ymax=3.25)

plt.legend((r'$x(t)$', r'$x(t-1)$'), loc=(.56, .75), prop=FontProperties(size=14), labelspacing=0.3)
plt.savefig('delay_plot_p2n12.png', dpi=72, transparent=True)

# show()


