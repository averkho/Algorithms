
import numpy as np

def edit_distance(s, t):
    
    """
    s - string 1
    t - string 2
    
    The function for calculating edit distance between two strings.
    The edit distance between two strings is the minimum number of operations (insertions, deletions,
    and substitutions) to transform one string into another
    
    """
    
    
    D=np.zeros((len(s)+1,len(t)+1))
    for i in range(len(s)+1):
        D[i][0]=i
    for j in range(len(t)+1):
        D[0][j]=j
    for i in range(1,len(s)+1):
        
        for j in range(1,len(t)+1):
            
            insertion=D[i][j-1]+1
            deletion=D[i-1][j]+1
            match=D[i-1][j-1]
            mismatch=D[i-1][j-1]+1
            
            if s[i-1]==t[j-1]:
                D[i][j]=min(insertion,deletion,match)
            else:
                D[i][j]=min(insertion,deletion,mismatch)
            
            
    return D[len(s)][len(t)]

if __name__ == "__main__":
    string1='prints'
    string2='print'
    print(edit_distance(string1,string2))
    
