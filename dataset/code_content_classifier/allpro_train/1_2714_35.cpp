#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10, maxK = 6, mod = 1e9 + 7;
int lazy[4 * maxN], seg[maxK][4 * maxN], ps[maxK][maxN], a[maxN];
int n;
void shift(int id, int s, int e) {
  if (lazy[id] == -1) return;
  int mid = (s + e) / 2;
  for (int k = 0; k < maxK; k++) {
    seg[k][2 * id] = 1LL * lazy[id] * (ps[k][mid] + mod - ps[k][s]) % mod;
    seg[k][2 * id + 1] = 1LL * lazy[id] * (ps[k][e] + mod - ps[k][mid]) % mod;
  }
  lazy[2 * id] = lazy[id];
  lazy[2 * id + 1] = lazy[id];
  lazy[id] = -1;
}
void upd(int id, int L, int R, int x, int s = 0, int e = n) {
  if (L <= s && e <= R) {
    lazy[id] = x;
    for (int k = 0; k < maxK; k++) {
      seg[k][id] = 1LL * x * (ps[k][e] + mod - ps[k][s]) % mod;
    }
    return;
  }
  if (L >= e || s >= R) return;
  int mid = (s + e) / 2;
  shift(id, s, e);
  upd(2 * id, L, R, x, s, mid);
  upd(2 * id + 1, L, R, x, mid, e);
  for (int k = 0; k < maxK; k++) {
    seg[k][id] = (seg[k][2 * id] + seg[k][2 * id + 1]) % mod;
  }
}
int get(int k, int id, int L, int R, int s = 0, int e = n) {
  if (L <= s && e <= R) return seg[k][id];
  if (L >= e || s >= R) return 0;
  shift(id, s, e);
  int mid = (s + e) / 2;
  return (get(k, 2 * id, L, R, s, mid) + get(k, 2 * id + 1, L, R, mid, e)) %
         mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(lazy, -1, sizeof lazy);
  int m;
  cin >> n >> m;
  for (int k = 0; k < maxK; k++) {
    for (int i = 0; i < n; i++) {
      long long curr = 1;
      for (int j = 0; j < k; j++) curr = (1LL * curr * i) % mod;
      ps[k][i + 1] = (ps[k][i] + curr) % mod;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    upd(1, i, i + 1, a[i]);
  }
  while (m--) {
    char tp;
    cin >> tp;
    if (tp == '=') {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      upd(1, l, r, x);
    } else {
      int l, r, k;
      cin >> l >> r >> k;
      l--;
      if (k == 0) {
        long long res = get(0, 1, l, r);
        cout << res << '\n';
        continue;
      }
      int t = 1 - l;
      t = (t + mod) % mod;
      long long ans = 0, ways = 1, pw = 1;
      for (int c = k; c >= 0; c--) {
        ans += 1LL * ((1LL * pw * ways) % mod) * get(c, 1, l, r) % mod;
        ans %= mod;
        pw = 1LL * pw * t % mod;
        ways *= c;
        ways /= (k - c + 1);
      }
      cout << ans << '\n';
    }
  }
}
