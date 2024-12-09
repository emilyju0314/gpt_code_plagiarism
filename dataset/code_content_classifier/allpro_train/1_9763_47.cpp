#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, d, b;
vector<long long> v;
inline bool legal(int i, int x) {
  if (x - i <= 1LL * (i + 1) * d) return true;
  return false;
}
inline int solve(int n, int m) {
  int p = 0, ret = 0;
  ;
  long long now = 0;
  for (int i = 0; i < n; ++i) {
    while (p < m && legal(i, p)) now += v[p++];
    if (now < b)
      ++ret;
    else
      now -= b;
  }
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &d, &b);
  for (int i = 0; i < n; ++i) {
    long long a;
    scanf("%I64d", &a);
    v.push_back(a);
  }
  int res = 0;
  for (int i = 0; i < 2; ++i) {
    res = max(res, solve((n - i + 1) / 2, n));
    reverse(v.begin(), v.end());
  }
  return cout << res << endl, 0;
}
