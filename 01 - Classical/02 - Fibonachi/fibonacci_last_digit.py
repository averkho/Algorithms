# Uses python3
import numpy as np

def get_fibonacci_last_digit_naive(n):
    
    if n <= 1:
        return n
    numbers=np.zeros(n+1)
    for i in range(n+1):
        if i<=1:
            numbers[i]=i
        else:
            numbers[i]=int((numbers[i-1]+numbers[i-2])%10)
        
    return int(numbers[n])

def test():
    
    assert(get_fibonacci_last_digit_naive(3)==2)
    assert(get_fibonacci_last_digit_naive(327305)==5)
    assert(get_fibonacci_last_digit_naive(331)==9)
    
    print('All tests are passed')

if __name__ == '__main__':
    
    n = int(input())
    test()
    print(get_fibonacci_last_digit_naive(n))
