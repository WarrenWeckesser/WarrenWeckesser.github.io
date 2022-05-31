import numpy as np
from scipy.stats import nakagami
import matplotlib.pyplot as plt


x = np.linspace(1e-12, 2.55, 800)
for nu in [0.25, 0.45, 0.5, 0.75, 1.0, 2.5]:
    if nu < 0.5:
        ls = ':'
    elif nu == 0.5:
        ls = '--'
    else:
        ls = '-'
    plt.plot(x, nakagami.pdf(x, nu), alpha=0.75, linestyle=ls, label=f'ν={nu}')

plt.ylim(-0.05, 1.55)
plt.title('PDF of the Nakagami distribution (a=0, s=1)')
plt.xlabel('x')
plt.legend(framealpha=1, shadow=True)
plt.grid(True)
# plt.show()
plt.savefig('nakagami_plots.svg')
