#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 1e5 + 2;
pair<int, int> mush[10003];
struct IT {
  vector<ld> it, lz;
  IT(int n) {
    it.assign(n + 1, 0);
    lz.assign(4 * n, 1);
  }
  void build(int id, int l, int r) {
    if (l == r) {
      it[l] = mush[l].second;
      return;
    }
    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build((id << 1) | 1, m + 1, r);
  }
  void dolazy(int id, int l, int r) {
    if (lz[id] == 1) return;
    if (l == r)
      it[l] *= lz[id];
    else {
      lz[id << 1] *= lz[id];
      lz[(id << 1) | 1] *= lz[id];
    }
    lz[id] = 1;
  }
  void update(int id, int l, int r, int L, int R, int p) {
    dolazy(id, l, r);
    if (l > R || r < L || L > R) return;
    if (L <= l && r <= R) {
      lz[id] *= p / 100.0;
      dolazy(id, l, r);
      return;
    }
    int m = (l + r) >> 1;
    update(id << 1, l, m, L, R, p);
    update((id << 1) | 1, m + 1, r, L, R, p);
  }
  void cal(int id, int l, int r) {
    dolazy(id, l, r);
    if (l == r) return;
    int m = (l + r) >> 1;
    cal(id << 1, l, m);
    cal((id << 1) | 1, m + 1, r);
  }
};
int n, m, a[N], h[N], pr[N], pl[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) cin >> a[i] >> h[i] >> pl[i] >> pr[i];
  for (int i = (1); i <= (m); ++i) cin >> mush[i].first >> mush[i].second;
  sort(mush + 1, mush + 1 + m);
  IT seg(m);
  seg.build(1, 1, m);
  for (int i = (1); i <= (n); ++i) {
    int l =
        lower_bound(mush + 1, mush + 1 + m, pair<int, int>(a[i] - h[i], -1)) -
        mush;
    int r = lower_bound(mush + 1, mush + 1 + m, pair<int, int>(a[i], -1)) -
            mush - 1;
    seg.update(1, 1, m, l, r, (100 - pl[i]));
    l = upper_bound(mush + 1, mush + 1 + m, pair<int, int>(a[i], 1e9)) - mush;
    r = upper_bound(mush + 1, mush + 1 + m, pair<int, int>(a[i] + h[i], 1e9)) -
        mush - 1;
    seg.update(1, 1, m, l, r, (100 - pr[i]));
  }
  seg.cal(1, 1, m);
  ld ans = 0;
  for (int i = (1); i <= (m); ++i) ans += seg.it[i];
  cout << fixed << setprecision(10) << ans;
  return 0;
}
