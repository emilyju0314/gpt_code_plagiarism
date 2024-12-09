#include <bits/stdc++.h>
int main() {
  long long n;
  std::cin >> n;
  std::function<long long(long long)> f;
  f = [&f](long long _n) {
    if (_n == 1) return 1ll;
    return _n * (_n + 1) / 2 - f(_n - 1);
  };
  std::cout << f(n);
  return 0;
}
