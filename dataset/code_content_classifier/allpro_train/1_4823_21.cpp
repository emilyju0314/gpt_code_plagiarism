#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

template <typename T>
struct Dinic {
  const T INF;
  struct edge {
    int to;
    T cap;
    int rev;
  };

  vector<vector<edge>> g;
  vector<int> level;
  vector<int> itr;


  Dinic (int V) : INF(numeric_limits<T>::max()) {
    g.resize(V);
  }

  void add_edge(int from, int to, T cap = 1) {
    g[from].emplace_back((edge){to, cap, (int)g[to].size()});
    g[to].emplace_back((edge){from, 0, (int)g[from].size() - 1});
  }

  bool bfs(int s, int t) {
    level.assign(g.size(), -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int u = que.front(); que.pop();
      for (auto &e : g[u]) {
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[u] + 1;
          que.push(e.to);
        }
      }
    }
    return level[t] != -1;
  }

  T dfs(int u, int t, T flow) {
    if (u == t) return flow;
    for (int &i = itr[u]; i < g[u].size(); i++) {
      edge &e = g[u][i];
      if (e.cap > 0 && level[u] < level[e.to]) {
        T d = dfs(e.to, t, min(flow, e.cap));
        if (d > 0) {
          e.cap -= d;
          g[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  T max_flow(int s, int t) {
    T flow = 0;
    while (bfs(s, t)) {
      itr.assign(g.size(), 0);
      T f = 0;
      while ((f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  Dinic<int> mf_g(n * m + 2);
  int S = n * m, T = n * m + 1;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i + 1 < n && s[i][j] == '.' && s[i + 1][j] == '.') {
        if ((i + j) % 2) mf_g.add_edge(i * m + j, (i + 1) * m + j);
        else mf_g.add_edge((i + 1) * m + j, i * m + j);
      }
      if (j + 1 < m && s[i][j] == '.' && s[i][j + 1] == '.') {
        if ((i + j) % 2) mf_g.add_edge(i * m + j, i * m + j + 1);
        else mf_g.add_edge(i * m + j + 1, i * m + j);
      }

      if ((i + j) % 2) mf_g.add_edge(S, i * m + j);
      else mf_g.add_edge(i * m + j, T);
    }
  }

  cout << mf_g.max_flow(S, T) << endl;
  
  for (int i = 0; i < n * m; i++) {
    int x1 = i / m, y1 = i % m;
    if ((x1 + y1) % 2 == 0) continue;
    for (auto e : mf_g.g[i]) {
      int x2 = e.to / m, y2 = e.to % m;
      if (e.to >= n * m) continue;
      if (e.cap == 0) {
        if (x1 == x2) s[x1][min(y1, y2)] = '>', s[x2][max(y1, y2)] = '<';
        else s[min(x1,x2)][y1] = 'v', s[max(x1, x2)][y2] = '^'; 
      }
    }
  }
  
  for (auto e : s) cout << e << endl;
  return 0; 
}
