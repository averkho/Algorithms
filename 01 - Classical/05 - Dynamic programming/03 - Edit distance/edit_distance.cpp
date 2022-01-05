#include <iostream>
#include <string>

int min(int a, int b, int c){

  /*

  The function to find minimum of three integers a, b and c

 */
  if (a<=b && a<=c){
    return a;
  } else if (b<a && b<=c){
    return b;
  } else{
    return c;
  }
}


int edit_distance(const std::string &str1, const std::string &str2) {

  /*
  str1 - string 1
  str2  - string 2
    
    The function for calculating edit distance between two strings.
    The edit distance between two strings is the minimum number of operations (insertions, deletions,
    and substitutions) to transform one string into another

 */

  size_t n=str1.length();
  size_t m=str2.length();
  //std::cout << "Before " << std::endl;
  int D[n+1][m+1];
  //std::cout <<"After " << std::endl;

  int insertion, deletion, match, mismatch;

  for (int i=0; i<=n; ++i){
    D[i][0]=i;
    
  }

  for (int j=0; j<=m; ++j){
    D[0][j]=j;
  }

  for (int i=1; i<=n; ++i){
    for (int j=1; j<=m; ++j){

      insertion=D[i][j-1]+1;
      deletion=D[i-1][j]+1;
      match=D[i-1][j-1];
      mismatch=D[i-1][j-1]+1;
      //std::cout << "Insertion " << insertion << std::endl;
      //std::cout << "Delection " << deletion << std::endl;

      if (str1[i-1]==str2[j-1]){
        D[i][j]=min(insertion,deletion,match);
        } else{
        D[i][j]=min(insertion,deletion,mismatch);
      }

    }
  }
 
  return D[n][m];
}

int main() {
  std::string str1;
  std::string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
