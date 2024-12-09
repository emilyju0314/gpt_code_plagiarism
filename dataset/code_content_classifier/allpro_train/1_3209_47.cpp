#include <bits/stdc++.h>
using namespace std;
const int base = 1000000007;
const int N = 400005;
const int MX = 305;
struct node {
  int mult;
  long long msk;
  int prom_mult;
  long long prom_msk;
  node() : mult(1), msk(0), prom_mult(1), prom_msk(0) {}
} t[N << 2];
int binpow(int a, int k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * a % base;
    a = (a * 1ll * a) % base;
    k >>= 1;
  }
  return res;
}
void seg_mult(int v, int tl, int tr, int l, int r, int mul, long long msk) {
  if (tl > tr || tl > r || l > tr) return;
  if (tl >= l && tr <= r) {
    t[v].prom_mult = (t[v].prom_mult * 1ll * mul) % base;
    mul = binpow(mul, tr - tl + 1);
    t[v].mult = (t[v].mult * 1ll * mul) % base;
    t[v].prom_msk |= msk;
    t[v].msk |= msk;
    return;
  }
  int tm = (tl + tr) >> 1;
  seg_mult(v + v, tl, tm, l, r, mul, msk);
  seg_mult(v + v + 1, tm + 1, tr, l, r, mul, msk);
  t[v].mult = ((t[v + v].mult * 1ll * t[v + v + 1].mult) % base) *
              binpow(t[v].prom_mult, tr - tl + 1) % base;
  t[v].msk = t[v + v].msk | t[v + v + 1].msk | t[v].prom_msk;
}
pair<int, long long> get_res(int v, int tl, int tr, int l, int r, int mul = 1,
                             long long msk = 0) {
  if (tl > tr || tl > r || l > tr) return {1, 0};
  if (tl >= l && tr <= r)
    return {(t[v].mult * 1ll * binpow(mul, tr - tl + 1)) % base,
            t[v].msk | msk};
  mul = (mul * 1ll * t[v].prom_mult) % base;
  msk |= t[v].prom_msk;
  int tm = (tl + tr) >> 1;
  pair<int, long long> resL = get_res(v + v, tl, tm, l, r, mul, msk),
                       resR = get_res(v + v + 1, tm + 1, tr, l, r, mul, msk);
  return {(resL.first * 1ll * resR.first) % base, resL.second | resR.second};
}
vector<int> primes;
vector<int> drin;
long long primemsk[MX];
bool is_prime(int x) {
  if (x < 2) return 0;
  if (x == 2) return 1;
  if (x % 2 == 0) return 0;
  for (int i = 3; i * i <= x; i += 2)
    if (x % i == 0) return 0;
  return 1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i < MX; i++) {
    if (is_prime(i))
      primes.push_back(i),
          drin.push_back(((i - 1) * 1ll * binpow(i, base - 2)) % base);
  }
  for (int i = 2; i < MX; i++) {
    for (long long j = 0; j < primes.size(); j++) {
      if (i % primes[j] == 0) primemsk[i] |= 1ll << j;
    }
  }
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    seg_mult(1, 0, n - 1, i, i, x, primemsk[x]);
  }
  while (m--) {
    string s;
    cin >> s;
    if (s[0] == 'T') {
      int l, r;
      cin >> l >> r;
      pair<int, long long> res = get_res(1, 0, n - 1, l - 1, r - 1);
      for (int i = 0; i < primes.size(); i++) {
        if ((res.second >> i) & 1)
          res.first = (res.first * 1ll * drin[i]) % base;
      }
      cout << res.first << "\n";
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      seg_mult(1, 0, n - 1, l - 1, r - 1, x, primemsk[x]);
    }
  }
}
