#Uses python3

import sys
import numpy as np


def lcs2(a, b):
    #write your code here
    '''
    The longest common subsequence of two sequences a and b - length
    '''
    global A
    A=np.zeros((len(a)+1,len(b)+1))
    
    for i in range(1,len(a)+1):
             
        
        for j in range(1,len(b)+1):
            
            if a[i-1]==b[j-1]:
                
                A[i][j]=A[i-1][j-1]+1
            else:
                A[i][j]=max(A[i-1][j],A[i][j-1])
            
      
    
    return int(A[len(a)][len(b)])

if __name__ == '__main__':
   
    a=[2,7,8,3]
    b=[5,2,7,8,7]
    print('The length of the longest common subsequence is {} elements'.format(lcs2(a, b)))
