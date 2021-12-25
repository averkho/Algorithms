#include <iostream>
#include <vector>
#include <algorithm>

int get_min_argument(int m1, int m2, int m3){

  
  if (m1<=m2 && m1<=m3){

    return 0;

  } else if (m2<m1 && m2<=m3){

    return 1;

  } else {

    return 2;
  }

}

int get_min_value(int m1, int m2, int m3){
  if (m1<=m2 && m1<=m3){

    return m1;

  } else if (m2<m1 && m2<=m3){

    return m2;

  } else {

    return m3;
  }
}

  
  typedef struct {
    int first;
    int second;
  } M; 

  void print(std::vector <int> &A){
    std::cout << "I am printing vector " << std::endl;
    for (int i=0; i<A.size(); ++i){
      std::cout << A[i] << "  ";
    }

    std::cout << "\n";
  }

  void print(std::vector <std::pair<int,int>> &A){
    std::cout << "I am printing paired vector " << std::endl;
    for (int i=0; i<A.size(); ++i){
      std::cout << A[i].first << "  " << A[i].second << std::endl; 
    }

    std::cout << "\n";
  }
  


std::vector<int> optimal_sequence(int n) {

  std::vector<std::pair<int,int>> sequence;
  sequence.push_back(std::make_pair(0,0));
  sequence.push_back(std::make_pair(1,0));
  sequence.push_back(std::make_pair(2,1));

  int i=3;
  int m1,m2,m3;

  while (i<=n){
    sequence.push_back(std::make_pair(i,0));

    if (i%3==0){
      m1=sequence[i/3].second+1;
    }else{
      m1=n+1;
    }

    if (i%2==0){
      m2=sequence[i/2].second+1;
    }else{
      m2=n+1;
    }

    m3=sequence[i-1].second+1;
    
    sequence[i].second=get_min_value(m1,m2,m3);
    ++i;
  }

  int count=n;
  std::vector <int> A; 
  A.push_back(n);

  std::vector<int> M3;

  M n1,n2,n3;

  std::vector <int> M_list;
  
  while (count>0){

    
    if (count%3==0){

      n1.first=sequence[count/3].first;
      n1.second=sequence[count/3].second;

    } else {
      n1.first=count;
      n1.second=n+1;
    }

    if (count%2==0){
      n2.first=sequence[count/2].first;
      n2.second=sequence[count/2].second;
    } else {
      n2.first=count;
      n2.second=n+1;
    }

    if (count-1>=0){

      n3.first=sequence[count-1].first;
      n3.second=sequence[count-1].second;

    } else {

      n3.first=count;
      n3.second=n+1;

    }

    M3.push_back(n1.first);
    M3.push_back(n2.first);
    M3.push_back(n3.first);
    //print(M3);
    count=M3[get_min_argument(n1.second,n2.second,n3.second)];
    M3.clear();
    A.push_back(count);
  }
  
  reverse(A.begin(), A.end());
  A.erase(A.begin()+0);
  return A;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
