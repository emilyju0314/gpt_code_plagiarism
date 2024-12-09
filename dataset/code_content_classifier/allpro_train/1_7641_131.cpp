#include <bits/stdc++.h>
using namespace std;
long long i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c, d;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    res = abs(c - a) + abs(d - b) + 2;
    if (a == c || b == d) res -= 2;
    cout << res << "\n";
  }
  return 0;
}
