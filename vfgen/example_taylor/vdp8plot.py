
import numpy as np
from numpy import loadtxt
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties


vdp8 = loadtxt('vdp8.dat')
vdp8_t  = vdp8[:,0]
vdp8_x  = vdp8[:,1]

vdpgsl = loadtxt('vdpgsl.dat')
vdpgsl_t = vdpgsl[:,0]
vdpgsl_x = vdpgsl[:,1]


plt.figure(figsize=(6, 4)).subplots_adjust(bottom=0.12)

plt.xlabel('t')
plt.ylabel('x')
plt.grid(True)
plt.hold(True)

lw = 1.5

plt.plot(vdp8_t, vdp8_x, 'b', linewidth=lw)
plt.plot(vdpgsl_t, vdpgsl_x, 'g', linewidth=lw)

plt.legend((r'Adaptive Taylor, Order 8',r'GSL (rk8pd)'), prop=FontProperties(size=16), loc='best')
plt.title('Van der Pol Equation')
plt.xlim(8.5, 10)
plt.ylim(-2.2, 3.3)
plt.savefig('vdp8compare.png', dpi=72, transparent=True)

# plt.show()


