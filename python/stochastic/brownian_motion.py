import numpy as np
import matplotlib.pyplot as plt


n_paths = 2
n_steps = 1000
dt = 0.01

steps = np.random.normal(0, np.sqrt(dt), size=(n_steps, n_paths))
paths = np.cumsum(steps, axis=0)


t = np.linspace(0, n_steps * dt, n_steps)

plt.plot(t, paths)
plt.show()