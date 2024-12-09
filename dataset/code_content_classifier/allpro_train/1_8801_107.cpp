#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
long long ret, seed, n, m, vmax, a[100005], l, r, op, x, y, DB;
int rnd() {
  ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}
set<pair<pair<int, int>, long long> > S;
vector<pair<pair<int, int>, long long> > o, q;
void ASS() {
  int E = 0;
  for (auto &h : S) E += h.first.second - h.first.first + 1;
  assert(E == n);
}
void st(int l, int r) {
  o.clear(), q.clear();
  for (auto &h : S)
    if (h.first.first >= l && h.first.second <= r)
      o.push_back(h);
    else if (max(l, h.first.first) <= min(r, h.first.second))
      q.push_back(h);
  for (auto &h : o) S.erase(h);
  for (auto &h : q) {
    S.erase(h);
    if (h.first.first < l && h.first.second > r)
      S.insert({{h.first.first, l - 1}, h.second}),
          S.insert({{r + 1, h.first.second}, h.second}),
          o.push_back({{l, r}, h.second});
    else if (h.first.first < l)
      S.insert({{h.first.first, l - 1}, h.second}),
          o.push_back({{l, h.first.second}, h.second});
    else
      S.insert({{r + 1, h.first.second}, h.second}),
          o.push_back({{h.first.first, r}, h.second});
  }
}
void add(int l, int r, long long v) {
  st(l, r);
  for (auto &h : o) S.insert({h.first, h.second + v});
}
void st(int l, int r, long long v) {
  st(l, r);
  S.insert({{l, r}, v});
}
long long kth(int l, int r, long long K) {
  vector<pair<long long, long long> > u;
  for (auto &h : S)
    if (max(l, h.first.first) <= min(r, h.first.second))
      u.push_back(
          {h.second, min(r, h.first.second) - max(l, h.first.first) + 1ll});
  sort(u.begin(), u.end());
  for (auto &h : u)
    if (K <= h.second)
      return h.first;
    else
      K -= h.second;
  assert(0);
}
long long pw(long long n, long long k, long long MOD) {
  long long r(1);
  while (k) {
    if (k & 1) r *= n, r %= MOD;
    n *= n, n %= MOD;
    k >>= 1;
  }
  return r;
}
long long pwr(int l, int r, long long x, long long M) {
  long long T = 0;
  for (auto &h : S)
    if (max(l, h.first.first) <= min(r, h.first.second))
      T = (T + (min(r, h.first.second) - max(l, h.first.first) + 1ll) *
                   pw(h.second % M, x, M)) %
          M;
  return T;
}
int main(void) {
  scanf("%lld%lld%lld%lld", &n, &m, &seed, &vmax);
  for (int i(1); i < n + 1; i++) a[i] = (rnd() % vmax) + 1;
  for (int i(0); i < n; i++) S.insert({{i, i}, a[i + 1]});
  for (int i(1); i < m + 1; i++) {
    op = (rnd() % 4) + 1;
    l = (rnd() % n) + 1;
    r = (rnd() % n) + 1;
    if (l > r) swap(l, r);
    if (op == 3)
      x = (rnd() % (r - l + 1)) + 1;
    else {
      x = (rnd() % vmax) + 1;
      if (op == 4) y = (rnd() % vmax) + 1;
    }
    if (op == 1)
      add(l - 1, r - 1, x);
    else if (op == 2)
      st(l - 1, r - 1, x);
    else if (op == 3)
      printf("%lld\n", kth(l - 1, r - 1, x)), ++DB;
    else
      printf("%lld\n", pwr(l - 1, r - 1, x, y)), ++DB;
  }
  return 0;
}
