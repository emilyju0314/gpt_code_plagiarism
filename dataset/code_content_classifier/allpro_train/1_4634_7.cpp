#include <bits/stdc++.h>
const int N = 100100;
std::pair<int, int> a[N], pref[N], suf[N];
int n;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
long long sqr(long long x) { return x * x; }
std::pair<int, int> getP(int x, int y) {
  if (x == 0 && y == n - 1) return {0, 0};
  return x > 0 ? y < n - 1 ? std::pair<int, int>(
                                 min(pref[x - 1].first, suf[y + 1].first),
                                 max(pref[x - 1].second, suf[y + 1].second))
                           : pref[x - 1]
               : suf[y + 1];
}
long long diam2(int x, int y) {
  auto p = getP(x, y);
  return max(sqr(p.second - p.first),
             max(sqr(a[y].first - a[x].first),
                 max(sqr(p.first) + sqr(a[x].first),
                     max(sqr(p.first) + sqr(a[y].first),
                         max(sqr(p.second) + sqr(a[x].first),
                             sqr(p.second) + sqr(a[y].first))))));
}
bool check(long long len2) {
  int k = 0;
  for (int i = 0; i < n; ++i) {
    while (k < n - 1 && sqr(a[k + 1].first - a[i].first) <= len2) ++k;
    if (diam2(i, k) <= len2) return true;
  }
  return false;
}
long long solve() {
  std::sort(a, a + n);
  pref[0] = {a[0].second, a[0].second};
  for (int i = 1; i < n; ++i)
    pref[i] = {min(a[i].second, pref[i - 1].first),
               max(a[i].second, pref[i - 1].second)};
  suf[n - 1] = {a[n - 1].second, a[n - 1].second};
  for (int i = n - 2; i >= 0; --i)
    suf[i] = {min(a[i].second, suf[i + 1].first),
              max(a[i].second, suf[i + 1].second)};
  long long s = sqr(a[n - 1].first - a[0].first);
  int y = n - 1;
  for (int i = 0; i < n; ++i) {
    while (sqr(a[y].first) > sqr(a[i].first)) --y;
    int l = i, r = y;
    while (l < r) {
      int t = (l + r + 1) / 2;
      auto p = getP(i, t);
      long long d1 = sqr(a[i].first - a[t].first);
      long long d2 = sqr(a[i].first) + max(sqr(p.first), sqr(p.second));
      if (d1 <= d2)
        l = t;
      else
        r = t - 1;
    }
    s = min(s, diam2(i, l));
  }
  long long l = 0, r = 1e18;
  while (l < r) {
    long long t = (l + r) / 2;
    if (check(t))
      r = t;
    else
      l = t + 1;
  }
  return min(s, l);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
  long long r = 1e18;
  for (int it = 0; it < 4; ++it) {
    if (it & 1)
      for (int i = 0; i < n; ++i) a[i].first = -a[i].first;
    if (it == 2)
      for (int i = 0; i < n; ++i) std::swap(a[i].first, a[i].second);
    r = min(r, solve());
  }
  printf("%I64d\n", r);
  return 0;
}
