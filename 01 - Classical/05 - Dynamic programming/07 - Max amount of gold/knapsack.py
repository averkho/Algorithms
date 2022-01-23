# Uses python3
import numpy as np

def optimal_weight(W, w):
    
    '''
    
    Given n gold bars, find the maximum weight of gold that fits in into bag ofcapacity W
    
    '''
    
    global K
    
    K=np.zeros([n+1,W+1])
    
    
        
    for weight in range(W+1):
        
        for i in range(n+1):
            
            if (i==0 or weight==0):
                
                K[i][w]=0
            
            elif (w[i-1]<=weight):
                
                K[i][weight]=max(w[i-1]+K[i-1][weight-w[i-1]],K[i-1][weight])
            
            else:
                K[i][weight]=K[i-1][weight]
    
    return K[n][W]

if __name__ == '__main__':
    
    W=10
    n=3
    w=[1,4,8]
    
    print(optimal_weight(W, w))
    
