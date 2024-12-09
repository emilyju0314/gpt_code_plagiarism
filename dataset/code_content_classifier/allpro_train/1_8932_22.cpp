#include <bits/stdc++.h>
using namespace std;
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const long long inf = 1000000001;
const long long INF = (long long)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
vector<long long> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vector<long long> dx2 = {1, 1, 0, -1, -1, -1, 0, 1},
                  dy2 = {0, 1, 1, 1, 0, -1, -1, -1};
const long long MOD = 1000000007;
vector<vector<pair<long long, long long>>> G;
vector<long long> p;
vector<map<long long, long long>> mp;
vector<long long> wst(32);
vector<long long> w;
vector<vector<long long>> ww;
long long zero;
bitset<111111> visited;
vector<long long> sum;
bool dfs(long long now, long long par, long long x) {
  visited[now] = true;
  sum[now] = x;
  for (pair<long long, long long> ch : G[now]) {
    long long v = ch.first;
    if (v == par) continue;
    if (v == p[now]) continue;
    long long y = ch.second;
    if (visited[v]) {
      if (now < v) {
        long long temp = x ^ sum[v] ^ y;
        if (wst[temp] < 2) {
          w.push_back(temp);
          wst[temp]++;
          if (wst[temp] == 2) {
            return false;
          }
        }
      }
    } else {
      bool temp = dfs(v, now, x ^ y);
      if (not temp) return false;
    }
  }
  return true;
}
vector<vector<long long>> basis;
map<vector<long long>, long long> basis2idx;
long long max_bit(long long x) {
  if (x == 0) return 0;
  long long res = 1 << 5;
  while ((x & res) == 0) {
    res >>= 1;
  }
  return res;
}
vector<vector<pair<long long, bool>>> hyou(
    400,
    vector<pair<long long, bool>>(400, pair<long long, long long>(-1, false)));
tuple<vector<long long>, bool> merge(vector<long long> &a, vector<long long> b,
                                     bool early_stop) {
  vector<long long> v;
  for (long long i = 0; i < (a.size()); i++) v.push_back(a[i]);
  for (long long j = 0; j < (b.size()); j++) v.push_back(b[j]);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (long long i = 0; i < (v.size()); i++) {
    if (v[i] == 0) continue;
    long long mask = max_bit(v[i]);
    for (long long j = 0; j < (v.size()); j++) {
      if (i == j) continue;
      if (v[j] & mask) {
        v[j] = v[j] ^ v[i];
        if (early_stop and v[j] == 0) return {v, true};
      }
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  if (v.size() == 0) {
    return {v, false};
  }
  bool flag = false;
  if (v.back() == 0) flag = true;
  while (v.size() > 0 and v.back() == 0) {
    v.pop_back();
  }
  return {v, flag};
}
tuple<long long, bool> merge2(long long t1, long long t2, bool early_stop) {
  if (hyou[t1][t2].first != -1) {
    return {hyou[t1][t2].first, hyou[t1][t2].second};
  }
  vector<long long> v;
  for (long long i = 0; i < (basis[t1].size()); i++) v.push_back(basis[t1][i]);
  for (long long j = 0; j < (basis[t2].size()); j++) v.push_back(basis[t2][j]);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (long long i = 0; i < (v.size()); i++) {
    if (v[i] == 0) continue;
    long long mask = max_bit(v[i]);
    for (long long j = 0; j < (v.size()); j++) {
      if (i == j) continue;
      if (v[j] & mask) {
        v[j] = v[j] ^ v[i];
        if (early_stop and v[j] == 0) {
          hyou[t1][t2] = hyou[t2][t1] = {basis2idx[v], true};
          return {basis2idx[v], true};
        }
      }
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  if (v.size() == 0) {
    return {0, false};
  }
  bool flag = false;
  if (v.back() == 0) flag = true;
  while (v.size() > 0 and v.back() == 0) {
    v.pop_back();
  }
  hyou[t1][t2] = hyou[t2][t1] = {basis2idx[v], flag};
  return {basis2idx[v], flag};
}
void make_basis() {
  basis.push_back(vector<long long>(0));
  basis2idx[basis[0]] = 0;
  long long cnt = 1;
  for (long long i = 1; i <= (31); i++) {
    vector<long long> v1(1, i);
    for (long long j = 0; j < (basis.size()); j++) {
      vector<long long> v2 = basis[j];
      auto [v, flag] = merge(v1, v2, false);
      if (basis2idx.count(v) == 0) {
        basis.push_back(v);
        basis2idx[v] = cnt++;
      }
      long long t1 = basis2idx[v1], t2 = basis2idx[v2];
      hyou[t1][t2] = hyou[t2][t1] = {basis2idx[v], flag};
    }
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ;
  make_basis();
  cerr << "basis.size()"
       << ": " << basis.size() << endl;
  ;
  long long n, m;
  cin >> n >> m;
  G.resize(n);
  p.resize(n);
  fill(p.begin(), p.end(), -1);
  mp.resize(n);
  sum.resize(n);
  for (long long i = 0; i < (m); i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    G[u].push_back(pair<long long, long long>(v, w));
    G[v].push_back(pair<long long, long long>(u, w));
    mp[u][v] = w;
    mp[v][u] = w;
  }
  for (long long i = 0; i < (n); i++) sort(G[i].begin(), G[i].end());
  for (long long u = 0; u < (n); u++) {
    if (G[u][0].first != 0) continue;
    for (long long j = 0; j < G[u].size(); j++) {
      long long v = G[u][j].first;
      if (v == 0) continue;
      if (G[v][0].first == 0) {
        p[u] = v;
        p[v] = u;
      }
    }
  }
  vector<long long> dp(basis.size()), dp2(basis.size());
  dp[0] = 1;
  visited[0] = true;
  for (long long i = 0; i < (G[0].size()); i++) {
    long long u = G[0][i].first;
    if (visited[u]) continue;
    long long v = p[u];
    if (v != -1) {
      zero = mp[u][v] ^ mp[0][u] ^ mp[0][v];
    } else {
      zero = -1;
    }
    w.clear();
    fill(wst.begin(), wst.end(), 0);
    bool fff = dfs(u, 0, G[0][i].second);
    if (v != -1) {
      bool fff2 = dfs(v, 0, mp[0][v]);
      if (not fff2) fff = false;
    }
    if (not fff) continue;
    sort(w.begin(), w.end());
    if (w.size() > 0 and w[0] == 0) {
      continue;
    }
    auto [w2, flag] = merge(w, vector<long long>(0), true);
    if (flag == true) continue;
    fill(dp2.begin(), dp2.end(), 0);
    long long t2 = basis2idx[w2];
    long long t0 = basis2idx[vector<long long>(1, zero)];
    for (long long i = 0; i < (dp.size()); i++) {
      if (dp[i] == 0) continue;
      (dp2[i] += dp[i]) %= MOD;
      if (zero == -1) {
        auto [w3, flag] = merge2(i, t2, true);
        if (flag) continue;
        (dp2[w3] += dp[i]) %= MOD;
      } else {
        auto [w3, flag] = merge2(i, t2, true);
        if (flag) continue;
        (dp2[w3] += dp[i] * 2) %= MOD;
        if (zero == 0) continue;
        auto [w4, flag2] = merge2(w3, t0, true);
        if (flag2) continue;
        (dp2[w4] += dp[i]) %= MOD;
      }
    }
    swap(dp, dp2);
  }
  long long ans = 0;
  for (long long i = 0; i < (basis.size()); i++) {
    ans += dp[i];
  }
  cout << ans % MOD << endl;
}
