#include <bits/stdc++.h>
#define MOD (int)(998244353)
using namespace std;

struct NTT {
  int base, mod, maxb, root;
  vector<int> rv, roots, invr;
  NTT(int mo = 998244353)
      : base(1), mod(mo), rv({0, 1}), roots({0, 1}), invr({0, 1}) {
    assert(mod >= 3 && mod & 1);
    int tmp = mod - 1;
    maxb = 0;
    while (!(tmp & 1)) tmp >>= 1, ++maxb;
    root = 2;
    while (mpow(root, (mod - 1) >> 1) == 1) ++root;
    assert(mpow(root, mod - 1) == 1);
    root = mpow(root, (mod - 1) >> maxb);
  }

  inline int mpow(int x, int n) {
    int res = 1;
    while (n) {
      if (n & 1) res = mul(res, x);
      x = mul(x, x);
      n >>= 1;
    }
    return res;
  }

  inline int inv(int x) { return mpow(x, mod - 2); }

  inline int add(int x, int y) {
    if ((x += y) >= mod) x -= mod;
    return x;
  }

  inline int mul(int x, int y) { return (int)(1LL * x * y % mod); }

  void ensure_base(int nb) {
    if (nb <= base) return;
    rv.resize(1 << nb);
    roots.resize(1 << nb);
    invr.resize(1 << nb);
    for (int i = 0; i < (1 << nb); ++i)
      rv[i] = (rv[i >> 1] >> 1) + ((i & 1) << (nb - 1));
    assert(nb <= maxb);
    while (base < nb) {
      int z = mpow(root, 1 << (maxb - 1 - base)), invz = inv(z);
      for (int i = 1 << (base - 1); i < (1 << base); ++i) {
        roots[i << 1] = roots[i];
        roots[(i << 1) + 1] = mul(roots[i], z);
        invr[i << 1] = invr[i];
        invr[(i << 1) + 1] = mul(invr[i], invz);
      }
      ++base;
    }
  }
  void ntt(vector<int> &a, int n, bool sg = 0) {
    assert((n & (n - 1)) == 0);
    for (int i = 0; i < n; ++i)
      if (i < rv[i]) swap(a[i], a[rv[i]]);
    for (int k = 1; k < n; k <<= 1)
      for (int i = 0; i < n; i += 2 * k)
        for (int j = 0; j < k; ++j) {
          int z = mul(a[i + j + k], (sg ? roots[j + k] : invr[j + k]));
          a[i + j + k] = add(a[i + j], mod - z);
          a[i + j] = add(a[i + j], z);
        }
    int invn = inv(n);
    if (sg)
      for (int i = 0; i < n; ++i) a[i] = mul(a[i], invn);
  }
  template <class T>
  vector<T> multiply(const vector<T> &a, const vector<T> &b) {
    int need = a.size() + b.size() - 1;
    int nb = 1;
    while ((1 << nb) < need) ++nb;
    ensure_base(nb);
    int sz = 1 << nb;
    vector<int> fa(sz, 0), fb(sz, 0);
    for (int i = 0; i < sz; ++i) {
      if (i < a.size()) fa[i] = a[i];
      if (i < b.size()) fb[i] = b[i];
    }
    ntt(fa, sz);
    ntt(fb, sz);
    for (int i = 0; i < sz; ++i) fa[i] = mul(fa[i], fb[i]);
    ntt(fa, sz, 1);
    vector<T> res(need);
    for (int i = 0; i < need; ++i) res[i] = fa[i];
    return res;
  }
};

// as + bt = GCD(a,b) a,b:const s,t:var(any)
// return GCD(a,b)
long long extGCD(long long a, long long b, long long &s, long long &t) {
  s = 1, t = 0;
  long long u = 0, v = 1;
  while (b) {
    long long tmp = a / b;
    a -= b * tmp;
    s -= u * tmp;
    t -= v * tmp;
    swap(s, u);
    swap(t, v);
    swap(a, b);
  }
  return a;
}
// (mod)x+ay=1, calculate y -> a^-1 (mod m) (a,m : coprime)
long long calcinv(long long a, long long m) {
  long long s, t;
  extGCD(a, m, s, t);
  return (s + m) % m;
}

using P = pair<int, int>;
int n;
vector<vector<long long>> memo;
priority_queue<P, vector<P>, greater<P>> pq;
NTT ntt;

int main() {
  cin >> n;
  {
    map<int, int> mp;
    for (int i = 0; i < 2 * n; ++i) {
      int x;
      cin >> x;
      ++mp[x];
    }
    for (auto [_, p] : mp) {
      vector<long long> v(1, 1);
      long long now = 1, cnt = 1;
      for (long long i = p; i > 1;) {
        (now *= i--) %= MOD;
        (now *= i--) %= MOD;
        (now *= calcinv(2 * cnt++, MOD)) %= MOD;
        v.push_back(now);
      }
      pq.push(P(v.size(), memo.size()));
      memo.push_back(v);
    }
  }
  while (pq.size() > 1) {
    P l = pq.top(), r;
    pq.pop();
    r = pq.top();
    pq.pop();
    memo[l.second] = ntt.multiply(memo[l.second], memo[r.second]);
    pq.push(P(memo[l.second].size(), l.second));
  }
  int id = pq.top().second;
  vector<long long> oddf(2, 1);
  for (int i = 3; i <= 2 * n; i += 2) {
    long long now = oddf.back() * i % MOD;
    oddf.push_back(now);
  }
  long long res = 0, len = memo[id].size();
  for (int i = 0; i < len; ++i) {
    long long now = memo[id][i] * oddf[n - i] % MOD;
    if (i & 1)
      (res += MOD - now) %= MOD;
    else
      (res += now) %= MOD;
  }
  cout << res << endl;
  return 0;
}
