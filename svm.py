import matplotlib.pyplot as plt
from matplotlib import colors

bias = [-1,-1,-1,-1,-1,-1,-1,-1]
x = [4,8,12,16,1,4,9,16]
y = [1,4,9,16,4,8,12,3]
label = [0,0,1,1,0,1,1,1]

fig = plt.figure(figsize=(8,8))
plt.scatter(x, y, c=label, cmap=colors.ListedColormap(['red','green']))
plt.show()

def dist(x1,y1,x2,y2):
    return sqrt((x1-x2)**2 + (y1-y2)**2)

def calc_loss():
