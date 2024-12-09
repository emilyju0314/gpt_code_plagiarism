#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > g;
long long dp[3003][3003];
int main() {
  long long m, h1, h2, x1, x2, y1, y2, a1, a2;
  cin >> m;
  cin >> h1 >> a1;
  cin >> x1 >> y1;
  cin >> h2 >> a2;
  cin >> x2 >> y2;
  long long c = -1, i1 = -1, i2 = -1, r1 = -1, r2 = -1, f1 = 0, f2 = 0;
  while (++c <= 2 * 1000002) {
    if (h1 == a1 && h2 == a2) {
      cout << c << endl;
      return 0;
    }
    if (h1 == a1 && f1 == 0) {
      i1 = c;
      f1 = 1;
    } else if (h1 == a1 && f1 == 1) {
      r1 = c;
      f1 = 2;
    }
    if (h2 == a2 && f2 == 0) {
      i2 = c;
      f2 = 1;
    } else if (h2 == a2 && f2 == 1) {
      r2 = c;
      f2 = 2;
    }
    h1 = (h1 * x1 + y1) % m;
    h2 = (h2 * x2 + y2) % m;
  }
  if (i1 == -1 || r1 == -1 || i2 == -1 || r2 == -1) {
    cout << -1 << endl;
    return 0;
  }
  long long l1 = r1 - i1, l2 = r2 - i2;
  for (long long i = 0; i <= 1000002; i++) {
    if ((i * l1 + i1 - i2) >= 0 && (i * l1 + i1 - i2) % l2 == 0) {
      cout << (i * l1 + i1) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
