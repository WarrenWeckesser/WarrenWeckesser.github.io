# File:   pendulum_plot.py
# Author: Warren Weckesser, www.warrenweckesser.net

from numpy import loadtxt
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties


t, theta, v, energy = loadtxt('pendulum.dat', unpack=True)

plt.figure(1, figsize=(6,4.5)).subplots_adjust(bottom=0.12)
plt.xlabel('t')
plt.grid(True)
plt.hold(True)
lw = 1
plt.plot(t,theta, 'b', linewidth=lw)
h = plt.plot(t, v, 'g', linewidth=lw)
plt.plot(t,energy, 'r--', linewidth=lw)
plt.legend((r'$\theta$', r'$v$', 'energy'), prop=FontProperties(size=16))
plt.title('Damped Pendulum')
plt.savefig('pendulum_plot.png', dpi=72, transparent=True)

# show()


