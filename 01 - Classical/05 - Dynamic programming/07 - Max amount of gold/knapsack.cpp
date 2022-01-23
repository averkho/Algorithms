#include <iostream>
#include <vector>



int optimal_weight(int W, const std::vector<int> &w) {

  // Given n gold bars, find the maximum weight of gold that fits in into bag ofcapacity W
  
  size_t n=w.size();

  std::vector <std::vector<int>> K(n+1,std::vector<int> (W+1));

  for (int i=0; i<=n; ++i){

    for (int weight=0; weight<=W; ++weight){

      if (i==0 || weight==0){

        K[i][weight]=0;

      } else if (w[i-1]<=weight){

        K[i][weight]=std::max(w[i-1]+K[i-1][weight-w[i-1]],K[i-1][weight]);

      } else {

        K[i][weight]=K[i-1][weight];

      }

    }

  }

  return K[n][W];

}

int main() {
  int n, W;
  std::cin >> W >> n;
  std::vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
