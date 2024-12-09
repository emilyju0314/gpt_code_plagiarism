#include <bits/stdc++.h>
using namespace std;
long a, b, c, d;
long gcd(long a, long b) {
  while (a && b) a > b ? a %= b : b %= a;
  return a + b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> c >> d;
  if (b * 1.0 / a < d * 1.0 / c) {
    swap(a, b);
    swap(c, d);
  }
  long aa, bb;
  aa = b * c - a * d;
  bb = b * c;
  long q = gcd(aa, bb);
  cout << aa / q << "/" << bb / q << endl;
  cin.get();
  cin.get();
  return 0;
}
