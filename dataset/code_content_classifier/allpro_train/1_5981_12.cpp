#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int pp[] = {2, 3, 5, 7, 11, 13, 31};
int idx;
ll n, m, b, p, e, pr[63];
map<ll, ll> mp;
vector<ll> ans;
inline ll mul(ll a, ll b, ll P) {
  ll t = a * b - ll(ld(a) * ld(b) / ld(P) + 0.5) * P;
  if (t >= P) t -= P;
  if (t < 0) t += P;
  return t;
}
inline ll qpow(ll a, ll b, ll P) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = mul(ret, a, P);
    a = mul(a, a, P);
    b >>= 1;
  }
  return ret;
}
bool MR(ll n) {
  for (int i = 0; i < 7; i++)
    if (n == pp[i]) return 1;
  if (!(n & 1)) return 0;
  ll r = n - 1;
  int kk = 0;
  while (!(r & 1)) r >>= 1, ++kk;
  for (int i = 0; i < 7; i++) {
    ll x = qpow(pp[i], r, n), y;
    for (int i = 0; i < kk; i++, x = y) {
      y = mul(x, x, n);
      if (y == 1 && x != 1 && x != n - 1) return 0;
    }
    if (y != 1) return 0;
  }
  return 1;
}
inline ll ff(ll x, ll n) { return mul(x, x, n) + 1; }
ll gcd(ll x, ll y) { return !y ? x : gcd(y, x % y); }
ll div(ll n) {
  ll x = rand() % n + 1, y = ff(x, n);
  ll kk = 1;
  int tt = 0;
  while (x != y) {
    ll t = kk;
    kk = mul(kk, abs(y - x), n);
    if (!kk) {
      t = gcd(t, n);
      return t;
    }
    if (tt == 50) {
      tt = 0;
      t = gcd(kk, n);
      if (t > 1) return t;
    }
    x = ff(x, n);
    y = ff(ff(y, n), n);
    ++tt;
  }
  ll t = gcd(kk, n);
  if (t > 1) return t;
  return -1;
}
void PR(ll n) {
  if (n == 1) return;
  if (MR(n)) {
    pr[++idx] = n;
    return;
  }
  ll x;
  do x = div(n);
  while (x == -1);
  PR(x);
  PR(n / x);
}
vector<ll> fac(ll n) {
  vector<ll> vv;
  if (n == 1) return vv;
  while (!(n & 1)) pr[++idx] = 2, n >>= 1;
  PR(n);
  for (int i = 1; i <= idx; i++) vv.push_back(pr[i]);
  return vv;
}
void facm() {
  for (ll t = 2; t * t * t <= m; t++)
    if (!(m % t)) {
      p = t;
      e = 0;
      ll v = m;
      while (v > 1) v /= p, ++e;
      return;
    }
  ll t = sqrt(m);
  for (ll i = max(0ll, t - 10); i <= t + 10; i++)
    if (i * i == m) {
      p = i;
      e = 2;
      return;
    }
  p = m;
  e = 1;
}
int main() {
  ios::sync_with_stdio(false);
  srand(time(0));
  cin >> n >> m >> b;
  facm();
  vector<ll> f = fac(p - 1);
  for (auto t : f) ++mp[t];
  if (e > 1) mp[p] += e - 1;
  if (b % p == 0) b = 1;
  ll phi = m / p * (p - 1), ord = phi;
  for (auto t : mp)
    while (!(ord % t.first) && qpow(b, ord / t.first, m) == 1) ord /= t.first;
  if (phi - ord >= n) {
    ll cnt = 0;
    while (int(ans.size()) < n) {
      ll vv = cnt++;
      if (!(vv % p)) continue;
      if (qpow(vv, ord, m) != 1)
        ans.push_back(vv);
      else if (p == 2 && e >= 3) {
        if (ord >= 2 && qpow(vv, ord / 2, m) == 1) {
          if (vv % 8 != 1) ans.push_back(vv);
        } else if (vv % 8 != b % 8)
          ans.push_back(vv);
      }
    }
    for (auto i : ans) cout << i << ' ';
  } else
    cout << -1 << endl;
  return 0;
}
