#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100009];
long double q, mx, sm, bs, sn = 10, md;
bool d;
map<long long, long long> mp;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]] = 1;
  sort(a + 1, a + 1 + n);
  if (a[1] != 0) {
    for (int i = n; i >= 1; i--) a[i + 1] = a[i];
    a[1] = 0;
    ++n;
  }
  if (a[n] != m) a[n + 1] = m, ++n;
  for (int i = 1; i < n; i++) {
    sm = a[i + 1] - a[i];
    if (mp[a[i]] && mp[a[i + 1]]) sm /= 2.0;
    mx = max(mx, sm);
  }
  cout.precision(9);
  cout << fixed << mx;
  return 0;
}
