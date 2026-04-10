import numpy as np
import matplotlib.pyplot as plt

n = 500
line = [-5, 5]
delta = 0.2

k = line[0]
ranges = []
inters = int((abs(line[0]) + abs(line[1]) + 1) / delta)

for i in range(inters):
    r = [k, k + delta, 0]
    ranges.append(r)

    k += (delta + 0.001)


for i in range(n):
    x = np.random.normal(0, 1)
    for k in range(len(ranges)):
        if x > ranges[k][0] and x < ranges[k][1]:
            ranges[k][2] += 0.01
            mid = ranges[k][0] + (delta / 2)
            
            plt.plot(mid, ranges[k][2], 'o')




            
plt.show()    

