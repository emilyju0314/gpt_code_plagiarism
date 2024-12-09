#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int N = 5e5 + 5, M = 998244353, INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
void Main();
void debug() { cerr << endl; }
template <typename T, typename... Ts>
void debug(T x, Ts... y) {
  cerr << "\033[31m" << x << "\033[0m";
  if (sizeof...(y) > 0) cerr << ' ';
  debug(y...);
}
template <typename T>
void debug(const T& a, int l, int r, char c) {
  for (int i = l; i <= r; ++i)
    cerr << "\033[31m" << a[i] << "\033[0m" << (i == r ? '\n' : c);
}
void print() { cout << '\n'; }
template <typename T, typename... Ts>
void print(T x, Ts... y) {
  cout << x;
  if (sizeof...(y) > 0) cout << ' ';
  print(y...);
}
template <typename T>
void print(const T& a, int l, int r, char c) {
  for (int i = l; i <= r; ++i) cout << a[i] << (i == r ? '\n' : c);
}
void input() {}
template <typename T, typename... Ts>
void input(T& x, Ts&... y) {
  cin >> x;
  input(y...);
}
template <typename T>
void input(T* a, int l, int r) {
  for (int i = l; i <= r; ++i) cin >> a[i];
}
template <typename T>
void input(vector<T>& a, int l, int r) {
  for (int i = l; i <= r; ++i) cin >> a[i];
}
template <typename T>
void Max(T& a, T b) {
  if (a < b) a = b;
}
template <typename T>
void Min(T& a, T b) {
  if (a > b) a = b;
}
template <typename T>
void Add(T& a, T b) {
  a += b;
  if (a > M) a -= M;
  if (a < 0) a += M;
}
template <typename T>
void Mul(T& a, T b) {
  a = a * b % M;
}
template <typename T>
T Mod(T a) {
  return (a % M + M) % M;
}
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Main();
}
template <typename T, int N, T oo>
struct Dinic {
  int n, s, t;
  struct edge {
    int v;
    T w;
    int rev;
  };
  vector<edge> G[N];
  void add(int u, int v, T w) {
    G[u].push_back({v, w, (int)G[v].size()});
    G[v].push_back({u, 0, (int)G[u].size() - 1});
  }
  void init(int n_) {
    n = n_;
    for (int i = 0; i <= n; i++) G[i].clear();
  }
  int dis[N], cur[N];
  bool bfs() {
    fill(dis, dis + n + 1, -1);
    fill(cur, cur + n + 1, 0);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (edge& e : G[u])
        if (e.w && dis[e.v] == -1) {
          dis[e.v] = dis[u] + 1;
          q.push(e.v);
        }
    }
    return dis[t] != -1;
  }
  T dfs(int u, T f) {
    if (u == t) return f;
    T used = 0;
    for (int& i = cur[u]; i < (int)G[u].size() && f > used; i++) {
      int v = G[u][i].v;
      T &w = G[u][i].w, &revw = G[v][G[u][i].rev].w;
      if (dis[v] != dis[u] + 1 || w <= 0) continue;
      T t = dfs(v, min(f - used, w));
      used += t;
      w -= t;
      revw += t;
    }
    return used;
  }
  T maxflow(int s_, int t_) {
    s = s_, t = t_;
    T ans = 0;
    while (bfs()) ans += dfs(s, oo);
    return ans;
  }
};
Dinic<int, 205, INF> F;
pii a[N][2];
vector<int> X, Y;
void Main() {
  int n, m;
  input(n, m);
  for (int i = 1; i <= m; ++i) {
    input(a[i][0].first, a[i][0].second, a[i][1].first, a[i][1].second);
    ++a[i][1].first;
    ++a[i][1].second;
    X.push_back(a[i][0].first);
    X.push_back(a[i][1].first);
    Y.push_back(a[i][0].second);
    Y.push_back(a[i][1].second);
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  Y.erase(unique(Y.begin(), Y.end()), Y.end());
  auto id = [](int x, vector<int>& X) {
    return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
  };
  const int s = X.size() + Y.size() + 1, t = s + 1;
  F.init(t);
  for (int i = 1; i <= m; ++i) {
    int l1 = id(a[i][0].first, X);
    int l2 = id(a[i][0].second, Y);
    int r1 = id(a[i][1].first, X);
    int r2 = id(a[i][1].second, Y);
    a[i][0].first = l1;
    a[i][0].second = r1;
    a[i][1].first = l2;
    a[i][1].second = r2;
    for (int i = l1; i < r1; ++i)
      for (int j = l2; j < r2; ++j) {
        F.add(i, j + X.size(), INF);
      }
  }
  for (int i = 0; i < (int)X.size() - 1; ++i) F.add(s, i + 1, X[i + 1] - X[i]);
  for (int i = 0; i < (int)Y.size() - 1; ++i)
    F.add(i + 1 + X.size(), t, Y[i + 1] - Y[i]);
  print(F.maxflow(s, t));
}
