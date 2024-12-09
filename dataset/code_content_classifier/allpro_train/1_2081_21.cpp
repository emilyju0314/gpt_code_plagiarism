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
ll maxflow;
struct ysp {
  map<ll, ll> left, right;
  priority_queue<pi, vc<pi>, greater<pi>> qs;
  ll lo, ro, qo;
  ysp() : lo(0), ro(0), qo(0) {}
  ll size() { return left.size() + right.size(); }
  void addqleft(ll x) {
    void(0);
    auto itr = right.lower_bound(x + lo - ro);
    if (itr != right.end()) {
      ll d = itr->first + ro - (x + lo);
      assert(d % 2 == 0);
      assert(d >= 0);
      qs.emplace(d / 2 - qo, x);
    }
  }
  void addqright(ll x) {
    void(0);
    auto itr = left.upper_bound(x + ro - lo);
    if (itr != left.begin()) {
      --itr;
      ll d = x + ro - (itr->first + lo);
      assert(d % 2 == 0);
      assert(d >= 0);
      qs.emplace(d / 2 - qo, itr->first);
    }
  }
  void insertleft(ll x, ll v) {
    if (v == 0) return;
    assert(v > 0);
    x -= lo;
    left[x] += v;
    addqleft(x);
  }
  void insertright(ll x, ll v) {
    if (v == 0) return;
    assert(v > 0);
    x -= ro;
    right[x] += v;
    addqright(x);
  }
  void Expand(ll w) {
    void(0);
    void(0);
    while (w && qs.size()) {
      pi z = qs.top();
      qs.pop();
      z.first += qo;
      assert(z.first >= 0);
      void(0);
      ll u = min(w, z.first);
      void(0);
      w -= u;
      z.first -= u;
      qo -= u;
      lo += u;
      ro -= u;
      if (z.first == 0) {
        void(0);
        auto l = left.find(z.second);
        auto r = right.find(z.second + lo - ro);
        if (l != left.end() && r != right.end()) {
          ll y = min(l->second, r->second);
          maxflow += y;
          ll f = -1;
          l->second -= y;
          if (l->second == 0)
            left.erase(l);
          else
            f = 0;
          r->second -= y;
          if (r->second == 0)
            right.erase(r);
          else
            f = 1;
          if (f == 0) {
            addqleft(l->first);
          } else if (f == 1) {
            addqright(r->first);
          } else {
            l = left.upper_bound(z.second);
            if (l != left.begin()) addqleft(prev(l)->first);
          }
        }
      } else
        qs.emplace(z.first - qo, z.second);
    }
    qo -= w;
    lo += w;
    ro -= w;
  }
  void show() {}
};
void merge(ysp& first, ysp& second) {
  if (first.size() < second.size()) swap(first, second);
  for (auto z : second.left) first.insertleft(z.first + second.lo, z.second);
  for (auto z : second.right) first.insertright(z.first + second.ro, z.second);
}
const ll nmax = 100010;
vc<pi> t[nmax];
vc<pi> obs[nmax];
ysp buf[nmax];
void dfs(ll v, ll p) {
  buf[v] = ysp();
  sort(obs[v].begin(), obs[v].end());
  for (auto z : obs[v]) {
    buf[v].insertright(z.first * 2, z.second);
    buf[v].insertleft(z.first * 2 + 2, z.second);
  }
  for (auto e : t[v])
    if (e.first != p) {
      dfs(e.first, v);
      buf[e.first].Expand(e.second * 2);
      merge(buf[v], buf[e.first]);
    }
  void(0);
  void(0);
  buf[v].show();
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  const ll vmax = ten(9);
  ll n;
  cin >> n;
  for (ll _ = ll(0); _ < ll(n - 1); _++) {
    ll u, v, l;
    cin >> u >> v >> l;
    u--;
    v--;
    l *= vmax;
    l -= 2;
    t[u].emplace_back(v, l);
    t[v].emplace_back(u, l);
  }
  ll ans = 0;
  ll k;
  cin >> k;
  for (ll _ = ll(0); _ < ll(k); _++) {
    ll d, f, p;
    cin >> d >> f >> p;
    d *= vmax;
    p--;
    obs[p].emplace_back(d, f);
    ans += f;
  }
  dfs(0, -1);
  void(0);
  buf[0].show();
  buf[0].Expand(inf);
  void(0);
  if (0) {
    for (ll _ = ll(0); _ < ll(10); _++) {
      ll tmp = maxflow;
      maxflow = 0;
      ll r = rand_int(0, n - 1);
      dfs(r, -1);
      buf[r].Expand(inf);
      void(0);
      assert(tmp == maxflow);
    }
  }
  cout << ans - maxflow << endl;
}
