# -*- coding: utf-8 -*-
"""
Created on Sat Oct  2 14:29:23 2021

@author: AVERKHO
"""

import random
import numpy as np


class BubbleSort:
    
    def __init__(self):
        
        pass
    
    def sort(self,arr):
        
        '''
        make bubble sort
        '''
        
        n=len(arr)
        
        for i in range(n):
            
            for j in range(n-i-1):
                
                if arr[j]>arr[j+1]:
                    
                    arr[j+1],arr[j]=arr[j],arr[j+1]
        return arr
    
def initialize_array(n):
    
    '''
    Initialize array of size n from 0 to 100.
    The array is shuffled
    
    '''
    
    arr=np.random.randint(100,size=n)
    np.random.shuffle(arr)
    
    return arr

    

if __name__=='__main__':
    
    n=10
    np.random.seed(13)
    arr=initialize_array(n)
    
    print('Initial array: ',arr)
    
    bubbleSort=BubbleSort()
    new_arr=bubbleSort.sort(arr)
      
    print('Sorted array: ',new_arr)
    