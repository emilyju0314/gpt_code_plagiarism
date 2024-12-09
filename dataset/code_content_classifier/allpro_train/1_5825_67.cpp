#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (a != 0 && b != 0) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return max(a, b);
}
int main() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int del = gcd(x, y);
  x /= del;
  y /= del;
  cout << x * min(a / x, b / y) << ' ' << y * min(a / x, b / y);
  return 0;
}
