#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long int a, b, x, y, n1, n2, m;
  cin >> a >> b >> x >> y;
  long long int g = gcd(x, y);
  if (g == 0) return 0;
  x = x / g;
  y = y / g;
  n1 = a / x;
  n2 = b / y;
  m = min(n1, n2);
  cout << m;
}
