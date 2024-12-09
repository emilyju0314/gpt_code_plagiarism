#include <bits/stdc++.h>
using namespace std;
long long t, a, b, c, d;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    if ((c > d) || (c == d && a != b))
      cout << -1 << '\n';
    else if ((a * d) == (b * c))
      cout << 0 << '\n';
    else if (c == 0)
      cout << -1 << '\n';
    else {
      long long i = a / c;
      long long j = b / d;
      if ((i * c) < a) i++;
      if ((j * b) < d) j++;
      j = max(i, j);
      if ((j * c - a) <= (j * d - b))
        cout << (j * d - b) << '\n';
      else {
        long long x = d - c;
        long long y = ((j * c - a) - (j * d - b) + x - 1) / x;
        cout << ((j + y) * d - b) << '\n';
      }
    }
  }
  return false;
}
