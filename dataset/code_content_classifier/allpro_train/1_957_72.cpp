#include <bits/stdc++.h>
int main(int argc, char **argv) {
  long long r = 0;
  long c;
  long long c2;
  std::cin >> c;
  for (long i = 0; i < c; i++) {
    std::cin >> c2;
    r += c2 + i * (c2 - 1);
  }
  std::cout << r;
}
