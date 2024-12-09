#include <bits/stdc++.h>
using namespace std;
struct SEG {
  long long cnt, sum;
};
int n, m;
long long t;
vector<pair<int, int> > a;
vector<SEG> seg;
void insert(int o, int l, int r, int POS, int VAL) {
  if (r < POS || POS < l) return;
  if (l == r) {
    seg[o].cnt = 1;
    seg[o].sum = VAL;
    return;
  }
  int mid = (l + r) >> 1;
  if (POS <= mid)
    insert(o << 1, l, mid, POS, VAL);
  else
    insert(o << 1 | 1, mid + 1, r, POS, VAL);
  seg[o].cnt = seg[o << 1].cnt + seg[o << 1 | 1].cnt;
  seg[o].sum = seg[o << 1].sum + seg[o << 1 | 1].sum;
}
long long pre(int o, int l, int r, long long K) {
  if (K < 1) return 0;
  if (seg[o].cnt <= K) return seg[o].sum;
  int mid = (l + r) >> 1;
  long long ret = pre(o << 1, l, mid, K);
  if (seg[o << 1].cnt <= K)
    ret += pre(o << 1 | 1, mid + 1, r, K - seg[o << 1].cnt);
  return ret;
}
void init() {
  cin >> n >> m >> t;
  seg.clear();
  seg.resize(n * 4 + 4, {0LL, 0LL});
  a.resize(n);
  for (int i = 0; i < n; i++) {
    auto &p = a[i];
    cin >> p.first;
    p.second = i + 1;
  }
}
long long eval(int k) {
  if (k == 0) return 0;
  if (seg[1].cnt < k) return t + 1;
  long long X = pre(1, 1, n, (k - 1) / m * m);
  long long Y = pre(1, 1, n, k);
  return X + Y;
}
int cal() {
  int sz = (int)seg[1].cnt;
  int l = 1, r = sz;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (eval(mid) <= t)
      l = mid + 1;
    else
      r = mid;
  }
  if (eval(l) <= t)
    return l;
  else
    return l - 1;
}
void solve() {
  pair<int, int> ans;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    int d = a[i].first;
    while (1) {
      insert(1, 1, n, a[i].second, a[i].first);
      if (i == n - 1 || a[i + 1].first != a[i].first) break;
      i++;
    }
    int r = cal();
    ans = max(ans, {r, d});
  }
  cout << ans.first << ' ' << min(t, (long long)ans.second) << '\n';
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    init();
    solve();
  }
}
