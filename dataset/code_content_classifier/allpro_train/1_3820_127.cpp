#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
const long long INF = 0x3f3f3f3f;
pair<long long, long long> v[MAXN];
bool mark[MAXN];
signed main() {
  long long n, m;
  cin >> n >> m;
  long long mex = 0;
  for (long long i = 0; i <= 1000000; i++) {
    v[i] = {INF, -INF};
  }
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    mex = max(x, mex);
    mark[x] = true;
    v[x].second = i;
    v[x].first = min(i, v[x].first);
  }
  long long pt2 = 0;
  long long last = INF;
  for (long long i = 1000000; i >= 1; i--) {
    if (v[i].second >= last) {
      pt2 = i + 1;
      break;
    }
    last = min(v[i].first, last);
  }
  for (long long i = 1000000; i >= 1; i--) {
    if (v[i].first == INF) v[i] = v[i + 1];
  }
  if (pt2 == 0) {
    cout << ((m) * (m + 1)) / 2 << endl;
    return 0;
  }
  long long up = 0;
  long long res = m - pt2 + 2;
  for (long long i = 1; i <= m; i++) {
    if (mark[i] == false) {
      res += m - min(pt2, mex + 1) + 2;
      continue;
    }
    if (v[i].first <= up) {
      break;
    } else
      up = max(up, v[i].second);
    while (up >= last && pt2 <= m) {
      pt2++;
      last = v[pt2].first;
    }
    res += m - min(pt2, mex + 1) + 2;
  }
  cout << res << endl;
}
