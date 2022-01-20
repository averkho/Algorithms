# -*- coding: utf-8 -*-
"""
Created on Mon Jan 17 13:40:57 2022

@author: AVERKHO
"""

import numpy as np


def knapsack(w,v,W):
    
    '''
    
    w -  array of weights (int)
    v - array of values (int)
    W - max allowed weight of knapsack
    
    return max possible value of knapsack
    
    '''
    global A
    
    A=np.zeros((len(w)+1,W+1))
    
    for i in range(1,len(w)+1):
        
        for weight in range(1,W+1):
            
            if w[i-1]<=weight:
                
                A[i][weight]=max(v[i-1]+A[i-1][weight-w[i-1]],A[i-1][weight])
                
            else:
                
                A[i][weight]=A[i-1][weight] 
    
    return A[i][weight]
    
    

if __name__=="__main__":
    # the max weight of a knapsack
    W=10
    w=[6,3,4,2]
    v=[30,14,16,9]
    
    print("Max value of knapsack with max weight {} is {}".format(W,knapsack(w,v,W)))