#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const int M = 1e9 + 7;
const double eps = 1e-6;
const double PI(acos(-1.0));
int n;
int p[N], b[N];
int f(long long m) {
  long long lef = p[0] - m;
  for (int i = (1); i <= (40); i++) {
    if (m >= p[i]) {
      lef -= min(lef, m - p[i]);
      m = p[i];
    } else
      lef += p[i] - m;
    lef += b[i];
  }
  return lef == 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  long long x;
  for (int i = 0; i < (n); i++) {
    cin >> x;
    int j = 0, f = 0;
    while (x > 1) {
      if (x & 1) f = 1;
      j++;
      x >>= 1;
    }
    if (!f)
      p[j]++;
    else
      b[j]++;
  }
  int l = 1, r = p[0], m, ans = -1;
  while (l <= r) {
    m = l + r >> 1;
    if (f(m)) {
      r = m - 1;
      ans = m;
    } else
      l = m + 1;
  }
  if (~ans) {
    for (int i = (ans); i <= (p[0]); i++) cout << i << " ";
    cout << endl;
  } else
    cout << ans << endl;
}
