#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1){
       return n;
    }
        

    std::vector<int> numbers(n);

    for (int i=0; i<(n+1); i++){
        if (i==0){
            numbers[i]=0;
        }
        else if (i==1){
            numbers[i]=1;
        }
        else{
            numbers[i]=(numbers[i-2]+numbers[i-1])%10;
        }
        

    }

   

    return numbers[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
