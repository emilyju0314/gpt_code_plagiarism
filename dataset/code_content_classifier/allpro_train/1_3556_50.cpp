#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class t, class u>
void chmax(t& first, u second) {
  if (first < second) first = second;
}
template <class t, class u>
void chmin(t& first, u second) {
  if (second < first) first = second;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<ll, ll>;
using vi = vc<ll>;
template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <class t>
ostream& operator<<(ostream& os, const vc<t>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
using uint = unsigned;
using ull = unsigned long long;
template <ll i, class T>
void print_tuple(ostream&, const T&) {}
template <ll i, class T, class H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "{";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << "}";
}
void print(ll x, ll suc = 1) {
  cout << x;
  if (suc == 1) cout << endl;
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(ll n, ll off = 0) {
  vi v(n);
  for (ll i = ll(0); i < ll(n); i++) v[i] = read() + off;
  return v;
}
template <class T>
void print(const vector<T>& v, ll suc = 1) {
  for (ll i = ll(0); i < ll(v.size()); i++)
    print(v[i], i == ll(v.size()) - 1 ? suc : 2);
}
string readString() {
  string s;
  cin >> s;
  return s;
}
template <class T>
T sq(const T& t) {
  return t * t;
}
void yes(bool ex = true) {
  cout << "Yes" << endl;
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No" << endl;
  if (ex) exit(0);
}
constexpr ll ten(ll n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
ll topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
ll topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
ll popcount(signed t) { return __builtin_popcount(t); }
ll popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(ll i) { return i && (i & -i) == i; }
bool inc(ll first, ll second, ll c) { return first <= second && second <= c; }
template <class t>
void mkuni(vc<t>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
ll rand_int(ll l, ll r) {
  static random_device rd;
  static mt19937 gen(rd());
  return uniform_int_distribution<ll>(l, r)(gen);
}
ll gcd(ll first, ll second) {
  return second ? gcd(second, first % second) : first;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  ll n, k;
  cin >> n >> k;
  vi first = readvi(n), e = readvi(n);
  ll g = 0;
  for (auto v : first) g = gcd(g, v);
  if (g == 1) {
    cout << 0 << endl;
    return 0;
  }
  vi p;
  for (ll i = 2; i * i <= g; i++) {
    if (g % i == 0) {
      p.push_back(i);
      while (g % i == 0) g /= i;
    }
  }
  if (g > 1) p.push_back(g);
  vc<pi> c;
  vi xs;
  for (ll i = ll(0); i < ll(n); i++) {
    ll x = 1;
    for (auto v : p)
      while (first[i] % v == 0) {
        first[i] /= v;
        x *= v;
      }
    c.emplace_back(e[i], x);
    xs.push_back(x);
  }
  sort(c.begin(), c.end());
  mkuni(xs);
  vi cnt(xs.size());
  ll m = p.size();
  vc<ll> d(1 << m, 0);
  vc<pi> f;
  for (auto w : c) {
    {
      ll i = lower_bound(xs.begin(), xs.end(), w.second) - xs.begin();
      if (cnt[i] == m) continue;
      cnt[i]++;
    }
    vi z(m, 1);
    for (ll i = ll(0); i < ll(p.size()); i++) {
      ll x = w.second;
      while (x % p[i] == 0) {
        z[i] *= p[i];
        x /= p[i];
      }
    }
    bool u = false;
    for (ll bit = ll(1); bit < ll(1 << m); bit++) {
      ll x = 1;
      for (ll i = ll(0); i < ll(m); i++)
        if (bit & 1 << i) x *= z[i];
      if (x <= k) {
        if (d[bit] < m) {
          d[bit]++;
          u = true;
        }
      }
    }
    if (u) f.push_back(w);
  }
  vvc<ll> dp(1 << m, vi(m + 1, inf / m));
  dp[0][0] = 0;
  for (auto w : f) {
    vi z(m, 1);
    for (ll i = ll(0); i < ll(p.size()); i++) {
      ll x = w.second;
      while (x % p[i] == 0) {
        z[i] *= p[i];
        x /= p[i];
      }
    }
    void(0);
    vi q;
    for (ll bit = ll(1); bit < ll(1 << m); bit++) {
      ll x = 1;
      for (ll i = ll(0); i < ll(m); i++)
        if (bit & 1 << i) x *= z[i];
      if (x <= k) {
        q.push_back(bit);
      }
    }
    for (ll bit = ll(1 << m) - 1; bit >= 0; bit--) {
      for (ll i = ll(1); i < ll(m + 1); i++) {
        for (auto v : q)
          if ((v & bit) == v) chmin(dp[bit][i], dp[bit - v][i - 1] + w.first);
      }
    }
  }
  ll ans = inf / m;
  for (ll i = ll(1); i < ll(m + 1); i++) chmin(ans, dp[(1 << m) - 1][i] * i);
  if (ans == inf / m) ans = -1;
  cout << ans << endl;
}
