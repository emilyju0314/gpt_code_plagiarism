#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int main() {
  int a, b, n, cur = 1;
  cin >> a >> b >> n;
  while (n > 0) {
    n -= (cur == 1) ? gcd(n, a) : gcd(n, b);
    cur = 1 - cur;
  }
  cout << cur << '\n';
  return 0;
}
