#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const long long inf = 1e9;
vector<long long> tree, si;
void upd(long long v, long long l, long long r, long long id, long long x) {
  if (l == r)
    tree[v] = min(tree[v], x);
  else {
    long long m = (l + r) >> 1;
    if (id <= m)
      upd(v << 1, l, m, id, x);
    else
      upd((v << 1) | 1, m + 1, r, id, x);
    tree[v] = min(tree[v << 1], tree[(v << 1) | 1]);
  }
}
long long que(long long v, long long tl, long long tr, long long l,
              long long r) {
  if (l > r) return inf;
  if (l > tr || tl > r) return inf;
  if (l <= tl && tr <= r) return tree[v];
  long long tm = (tl + tr) >> 1;
  return min(que(v << 1, tl, tm, l, r), que((v << 1) | 1, tm + 1, tr, l, r));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  ;
  long long n;
  string t;
  cin >> n >> t;
  vector<pair<long long, long long>> s;
  long long fi = -1;
  long long la = -1;
  for (long long i = 0; i < n; ++i) {
    if (t[i] == '1') {
      if (fi == -1) fi = i;
      la = i;
    } else {
      if (la != -1) s.emplace_back(fi, la);
      fi = la = -1;
    }
  }
  if (la != -1) s.emplace_back(fi, la);
  long long r[n];
  fill(r, r + n, -1);
  for (auto x : s) {
    long long le = x.first;
    long long ri = x.second;
    for (long long i = le; i <= ri; ++i) r[i] = ri;
  }
  auto sum = [&](long long x) { return x * (x + 1) / 2; };
  long long res = 0;
  long long ans[n];
  tree.resize(4 * n, inf);
  si.resize(n, inf);
  auto ins = [&](long long sz, long long l) { upd(1, 0, n - 1, sz, l); };
  auto f = [&](long long l) {
    if (t[l] == '0') {
      if (l == n - 1) return 0ll;
      if (t[l + 1] == '1') ins(r[l + 1] - l, l + 1);
      return ans[l + 1];
    }
    long long right = r[l];
    long long sz = right - l + 1;
    long long x = que(1, 0, n - 1, sz, n - 1);
    if (x == inf) {
      return sum(sz) + (n - 1 - right) * sz;
    } else {
      long long v = sum(sz);
      v += ((x - 1 - right) * sz);
      v += ans[x];
      v -= (sum(sz));
      v += (sz * sz);
      return v;
    }
  };
  for (long long i = n - 1; i >= 0; --i) {
    ans[i] = f(i);
    res += ans[i];
  }
  cout << res;
}
