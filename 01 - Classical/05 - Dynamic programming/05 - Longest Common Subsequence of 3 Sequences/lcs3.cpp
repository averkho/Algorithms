#include <iostream>
#include <vector>



int lcs3(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c) {
  
  size_t n1=a.size();
  size_t n2=b.size();
  size_t n3=c.size();

  int A[n1+1][n2+1][n3+1];

  for (int i=0; i<=n1; ++i){
    for (int j=0; j<=n2; ++j){
      for (int k=0; k<=n3; ++k){

        if (i==0 || j==0 || k==0){

          A[i][j][k]=0;

        } else if (a[i-1]==b[j-1] && a[i-1]==c[k-1] && b[j-1]==c[k-1]){

          A[i][j][k]=A[i-1][j-1][k-1]+1;

        } else{

           A[i][j][k]=std::max(A[i-1][j][k], std::max(A[i][j-1][k],A[i][j][k-1]));

        }
      }
    }
  }

  return A[n1][n2][n3];
}

int main() {
  size_t an;
  std::cout << "Enter a size of sequence #1 " << std::endl;
  std::cin >> an;
  std::vector<int> a(an);
  std::cout << "Enter elements of sequence #1" << std::endl;
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cout << "Enter a size of sequence #2 " << std::endl;
  std::cin >> bn;
  std::vector<int> b(bn);
  std::cout << "Enter elements of the sequence #2 " << std::endl;
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cout << "Enter a size of sequence #3 " << std::endl;
  std::cin >> cn;
  std::vector<int> c(cn);
  std::cout << "Enter elements of sequence #3" << std::endl;

  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << "The length of the longest common subsequence of three sequences is ";
  std::cout << lcs3(a, b, c);
  std::cout << " elements" << std::endl;
}
