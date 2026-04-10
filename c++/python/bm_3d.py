import numpy as np
import matplotlib.pyplot as plt


n_paths = 10
n_steps = 1000
dt = 0.01

def brownian_motion_3d(n_paths, n_steps, dt):

    steps = np.random.normal(0, np.sqrt(dt), size=(n_steps, n_paths, 2))

    paths = np.cumsum(steps, axis=0)
    path_x = paths[:, :, 0]
    path_y = paths[:, :, 1]

    t = np.linspace(0, n_steps * dt, n_steps)

    return t, path_x, path_y



t, path_x, path_y = brownian_motion_3d(n_paths, n_steps, dt)


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d', alpha=0.1)

for k in range(len(path_x[0, :])):
    ax.plot(t, path_x[:, k], path_y[:, k] , lw=0.8)


ax.set_xlabel('t')
ax.set_ylabel('x')
ax.set_zlabel('y')

plt.show()