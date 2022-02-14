# -*- coding: utf-8 -*-
"""
Created on Sun Feb 13 22:53:36 2022

@author: AVERKHO
"""

def string_matching_naive(text,pattern):
    
        
    m=len(text)
    n=len(pattern)
    
    found=False
    
    for i in range(m-n+1):
        
        j=0
        
        while(j<n):
            
            if text[i+j]!=pattern[j]:
                
                break
            
            if j==n-1:
                
                print('pattern occurs at shift {}'.format(i))
                found=True
            
            j+=1
        
    if not(found):
        
        print("Pattern '{}' was not found in string '{}'".format(pattern,text))
    


if __name__=="__main__":
    
    text='acsdfegwegaabaabaab'
    pattern='aab'
    
    string_matching_naive(text,pattern)