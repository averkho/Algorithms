#include <iostream>
#include <vector>

/*
The minimum number of coins with denominations 1,3,4 that changes money
*/



void print(std::vector <int> &A){
  std::cout << "I am printing vector " << std::endl;
  for (int i=0; i<A.size(); ++i){
    std::cout<< A[i] << " ";
  }
}

// coins that could be used to change money

std::vector <int> coins={1,3,4};

int get_change(int m) {

int num_coins;

  std::vector <int> min_number_coins(m+1,0);
  min_number_coins[0]=0;
  

  for (int i=1; i<=m; ++i){
    min_number_coins[i]=m+1;

    for (int j=0;j<coins.size();++j){
       if (coins[j]<=i){

         num_coins=min_number_coins[i-coins[j]]+1;

         if (num_coins<min_number_coins[i]){
           min_number_coins[i]=num_coins;
         }

       }
    }

  }
  
  return min_number_coins[m];
}

int main() {
  int m;
  std::cout << "Enter the amount to be changed " << std::endl;
  std::cin >> m;
   
  std::cout << get_change(m) << '\n';
}
