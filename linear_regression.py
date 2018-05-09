#function from: https://towardsdatascience.com/linear-regression-using-gradient-descent-in-10-lines-of-code-642f995339c0
import matplotlib.pylab as plt
import numpy as np
def abline(slope, intercept):
    """Plot a line from slope and intercept"""
    axes = plt.gca()
    x_vals = np.array(axes.get_xlim())
    y_vals = intercept + slope * x_vals
    plt.plot(x_vals, y_vals, '--')

def linear_regression(X, y, m_current=0, b_current=0, epochs=1000, learning_rate=0.0001):
    cost = 0
    N = float(len(y))
    for i in range(epochs):
        y_current = (m_current * X) + b_current
        cost = sum([data**2 for data in (y-y_current)]) / N
        m_gradient = -(2/N) * sum(X * (y - y_current))
        b_gradient = -(2/N) * sum(y - y_current)
        m_current = m_current - (learning_rate * m_gradient)
        b_current = b_current - (learning_rate * b_gradient)
    return m_current, b_current, cost

#I want to see if this function really works by plotting it


x = np.array([4,8,12,16,1,4,9,16])
y = np.array([1,4,9,16,4,8,12,3])

m = 1
b = 0
c = -1
fig = plt.figure()
fig.suptitle("y =" + str(m) + "x +" + str(b));
plt.scatter(x,y)
abline(m,b)
plt.show()

m,b,c = linear_regression(x,y,m,1)
fig = plt.figure()
fig.suptitle("y =" + str(m) + "x +" + str(b));
plt.scatter(x,y)
abline(m,b)
plt.show()






#--------------------------------
#crappy code but I want to see how it compares to linear regression

# Standalone simple linear regression example
from math import sqrt

# Calculate the mean value of a list of numbers
def mean(values):
	return sum(values) / float(len(values))

# Calculate covariance between x and y
def covariance(xx, mean_x, yy, mean_y):
	covar = 0.0
	for i in range(len(xx)):
		covar += (xx[i] - mean_x) * (yy[i] - mean_y)
	return covar

# Calculate the variance of a list of numbers
def variance(values, mean):
	return sum([(xx-mean)**2 for xx in values])

# Calculate coefficients
def coefficients(dataset):
	xx = [row[0] for row in dataset]
	yy = [row[1] for row in dataset]
	x_mean, y_mean = mean(xx), mean(yy)
	b1 = covariance(xx, x_mean, yy, y_mean) / variance(xx, x_mean)
	b0 = y_mean - b1 * x_mean
	return [b0, b1]
b,m = coefficients([x,y])

fig = plt.figure()
fig.suptitle("y =" + str(m) + "x +" + str(b));
plt.scatter(x,y)
abline(m,b)
plt.show()
