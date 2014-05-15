
# vanderpol_plot.py
#
# Plot the solution to the van der Pol system that was saved in vdp.dat.
# Save the plot in vanderpol_plot.png.
#

from numpy import loadtxt
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties


t, x, y = loadtxt('vdp.dat', unpack=True)

plt.figure(1, figsize=(6, 4)).subplots_adjust(bottom=0.12)
plt.xlabel('t')
plt.grid(True)
plt.hold(True)
lw = 1.5
plt.plot(t,x, 'b', linewidth=lw)
plt.plot(t,y, 'g', linewidth=lw)
plt.legend((r'$x$', r'$y$'), prop=FontProperties(size=14), labelspacing=0.3, loc='best')
plt.title('van der Pol')
plt.savefig('vanderpol_plot.png', dpi=72, transparent=True)

# show()


