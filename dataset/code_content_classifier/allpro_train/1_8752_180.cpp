#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll, ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll modpow(ll a, ll b, ll mod = (ll)(1e9 + 7)) {
  if (!b) return 1;
  a %= mod;
  return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int DEBUG = 1;
const int mxk = 13, mxm = 4, dsz = (1 << mxm) * mxk, mod = 1e9 + 7;
int n, m, k;
void add(ll &a, ll b) {
  a += b;
  if (a >= mod) a -= mod;
}
struct Matrix {
  ll a[dsz][dsz];
  Matrix() {
    for (int i = 0; i < dsz; i++)
      for (int j = 0; j < dsz; j++) a[i][j] = 0;
  }
} id;
void init() {
  for (int i = 0; i < dsz; i++) id.a[i][i] = 1;
}
Matrix operator*(Matrix a, Matrix b) {
  Matrix ret;
  for (int i = 0; i < dsz; i++)
    for (int j = 0; j < dsz; j++)
      for (int kk = 0; kk < dsz; kk++)
        add(ret.a[i][kk], a.a[i][j] * b.a[j][kk] % mod);
  return ret;
}
int cnv(int mask, int kk) { return (kk << mxm) + mask; }
int rot(int mask) { return (mask << 1) % (1 << m); }
Matrix modpow(Matrix a, ll b) {
  Matrix ans = id;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b /= 2;
  }
  return ans;
}
void solve() {
  init();
  Matrix op;
  for (int mask = 0; mask < 1 << m; mask++)
    for (int kk = 0; kk <= k; kk++) {
      add(op.a[cnv(rot(mask), kk)][cnv(mask, kk)], 1);
      if (kk < k)
        add(op.a[cnv(rot(mask) + 1, kk + 1)][cnv(mask, kk)],
            1 + __builtin_popcount(mask));
    }
  Matrix b;
  b.a[0][0] = 1;
  Matrix res = modpow(op, n) * b;
  ll ans = 0;
  for (int mask = 0; mask < 1 << m; mask++) add(ans, res.a[cnv(mask, k)][0]);
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n >> k >> m) solve();
  return 0;
}
