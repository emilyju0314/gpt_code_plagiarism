#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, m, d;
  cin >> n >> m >> d;
  n *= m;
  vector<int> a(n);
  for (auto(i) = (0); (i) < (n); (i)++) cin >> a[i];
  sort((a).begin(), (a).end());
  vector<int> h(n), pr(n + 1);
  for (auto(i) = (1); (i) < (n); (i)++) {
    if ((a[i] - a[0]) % d) {
      cout << -1;
      return 0;
    }
    h[i] = (a[i] - a[0]) / d;
  }
  for (auto(i) = (0); (i) < (n); (i)++) pr[i + 1] = pr[i] + h[i];
  int ia = 0, ib = 0, c = 1000000007;
  while (ia < n) {
    while (ib < n && h[ib] == h[ia]) ib++;
    c = min(c, h[ia] * (ia + ib - n) - pr[ia] + pr[n] - pr[ib]);
    ia = ib;
  }
  cout << c;
  return 0;
}
