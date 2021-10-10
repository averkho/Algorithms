# -*- coding: utf-8 -*-
"""
Created on Sun Oct  3 19:46:14 2021

@author: AVERKHO
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
plt.close('all')

import os
os.listdir('./')

dat=pd.read_csv('./Mall_Customers.csv')
dat.columns
X=dat[['Annual Income (k$)','Spending Score (1-100)']].values

K=5
m=200
centroids=np.array([]).reshape(2,0)
