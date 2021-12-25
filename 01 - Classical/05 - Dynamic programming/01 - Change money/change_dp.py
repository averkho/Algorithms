# Uses python3

'''
The minimum number of coins with denominations 1,3,4 that changes money

'''

def get_change(m):
    
    '''
    The function gets the minimum number of coins to change m
    
    '''
    
    min_number_coins=[0]*(m+1)
    
    # coin denominations
    coins=[1,3,4]
    
    for i in range(1,m+1):
        min_number_coins[i]=(m+1)
        for coin in coins:
            
            if coin<=i:
                
                num_coins=min_number_coins[i-coin]+1
                
                if num_coins<min_number_coins[i]:
                    
                    min_number_coins[i]=num_coins
                    
    return min_number_coins[m]

if __name__ == '__main__':
    
    #money to change
    m=8
       
    print(get_change(m))
