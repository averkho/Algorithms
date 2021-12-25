# Uses python3

import numpy as np

'''
Given an integer you must compute the minimum number of operations needed to obtain 
that number starting from 1

Operations allowed:

 1 - x*2
 2 - x*3
 3 - x+1

'''

def optimal_sequence(n):
    '''
    
    Dynamic programming was used to solve the task.
    
    '''
    # Part I filling on the sequence of best solutions
    
    sequence = []
    sequence.append([0,0])
    sequence.append([1,0])
    sequence.append([2,1])
    
    i=3
    
    while i<=n:
        
        sequence.append([i,0])
        
        if i % 3 == 0:
            m1 = sequence[i // 3][1]+1
        else:
            m1=n+1
            
        if i % 2 == 0:
            m2 = sequence[i // 2][1]+1
        else:
            m2=n+1
        
        m3 = sequence[i - 1][1]+1
        
        sequence[i][1]=min([m1,m2,m3])
               
        i+=1
        
    # Part II creating the vector of best solutions to get n
    
    count=n       
    A=[n]
    while count>0:
        
        if count%3==0:
            m1=sequence[count//3]
        else:
            m1=[count,n+1]
        
        if count%2==0:
            m2=sequence[count//2]
        else:
            m2=[count,n+1]
        if count-1>=0:
            m3=sequence[count-1]
        else:
            m3=[count,n+1]
        
        m_list=[m1[1],m2[1],m3[1]]
        M_list=[m1[0],m2[0],m3[0]]
        count=M_list[np.argmin(m_list)]
        A.append(M_list[np.argmin(m_list)])  
    A.reverse()
    A=A[1:]
    return A,sequence

# Input number
n =5
sequence,A = list(optimal_sequence(n))

print(len(sequence) - 1)

for x in sequence:
    print(x, end=' ')
