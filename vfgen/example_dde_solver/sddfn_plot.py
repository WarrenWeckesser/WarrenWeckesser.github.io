import numpy as np
from numpy import loadtxt
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties


t, y = loadtxt('sddfn.dat', unpack=True)

plt.figure(figsize=(8, 5)).subplots_adjust(bottom=0.12)

plt.xlabel('t')
plt.ylabel('y')
plt.grid(True)
plt.hold(True)

lw = 1
plt.plot(t, y, 'bo', linewidth=lw)

t1 = np.linspace(0, 1.0, 51)
y1 = range(0, 51)
for k in range(0, 51):
    y1[k] = np.sqrt(t1[k] + 1)
plt.plot(t1, y1, 'g', linewidth=lw)

t2 = np.linspace(1.0, 2.0, 51)
y2 = range(0, 51)
for k in range(0, 51):
    y2[k] = (t2[k] + 1)/4 + 0.5 + (1 - np.sqrt(2.0)/2)*np.sqrt(t2[k] + 1)
plt.plot(t2,y2, 'g', linewidth=lw)

# plt.xlim(xmin=0.0, xmax=2.0)
plt.ylim(ymin=0.95, ymax=1.8)

plt.legend((r'dde_solver', 'Exact'), loc='upper left',
    prop=FontProperties(size=16), numpoints=1)
plt.savefig('sddfn.png', dpi=72, transparent=True)

# plt.show()


