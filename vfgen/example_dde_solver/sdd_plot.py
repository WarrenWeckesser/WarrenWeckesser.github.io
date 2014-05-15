import numpy as np
from numpy import loadtxt
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties


t, y = loadtxt('sdd.dat', unpack=True)

plt.figure(figsize=(8, 6)).subplots_adjust(bottom=0.12)

plt.xlabel('t')
plt.ylabel('y')
plt.title('State-Dependent Delay Example')
plt.grid(True)
plt.hold(True)

lw = 1
plt.plot(t, y, 'bo', linewidth=lw)

t1 = [0, np.exp(1)-1]
y1 = [t1[0]+1, t1[1]+1]
plt.plot(t1, y1, 'g', linewidth=lw)

t2 = np.linspace(np.exp(1)-1, np.exp(2)-1, 51)
y2 = range(0, 51)
for k in range(0, 51):
    y2[k] = np.exp((t2[k]+1)/np.exp(1))
plt.plot(t2, y2, 'g', linewidth=lw)

t3 = np.linspace(np.exp(2)-1, 10, 51)
y3 = range(0, 51)
for k in range(0, 51):
    y3[k] = (np.exp(1)/(3 - np.log(t3[k] + 1)))**np.exp(1)
plt.plot(t3, y3, 'g', linewidth=lw)

plt.ylim(ymin=0.0, ymax=60.0)

plt.legend((r'dde_solver_m', 'Exact'), loc='upper left',
    prop=FontProperties(size=16), numpoints=1)
plt.savefig('sdd.png', dpi=72, transparent=True)

# show()


