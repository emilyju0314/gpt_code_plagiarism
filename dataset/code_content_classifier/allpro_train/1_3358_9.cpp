#include <iostream>
#include <set>
using ll = long long;

int main() {
  int n{0};
  std::set<char> S;
  char c;
  while (std::cin >> c, !std::cin.eof()) {
    S.insert(c);
    ++n;
  }
  std::cout << ((n == S.size()) ? "yes" : "no") << std::endl;
}