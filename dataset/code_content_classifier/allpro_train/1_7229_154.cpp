#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 4;
constexpr int MAXK = 1e3 + 5;
constexpr int MOD = 1e9 + 7;
constexpr long long INF = 9187201950435737471;
constexpr int LOG = 11;
struct edge {
  long long u, v, w;
  void Get() { cin >> u >> v >> w; }
  void Debug() { cout << u << "->" << v << "\n"; }
};
int n, m, s, t, deg[MAXN], cnt;
string ans[MAXN];
long long dist[2][MAXN], val[MAXN];
bool mark[MAXN];
edge E[MAXN];
vector<int> G[MAXN][2], T[MAXN][2], rec;
void dijkstra(int src, int type) {
  set<pair<int, int> > st;
  dist[type][src] = 0;
  st.insert(make_pair(0, src));
  while (!st.empty()) {
    int u = (*st.begin()).second;
    st.erase(st.begin());
    for (auto i : G[u][type]) {
      int v = E[i].u ^ E[i].v ^ u, w = E[i].w;
      if (dist[type][v] > dist[type][u] + w) {
        st.erase(make_pair(dist[type][v], v));
        dist[type][v] = dist[type][u] + w;
        st.insert(make_pair(dist[type][v], v));
      }
    }
  }
}
void Create_DAG(int u) {
  mark[u] = true;
  for (auto i : G[u][1]) {
    int v = E[i].u ^ E[i].v ^ u, w = E[i].w;
    if (dist[0][u] == dist[0][v] + w) {
      T[v][0].push_back(i);
      T[u][1].push_back(i);
      if (!mark[v]) {
        Create_DAG(v);
      }
    }
  }
}
void Check_Yes() {
  int u = rec.back();
  rec.pop_back();
  if (T[u][0].size() == 1 && rec.empty() && !cnt) {
    int idx = T[u][0].back();
    if (T[E[idx].v][1].size() == 1) {
      ans[idx] = "YES";
    }
  }
  for (auto i : T[u][0]) {
    int v = E[i].v;
    deg[v]--;
    if (!deg[v]) {
      rec.push_back(v);
      if (T[v][1].size() > 1) {
        cnt -= T[v][1].size();
        cnt++;
      }
    } else {
      cnt++;
    }
  }
  if (!rec.empty()) {
    Check_Yes();
  }
}
void Check_Other() {
  for (int i = 1; i <= m; i++) {
    if (ans[i] != "YES") {
      if (dist[0][E[i].u] != INF && dist[1][E[i].v] != INF &&
          dist[0][E[i].u] + dist[1][E[i].v] + 1 < dist[0][t]) {
        ans[i] = "CAN";
        val[i] = dist[0][E[i].u] + dist[1][E[i].v] + E[i].w - dist[0][t] + 1;
      } else {
        ans[i] = "NO";
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; i++) {
    E[i].Get();
    G[E[i].u][0].push_back(i);
    G[E[i].v][1].push_back(i);
  }
  memset(dist, 127, sizeof dist);
  dijkstra(s, 0);
  dijkstra(t, 1);
  Create_DAG(t);
  for (int i = 1; i <= n; i++) {
    deg[i] = T[i][1].size();
  }
  rec.push_back(s);
  Check_Yes();
  Check_Other();
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << " ";
    if (ans[i] == "CAN") {
      cout << val[i];
    }
    cout << "\n";
  }
  return 0;
}
