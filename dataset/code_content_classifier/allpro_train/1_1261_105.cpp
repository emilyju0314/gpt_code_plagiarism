#include <bits/stdc++.h>
const double EPS = 1e-4;
const long long int MOD = 1000000007ll;
const long long int HASHMOD[2] = {1000000009ll, 1100000009ll};
const double PI = 3.14159265359;
int INF = 2147483645;
long long int INFINF = 9223372036854775807;
template <class T>
T Max2(T a, T b) {
  return a < b ? b : a;
}
template <class T>
T Min2(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T Max3(T a, T b, T c) {
  return Max2(Max2(a, b), c);
}
template <class T>
T Min3(T a, T b, T c) {
  return Min2(Min2(a, b), c);
}
template <class T>
T Max4(T a, T b, T c, T d) {
  return Max2(Max2(a, b), Max2(c, d));
}
template <class T>
T Min4(T a, T b, T c, T d) {
  return Min2(Min2(a, b), Min2(c, d));
}
using namespace std;
long long int bit_count(long long int _x) {
  long long int _ret = 0;
  while (_x) {
    if (_x % 2 == 1) _ret++;
    _x /= 2;
  }
  return _ret;
}
long long int bit(long long int _mask, long long int _i) {
  return (_mask & (1 << _i)) == 0 ? 0 : 1;
}
long long int powermod(long long int _a, long long int _b, long long int _m) {
  long long int _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a) % _m;
    _b /= 2;
    _a = (_a * _a) % _m;
  }
  return _r;
}
struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index)
      : from(from), to(to), cap(cap), flow(flow), index(index) {}
  long long rcap() { return cap - flow; }
};
struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<vector<Edge *> > Lf;
  vector<int> layer;
  vector<int> Q;
  Dinic(int N) : N(N), G(N), Q(N) {}
  void AddEdge(int from, int to, int cap) {
    if (from == to) return;
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }
  long long BlockingFlow(int s, int t) {
    layer.clear();
    layer.resize(N, -1);
    layer[s] = 0;
    Lf.clear();
    Lf.resize(N);
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i];
        if (e.rcap() <= 0) continue;
        if (layer[e.to] == -1) {
          layer[e.to] = layer[e.from] + 1;
          Q[tail++] = e.to;
        }
        if (layer[e.to] > layer[e.from]) {
          Lf[e.from].push_back(&e);
        }
      }
    }
    if (layer[t] == -1) return 0;
    long long totflow = 0;
    vector<Edge *> P;
    while (!Lf[s].empty()) {
      int curr = P.empty() ? s : P.back()->to;
      if (curr == t) {
        long long amt = P.front()->rcap();
        for (int i = 0; i < P.size(); ++i) {
          amt = min(amt, P[i]->rcap());
        }
        totflow += amt;
        for (int i = P.size() - 1; i >= 0; --i) {
          P[i]->flow += amt;
          G[P[i]->to][P[i]->index].flow -= amt;
          if (P[i]->rcap() <= 0) {
            Lf[P[i]->from].pop_back();
            P.resize(i);
          }
        }
      } else if (Lf[curr].empty()) {
        P.pop_back();
        for (int i = 0; i < N; ++i)
          for (int j = 0; j < Lf[i].size(); ++j)
            if (Lf[i][j]->to == curr) Lf[i].erase(Lf[i].begin() + j);
      } else {
        P.push_back(Lf[curr].back());
      }
    }
    return totflow;
  }
  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t)) totflow += flow;
    return totflow;
  }
};
int n;
int a[210];
bool isp[20010];
vector<int> G[210];
vector<vector<int> > ans;
bool vis[210];
vector<int> temp;
void dfs(int u) {
  vis[u] = true;
  temp.push_back(u);
  for (int v : G[u])
    if (!vis[v]) dfs(v);
}
int main() {
  srand(time(NULL));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= 20000; i++) isp[i] = true;
  for (int i = 2; i <= 20000; i++)
    if (isp[i])
      for (int j = i + i; j <= 20000; j += i) isp[j] = false;
  Dinic mf(n + 4);
  for (int i = 1; i <= n; i++)
    if (a[i] % 2 == 1) mf.AddEdge(n + 1, i, 2);
  for (int i = 1; i <= n; i++)
    if (a[i] % 2 == 0) mf.AddEdge(i, n + 2, 2);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i] % 2 == 1 && a[j] % 2 == 0 && isp[a[i] + a[j]])
        mf.AddEdge(i, j, 1);
  int flow = mf.GetMaxFlow(n + 1, n + 2);
  if (flow != n) {
    printf("Impossible");
    return 0;
  } else {
    for (int i = 1; i <= n; i++) {
      for (Edge it : mf.G[i]) {
        if (it.flow == 1 && it.to <= n) {
          G[i].push_back(it.to);
          G[it.to].push_back(i);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      temp.clear();
      dfs(i);
      ans.push_back(temp);
    }
  printf("%d\n", ans.size());
  for (auto t : ans) {
    printf("%d ", t.size());
    for (int t1 : t) printf("%d ", t1);
    printf("\n");
  }
  return 0;
}
