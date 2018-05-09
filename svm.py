"""
constraints:
 - Linear seperator
 - binary classifier
"""

import matplotlib.pyplot as plt
import numpy as np
from matplotlib import colors

x = np.array([4,8,12,16,1,4,9,16])
y = np.array([1,4,9,16,4,8,12,3])
label = [0,0,1,1,0,1,1,1]

fig = plt.figure(figsize=(8,8))
plt.scatter(x, y, c=label, cmap=colors.ListedColormap(['red','green']))
plt.show()

def dist(x1,y1,x2,y2):
    return sqrt((x1-x2)**2 + (y1-y2)**2)

orth_vecs = np.cross(x,y)

def calc_loss():
    return 0
def dist_to_plane():


#note: the margin is always symmetrical on both sides of the hyperplane
def tot_margin(v1):
    return 2/np.absolute(v1)
#Karush-Khun-Tucker

for x in range(1000):
    cur_descent = calc_loss()
