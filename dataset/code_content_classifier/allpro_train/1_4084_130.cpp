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
template <class N, class E>
struct treedp {
  const vvc<E>& g;
  vc<N> first, second, res;
  void dfs1(ll v, ll p) {
    first[v].init(v);
    E up;
    for (auto e : g[v])
      if (e != p) {
        dfs1(e, v);
        second[e] = first[v];
        first[v] = first[v] + first[e];
      } else
        up = e;
    if (p != -1) first[v] = first[v].up(up);
  }
  void dfs2(ll v, ll p, N cur) {
    for (ll i = ll(g[v].size()) - 1; i >= ll(0); i--) {
      auto e = g[v][i];
      if (e == p) continue;
      dfs2(e, v, (cur + second[e]).up(e));
      cur = cur + first[e];
    }
    res[v] = cur;
  }
  treedp(const vvc<E>& gg)
      : g(gg), first(g.size()), second(g.size()), res(g.size()) {
    dfs1(0, -1);
    N tmp;
    tmp.init(0);
    dfs2(0, -1, tmp);
  }
};
struct E {
  ll to, cost;
  operator ll() const { return to; }
};
vi wt;
struct N {
  ll top, c, s;
  void init(ll v) {
    top = c = wt[v];
    s = 0;
  }
  N up(E e) const { return N{wt[e.to], c + wt[e.to], s + c * e.cost}; }
  N operator+(const N& r) const {
    assert(top == r.top);
    return N{top, c + r.c - top, s + r.s};
  }
};
const ll vmax = 5010;
bool pri[vmax];
void initprime() {
  for (ll i = ll(2); i < ll(vmax); i++) pri[i] = 1;
  for (ll i = ll(2); i < ll(vmax); i++)
    if (pri[i])
      for (ll j = i * 2; j < vmax; j += i) pri[j] = 0;
}
vi factors[vmax];
void initfactor() {
  for (ll i = ll(2); i < ll(vmax); i++)
    if (pri[i])
      for (ll j = i; j < vmax; j += i) {
        ll x = j;
        while (x % i == 0) {
          factors[j].push_back(i);
          x /= i;
        }
      }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  initprime();
  initfactor();
  vi cnt(vmax);
  {
    ll n;
    cin >> n;
    if (n < 0) {
      n = -n;
      for (ll i = ll(0); i < ll(n); i++) cnt[max(i, ll(1))]++;
    } else {
      for (ll _ = ll(0); _ < ll(n); _++) {
        cnt[max(ll(1), read())]++;
      }
    }
  }
  vi ps;
  for (ll i = ll(0); i < ll(vmax); i++)
    if (pri[i]) ps.push_back(i);
  ll s = ps.size();
  auto getidx = [&](ll p) { return s - 1 - lwb(ps, p); };
  void(0);
  auto lca = [&](const vi& first, const vi& second) {
    for (ll i = ll(0); i < ll(s); i++)
      if (first[i] != second[i]) {
        vi res(s);
        for (ll j = ll(0); j < ll(i); j++) res[j] = first[j];
        res[i] = min(first[i], second[i]);
        return res;
      }
    return first;
  };
  auto dist = [&](const vi& first, const vi& second) {
    ll res = 0;
    for (ll i = ll(0); i < ll(s); i++) res += second[i] - first[i];
    return res;
  };
  auto asds = [&](const vi& first, const vi& second) {
    for (ll i = ll(0); i < ll(s); i++)
      if (first[i] != second[i]) {
        if (first[i] > second[i]) return false;
        for (ll j = ll(i + 1); j < ll(s); j++)
          if (first[j]) return false;
        return true;
      }
    void(0);
    assert(false);
  };
  ll n = 0;
  vc<tuple<ll, ll, ll>> es;
  vc<pair<vi, ll>> st;
  auto ae = [&](ll i) {
    es.emplace_back(st[i].second, st[i + 1].second,
                    dist(st[i].first, st[i + 1].first));
  };
  vi cur(s);
  for (ll i = ll(0); i < ll(vmax); i++) {
    for (auto f : factors[i]) cur[getidx(f)]++;
    if (cnt[i]) {
      void(0);
      void(0);
      if (st.size()) {
        auto z = lca(st.back().first, cur);
        void(0);
        auto itr = lower_bound(st.begin(), st.end(), pair<vi, ll>(z, -1));
        if (itr == st.end() || itr->first != z) {
          st.insert(itr, make_pair(z, n++));
          wt.push_back(0);
        }
        while (!asds(st.back().first, cur)) {
          ae(ll(st.size()) - 2);
          st.pop_back();
        }
      }
      st.emplace_back(cur, n++);
      wt.push_back(cnt[i]);
    }
  }
  for (ll i = ll(0); i < ll(ll(st.size()) - 1); i++) ae(i);
  {
    vvc<E> tr(n);
    for (auto e : es) {
      ll first, second, c;
      tie(first, second, c) = e;
      tr[first].push_back({second, c});
      tr[second].push_back({first, c});
    }
    auto dp = treedp<N, E>(tr).res;
    ll ans = inf;
    for (ll i = ll(0); i < ll(n); i++) chmin(ans, dp[i].s);
    cout << ans << endl;
  }
}
