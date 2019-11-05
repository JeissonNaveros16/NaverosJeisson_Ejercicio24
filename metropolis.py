import os
import numpy as np
import matplotlib.pyplot as plt

plt.figure()
data = np.loadtxt("metropolis.dat")
plt.hist(data, density=True)
plt.xlabel('X')
plt.ylabel('P(X)')
plt.savefig("metropolis.png")