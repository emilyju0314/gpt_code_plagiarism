#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
const int xn = 1e5 + 10;
const int xm = 10;
const int sq = 320;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;
int mod = 1e9 + 7;
const int base = 257;
int n, q, k, a[xn], b[xn], fen[xm][xn], phi;
int seg[xn << 2], lazy[xn << 2], md, sum[xn << 2];
bool prm[xn];
void calc_phi() {
  phi = md = mod;
  int t = mod;
  for (int i = 2; i * i <= t; ++i) {
    if (t % i) continue;
    while (t % i == 0) t /= i;
    phi -= phi / i;
  }
  if (t > 1) phi -= phi / t;
  --phi;
}
void mofen(int id, int pos, int val) {
  for (pos += 5; pos < xn; pos += pos & -pos) fen[id][pos] += val;
}
int gefen(int id, int pos) {
  int res = 0;
  for (pos += 5; pos > 0; pos -= pos & -pos) res += fen[id][pos];
  return res;
}
void build(int id, int l, int r) {
  seg[id] = lazy[id] = sum[id] = 1;
  if (r - l == 1) {
    cin >> a[l];
    return;
  }
  int mid = l + r >> 1;
  build(id << 1, l, mid), build(id << 1 | 1, mid, r);
  sum[id] = (sum[id << 1] + sum[id << 1 | 1]) % mod;
}
void update2(int id, int l, int r, int ql, int qr, int val) {
  if (qr <= l || r <= ql || qr <= ql) return;
  if (ql <= l && r <= qr) {
    seg[id] = 1ll * seg[id] * val % mod;
    return;
  }
  int mid = l + r >> 1;
  update2(id << 1, l, mid, ql, qr, val);
  update2(id << 1 | 1, mid, r, ql, qr, val);
}
int get2(int id, int l, int r, int pos) {
  if (r - l == 1) return seg[id];
  int mid = l + r >> 1;
  if (pos < mid) return 1ll * seg[id] * get2(id << 1, l, mid, pos) % mod;
  return 1ll * seg[id] * get2(id << 1 | 1, mid, r, pos) % mod;
}
void shift(int id, int l, int r) {
  if (lazy[id] == 1) return;
  sum[id] = 1ll * sum[id] * lazy[id] % mod;
  if (r - l > 1) {
    lazy[id << 1] = 1ll * lazy[id << 1] * lazy[id] % mod;
    lazy[id << 1 | 1] = 1ll * lazy[id << 1 | 1] * lazy[id] % mod;
  }
  lazy[id] = 1;
}
void update1(int id, int l, int r, int ql, int qr, int val) {
  shift(id, l, r);
  if (qr <= l || r <= ql || qr <= ql) return;
  if (ql <= l && r <= qr) {
    lazy[id] = 1ll * lazy[id] * val % mod;
    shift(id, l, r);
    return;
  }
  int mid = l + r >> 1;
  update1(id << 1, l, mid, ql, qr, val);
  update1(id << 1 | 1, mid, r, ql, qr, val);
  sum[id] = (sum[id << 1] + sum[id << 1 | 1]) % mod;
}
void modify(int id, int l, int r, int pos, int val) {
  if (r - l == 1) {
    sum[id] = val;
    return;
  }
  int mid = l + r >> 1;
  shift(id << 1, l, mid), shift(id << 1 | 1, mid, r);
  if (pos < mid)
    modify(id << 1, l, mid, pos, val);
  else
    modify(id << 1 | 1, mid, r, pos, val);
  sum[id] = (sum[id << 1] + sum[id << 1 | 1]) % mod;
}
int get1(int id, int l, int r, int ql, int qr) {
  shift(id, l, r);
  if (qr <= l || r <= ql || qr <= ql) return 0;
  if (ql <= l && r <= qr) return sum[id];
  int mid = l + r >> 1;
  return (get1(id << 1, l, mid, ql, qr) + get1(id << 1 | 1, mid, r, ql, qr)) %
         mod;
}
void query1(int l, int r, int x) {
  update1(1, 1, n + 1, l, r + 1, x);
  for (int i = 0; i < k; ++i) {
    int y = 0;
    while (x % b[i] == 0) ++y, x /= b[i];
    mofen(i, l, y);
    mofen(i, r + 1, -y);
  }
  update2(1, 1, n + 1, l, r + 1, x);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> mod, calc_phi();
  for (int i = 2; i < xn; ++i) {
    if (prm[i]) continue;
    if (md % i == 0) b[k++] = i;
    while (md % i == 0) md /= i;
  }
  if (md > 1) b[k++] = md;
  build(1, 1, n + 1);
  for (int i = 1; i <= n; ++i) query1(i, i, a[i]);
  cin >> q;
  while (q--) {
    int t, l, r, x, y, ind, res;
    cin >> t;
    if (t == 1) {
      cin >> l >> r >> x;
      query1(l, r, x);
    } else if (t == 2) {
      cin >> ind >> x, res = 1;
      for (int i = 0; i < k; ++i) {
        y = 0;
        while (x % b[i] == 0) ++y, x /= b[i];
        mofen(i, ind, -y);
        mofen(i, ind + 1, y);
        res = 1ll * res * power(b[i], gefen(i, ind), mod) % mod;
      }
      update2(1, 1, n + 1, ind, ind + 1, power(x, phi, mod));
      res = 1ll * res * get2(1, 1, n + 1, ind) % mod;
      modify(1, 1, n + 1, ind, res);
    } else {
      cin >> l >> r;
      cout << get1(1, 1, n + 1, l, r + 1) << '\n';
    }
  }
  return 0;
}
