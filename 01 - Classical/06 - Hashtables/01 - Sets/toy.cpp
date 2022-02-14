#include <iostream>
#include <bitset>

int main(){

    int a;

    std::cin >> a;

   std::cout << std::bitset<8>(a) << "="<< a << std::endl;

    a<<=1;

    std::cout << std::bitset<8>(a) << "="<< a << std::endl;

    return 0;
}