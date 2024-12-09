#include<iostream>

int main (){
  int n;
  std::cin >> n;
  int r = n % 1000;
  std::cout << (r?1000-r:0) << std::endl;
}