#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b, int n, int m) {

  int A[n+1][m+1];

  for (int i=0; i<=n; ++i){
    A[i][0]=0;
  }

  for (int j=0; j<=m; ++j){
    A[0][j]=0;
  }

  for (int i=1; i<=n; ++i){
    for (int j=1; j<=m; ++j){
      if (a[i-1]==b[j-1]){
        A[i][j]=A[i-1][j-1]+1;
      } else{
        A[i][j]=std::max(A[i-1][j],A[i][j-1]);
      }
    }
  }
  

  
  return A[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }
  std::cout << "The longest common subsequence of two sequences is ";
  std::cout << lcs2(a, b,n,m);
  std::cout << " elements" << std::endl;
}
