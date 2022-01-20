#Uses python3


import numpy as np

def lcs3(a, b, c):
    
    '''
    
    Function returns the largest common subsequnce of three sequences a, b and c
    
    '''
    
    
    n1=len(a)
    n2=len(b)
    n3=len(c)
    
    global A
    
    A=np.zeros((n1+1,n2+1,n3+1))
    
    for i in range(n1+1):
        
        for j in range(n2+1):
            
            for k in range(n3+1):
                
                if (i==0 or j==0 or k==0):
                    
                    A[i][j][k]=0
                
                elif (a[i-1]==b[j-1]==c[k-1]):
                    
                    A[i][j][k]=A[i-1][j-1][k-1]+1
                    
                else:
                    
                    A[i][j][k]=max(A[i-1][j][k],A[i][j-1][k],A[i][j][k-1])
    
    return A[n1][n2][n3]

if __name__ == '__main__':
    
   
    a=[1,2,3] # the sequnce #1
    b=[2,1,3] # the sequence #2
    c=[1,3,5] # the sequence #3
    
    print(lcs3(a, b, c))
