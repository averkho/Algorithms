# -*- coding: utf-8 -*-
"""
Created on Sun Oct  3 20:28:25 2021

@author: AVERKHO
"""

import numpy as np

def forgy(X,row_count,n_clusters):
    
    return X[np.random.choice(row_count,size=n_clusters,replace=False)]