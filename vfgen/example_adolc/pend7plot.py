# File:   pend7plot.py
# Author: Warren Weckesser, www.warrenweckesser.net

from numpy import loadtxt
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

t, theta, v = data = loadtxt('pend7.dat', unpack=True)

plt.figure(1, figsize=(6, 4)).subplots_adjust(bottom=0.12)
plt.xlabel('t')
plt.grid(True)
plt.hold(True)
lw = 1.5
plt.plot(t, theta, 'b', linewidth=lw)
plt.plot(t, v, 'g', linewidth=lw)
plt.legend((r'$\theta$', r'$v$'), prop=FontProperties(size=16))
plt.title('Damped Pendulum')
plt.savefig('pend7.png', dpi=72, transparent=True)

# show()


