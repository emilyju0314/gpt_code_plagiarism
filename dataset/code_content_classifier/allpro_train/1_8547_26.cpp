#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
typedef pair<LL, LL> pLL;
// LatexBegin
struct MCMF { LL flow, cost;
  struct Node : vector<int> { int p, inq; LL a, d; };
  struct Edge { int u, v; LL c, co; };
  vector<Node> N; vector<Edge> E;
  void init(int n) {
    N.clear(); N.resize(n); E.clear(); flow = cost = 0;
  }
  void addEdge(int u, int v, LL c, LL co) {
    int m = E.size();
    E.push_back({u, v, c,  co}); N[u].push_back(m++); 
    E.push_back({v, u, 0, -co}); N[v].push_back(m++);
  }
  void run(int s, int t) {
    while (SPFA(s, t)) {
      flow += N[t].a; cost += N[t].d * N[t].a;
      for (int u = t ; u != s ; u = E[N[u].p].u) {
        E[N[u].p    ].c -= N[t].a;
        E[N[u].p ^ 1].c += N[t].a;
      }
    }
  }
  bool SPFA(int s, int t) {
    for (auto &v : N) v.d = INF, v.inq = false;
    queue<int> q; q.push(s); N[s].inq = true;
    N[s].d = 0, N[s].p = -1, N[s].a = INF;
    while (q.size()) {
      int u = q.front(); q.pop(); N[u].inq = false;
      for (auto &e : N[u]) { int v = E[e].v;
        if (!E[e].c || N[v].d <= N[u].d + E[e].co)
          continue;
        N[v].d = N[u].d + E[e].co;
        N[v].p = e; N[v].a = min(N[u].a, E[e].c);
        if (!N[v].inq) q.push(v), N[v].inq = true;
      }
    }
    return N[t].d != INF;
  }
} solver;
// LatexEnd
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    solver.init(1 + 2 * n + 1);
    for (int i = 0 ; i < n ; i++) {
        solver.addEdge(0, 1 + i, k, 0);
        solver.addEdge(1 + n + i, 1 + n + n, k, 0);
        solver.addEdge(1 + i, 1 + n + n, INF, 0);
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            LL v; cin >> v;
            solver.addEdge(1 + i, 1 + n + j, 1, -v);
        }
    }
    solver.run(0, 1 + n + n);
    cout << -solver.cost << '\n';
    auto E = solver.E;
    vector<vector<char>> G(n, vector<char>(n, '.'));
    for (int i = 0 ; i < (int)E.size() ; i += 2) {
        int u = E[i].u, v = E[i].v;
        if (u == 0 || v == 1 + n + n)
            continue;
        if (E[i].c) continue;
        u--, v--, v -= n;
        G[u][v] = 'X';
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++)
            cout << G[i][j];
        cout << '\n';
    }
}