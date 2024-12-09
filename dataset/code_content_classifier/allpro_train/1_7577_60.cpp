#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> p[2555];
long long minm(long long a, long long b) {
  if (a > b) return b;
  return a;
}
long long maxm(long long a, long long b) {
  if (a > b) return a;
  return b;
}
int main() {
  long long n, x1, y1, x2, y2, i, j, k, dist1, dist2, maxer[2555], ans, x, y;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  long long mx = -1;
  for (i = 0; i < n; i += 1) {
    cin >> x >> y;
    dist1 = (x - x1) * (x - x1) + (y1 - y) * (y1 - y);
    dist2 = (x - x2) * (x - x2) + (y2 - y) * (y2 - y);
    p[i] = make_pair(dist1, dist2);
    if (dist2 > mx) mx = dist2;
  }
  sort(p, p + n);
  maxer[n - 1] = p[n - 1].second;
  for (i = n - 2; i >= 0; i -= 1) {
    maxer[i] = maxm(p[i].second, maxer[i + 1]);
  }
  ans = 5e18;
  for (i = 0; i < n; i += 1) {
    ans = minm(ans, p[i].first + maxer[i + 1]);
  }
  ans = minm(ans, mx);
  cout << ans;
  return 0;
}
