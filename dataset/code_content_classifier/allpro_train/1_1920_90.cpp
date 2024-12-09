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
template <class t, size_t n>
ostream& operator<<(ostream& os, const array<t, n>& first) {
  return os << vc<t>(first.begin(), first.end());
}
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
template <class t>
void print(t x, ll suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
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
  cout << "Yes"
       << "\n";
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No"
       << "\n";
  if (ex) exit(0);
}
void possible(bool ex = true) {
  cout << "Possible"
       << "\n";
  if (ex) exit(0);
}
void impossible(bool ex = true) {
  cout << "Impossible"
       << "\n";
  if (ex) exit(0);
}
constexpr ll ten(ll n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
ll topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
ll topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
ll botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
ll botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
ll popcount(signed t) { return __builtin_popcount(t); }
ll popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(ll i) { return i && (i & -i) == i; }
ll mask(ll i) { return (ll(1) << i) - 1; }
bool inc(ll first, ll second, ll c) { return first <= second && second <= c; }
template <class t>
void mkuni(vc<t>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
ll rand_int(ll l, ll r) {
  static random_device rd;
  static mt19937_64 gen(rd());
  return uniform_int_distribution<ll>(l, r)(gen);
}
template <class t>
ll lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
template <class T, class F>
struct SegTree {
  vc<T> buf;
  ll s;
  const F f;
  const T g;
  SegTree(F ff, T gg) : f(ff), g(gg) {}
  void init(const vc<T>& d) {
    ll n = d.size();
    s = 1;
    while (s < n) s *= 2;
    buf.resize(s * 2, g);
    for (ll i = ll(0); i < ll(n); i++) buf[i + s] = d[i];
    for (ll i = ll(s) - 1; i >= ll(1); i--) u(i);
  }
  SegTree(const vc<T>& d, F ff, T gg) : f(ff), g(gg) { init(d); }
  void u(ll i) { buf[i] = f(buf[i * 2], buf[i * 2 + 1]); }
  void set(ll i, T t) {
    i += s;
    buf[i] = t;
    while (i >>= 1) u(i);
  }
  void upd(ll i, T t) {
    i += s;
    buf[i] = f(buf[i], t);
    while (i >>= 1) u(i);
  }
  T get(ll second, ll e, ll l, ll r, ll i) {
    if (e <= l || r <= second) return g;
    if (second <= l && r <= e) return buf[i];
    ll m = (l + r) / 2;
    return f(get(second, e, l, m, i * 2), get(second, e, m, r, i * 2 + 1));
  }
  T get(ll second, ll e) { return get(second, e, 0, s, 1); }
};
template <class T, class F>
SegTree<T, F> segtree(const vc<T>& d, F f, T g) {
  return SegTree<T, F>(d, f, g);
}
struct online_zalgo {
  vi s;
  vvc<ll> del;
  set<ll> pos;
  pair<ll, vi> append(ll c) {
    ll i = s.size();
    del.emplace_back();
    s.push_back(c);
    for (auto itr = pos.begin(); itr != pos.end(); itr = pos.erase(itr)) {
      ll j = *itr;
      if (s[i - j] == s[i]) break;
      del[i].push_back(j);
    }
    if (pos.size()) {
      ll off = *pos.begin();
      for (auto k : del[i - off]) {
        auto itr = pos.find(k + off);
        assert(itr != pos.end());
        del[i].push_back(*itr);
        pos.erase(itr);
      }
    }
    ll ad = -1;
    if (i && s[0] == s[i]) {
      pos.insert(i);
      ad = i;
    }
    return make_pair(ad, del[i]);
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  ull ans = 0;
  ull ans26 = 0;
  ll mn = inf;
  auto seg = segtree(
      vi(n), [](ll x, ll y) { return min(x, y); }, inf);
  ll cur = 0;
  map<ll, ll> valcnt;
  online_zalgo oz;
  for (ll i = ll(0); i < ll(n); i++) {
    char c = readString()[0];
    ll w = 0;
    cin >> w;
    c = 'a' + (c - 'a' + ans26) % 26;
    w ^= (ans & mask(30));
    chmin(mn, w);
    seg.set(i, w);
    {
      ll sum = 0;
      for (auto itr = valcnt.end(); itr != valcnt.begin();
           itr = valcnt.erase(itr)) {
        --itr;
        if (itr->first <= w) break;
        cur -= itr->first * itr->second;
        sum += itr->second;
      }
      valcnt[w] += sum;
      cur += sum * w;
    }
    ll ad;
    vi rem;
    tie(ad, rem) = oz.append(c);
    if (ad != -1) {
      cur += w;
      valcnt[w]++;
    }
    for (auto j : rem) {
      ll z = seg.get(j, i + 1);
      valcnt[z]--;
      cur -= z;
    }
    ans += cur;
    ans26 += cur;
    ans += mn;
    ans26 += mn;
    cout << ans << "\n";
    ans26 %= 26;
  }
}
