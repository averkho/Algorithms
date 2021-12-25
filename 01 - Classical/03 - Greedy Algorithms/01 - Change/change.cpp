#include <iostream>

int get_change(int m) {
  //write your code here
  if (m==0) return m;

  int count=0;
  int left=m;

  int tenths;

  tenths=left/10;
  left%=10;

  count+=tenths;

  tenths=left/5;

  left%=5;
  count+=tenths+left;

  return count;

}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
