#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
inline void cmin(int &x, int y) {
  if (y < x) x = y;
}
inline void cmax(int &x, int y) {
  if (y > x) x = y;
}
vector<pair<long long, long long> > fa(long long x) {
  vector<pair<long long, long long> > v;
  for (long long i = 2; i <= x, x > 1; i++) {
    long long f = 0;
    while (x % i == 0) {
      x /= i;
      ++f;
    }
    if (f) v.push_back(make_pair(i, f));
    if (i == 1000004) {
      v.push_back(make_pair(x, 1));
      break;
    }
  }
  return v;
}
int main() {
  long long n, b;
  cin >> n >> b;
  vector<pair<long long, long long> > c = fa(b);
  long long ans = LL_INF;
  for (long long i = 0; i < c.size(); i++) {
    long long x = c[i].first, fac = 0;
    for (long long t = n; t; t /= x) fac += t / x;
    ans = min(ans, fac / c[i].second);
  }
  printf("%I64d", ans);
  return 0;
}
