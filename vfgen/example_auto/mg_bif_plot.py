#
# File:   mg.auto
# Author: Warren Weckesser, www.warrenweckesser.net
#
# Copyright (c) 2014 Warren Weckesser
#
# `auto` must be in the Python path to run this script.
# One way to do this is to add $AUTO_DIR/python to the
# PYTHONPATH environment variable.

import numpy as np
import matplotlib.pyplot as plt
import auto


mg = auto.bd("mg_bif")

fig = plt.figure(figsize=(6, 4)).subplots_adjust(bottom=0.13, left=0.16)

for p in mg.data:
    curves = p.coordarray
    plt.plot(curves[0], curves[2], 'b')

p0 = mg.data[0]
hb = p0.bylabel("HB")
hx = hb.coordarray[0]
hy = hb.coordarray[2]
plt.plot(hx, hy, 'bo')
plt.annotate("Hopf", (hx, hy), xytext=(hx-1.75, hy+0.01))

for k in range(1, 4):
    pd = mg.data[k].bylabel("PD")
    x = pd.coordarray[0]
    y = pd.coordarray[2]
    plt.plot(x, y, 'bo')
    if k == 3:
        ty = y + 0.01
    else:
        ty = y - 0.025
    plt.annotate("PD", (x, y), xytext=(x, ty))

plt.xlabel(r"$\tau$", fontsize=20)
plt.ylabel(r"${\rm max}\, x(t)$", fontsize=20)
plt.xlim(0, 20)
plt.grid(True)
plt.savefig("mg_bif.png", dpi=72, transparent=True)
#plt.show()