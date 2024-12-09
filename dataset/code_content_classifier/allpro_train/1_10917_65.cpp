#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, d, x, y;
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> x;
    cin >> y;
    cin >> d;
    long long e = n + 1;
    if ((y - x) % d == 0) {
      e = abs(y - x) / d;
    }
    long long c = n + 1, a = n + 1;
    if ((y - 1) % d == 0) c = (x - 1 + d - 1) / d + (y - 1) / d;
    if ((n - y) % d == 0) a = (n - y) / d + (n - x + d - 1) / d;
    if (a == n + 1 && c == n + 1 && e == n + 1)
      cout << -1 << endl;
    else
      cout << min(min(a, c), e) << endl;
  }
}
