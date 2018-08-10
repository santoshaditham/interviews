import numpy as np
import random

# y = mx + b
# MSSE 
def linear_regression(X, y, e=20000, lr=0.0001):
    n = float(X.shape[0])
    m_cur = 0
    b_cur = 0
    for i in range(0,e):
        y_cur = m_cur * X + b_cur
        m_grad = - (2/n) * np.sum(X * (y-y_cur))
        b_grad = - (2/n) * np.sum(y-y_cur)
        m_cur = m_cur - lr*m_grad
        b_cur = b_cur - lr*b_grad
        error = np.mean(np.square(y-y_cur))
        if i%1000 == 0:
            print('Current slope {}, intercept {}, error {}'.format(m_cur, b_cur, error))
    return m_cur, b_cur, error

def sigmoid(z):
    return 1 / (1 + np.exp(-z))

# y = 1 / 1+ (e)-mx
def logistic_regression(X, y, e=20000, lr=0.0001):
    n = float(len(X))
    m_cur = 0
    for i in range(0,e):
        z = np.dot(X, m_cur)
        y_cur = sigmoid(z)
        gradient = np.dot(X.T, (y_cur - y)) / n
        m_cur = m_cur - lr*gradient
        error = np.mean(-y * np.log(y_cur) - (1 - y) * np.log(1 - y_cur))
        if i%1000 == 0:
            print('Current slope {}, error {}'.format(m_cur, error))       
    return m_cur, error

if __name__ == "__main__":
    X = np.array([x for x in range(0, 100)]).reshape(-1, 1)
    y = np.array([float(y*5+2) for y in range(0, 100)]).reshape(-1, 1)
    m, b, e = linear_regression(X, y)
    print('Final slope: ', m)
    print('Final intercept: ', b)
    print('Final error: ', e)    
    y = np.array([random.uniform(0, 1) for y in range(0, 100)]).reshape(-1, 1)
    m, e = logistic_regression(X, y)
    print('Final slope: ', m) 
    print('Final error: ', e) 

