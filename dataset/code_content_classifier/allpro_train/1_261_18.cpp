#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int INF = 1e9 + 5;
const long long INF_LL = 1e15 + 5;
int g[N][N], dist[N][N];
struct Ship {
  int loc, attack, fuel, price;
  void read() {
    cin >> loc >> attack >> fuel >> price;
    --loc;
  }
};
vector<pair<int, int>> reward[N];
struct Base {
  int loc, defence, gold;
  void read() {
    cin >> loc >> defence >> gold;
    --loc;
    reward[loc].emplace_back(defence, gold);
  }
};
template <typename T>
void max_self(T& a, T b) {
  a = max(a, b);
}
template <typename flow_t>
class Dinic {
 public:
  Dinic(int _n, int _source, int _sink) : n(_n), source(_source), sink(_sink) {
    g.resize(n);
    flow.resize(n, vector<flow_t>(n));
    level.resize(n);
    ptr.resize(n);
  }
  void add_edge(int from, int to, flow_t cap) {
    g[from].push_back(to);
    g[to].push_back(from);
    flow[from][to] += cap;
  }
  bool bfs() {
    vector<int> q{source};
    for (int i = 0; i < (int)q.size(); i++) {
      int u = q[i];
      for (int v : g[u]) {
        if (level[v] == -1 && flow[u][v] > 0) {
          level[v] = level[u] + 1;
          q.push_back(v);
        }
      }
    }
    return level[sink] != -1;
  }
  flow_t dfs(int u, flow_t pushed) {
    if (pushed == 0) {
      return 0;
    }
    if (u == sink) {
      return pushed;
    }
    for (int& pos = ptr[u]; pos < (int)g[u].size(); pos++) {
      int v = g[u][pos];
      if (level[v] != level[u] + 1 || flow[u][v] == 0) {
        continue;
      }
      flow_t maybe_push = dfs(v, min(pushed, flow[u][v]));
      if (maybe_push == 0) {
        continue;
      }
      flow[u][v] -= maybe_push;
      flow[v][u] += maybe_push;
      return maybe_push;
    }
    return 0;
  }
  flow_t max_flow() {
    flow_t mf(0);
    while (true) {
      level.assign(n, -1);
      level[source] = 0;
      if (!bfs()) {
        break;
      }
      ptr.assign(n, 0);
      flow_t now;
      do {
        now = dfs(source, FLOW_MAX);
        mf += now;
      } while (now != 0);
    }
    return mf;
  }

 private:
  const flow_t FLOW_MAX = numeric_limits<flow_t>::max() / 2;
  vector<vector<int>> g;
  vector<vector<flow_t>> flow;
  vector<int> level, ptr;
  int n, source, sink;
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fill((int*)dist, (int*)dist + N * N, INF);
  for (int i = 0; i < int(N); i++) dist[i][i] = 0;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < int(m); i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a][b] = g[b][a] = 1;
    dist[a][b] = dist[b][a] = 1;
  }
  for (int k = 0; k < int(n); k++)
    for (int i = 0; i < int(n); i++)
      for (int j = 0; j < int(n); j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
  int second, B, K;
  cin >> second >> B >> K;
  vector<Ship> ships(second);
  vector<Base> bases(B);
  for (auto& s : ships) {
    s.read();
  }
  for (auto& b : bases) {
    b.read();
  }
  for (int i = 0; i < int(n); i++) {
    sort(reward[i].begin(), reward[i].end());
    int sz = reward[i].size();
    for (int j = 1; j <= int(sz - 1); j++) {
      reward[i][j].second = max(reward[i][j].second, reward[i][j - 1].second);
    }
  }
  vector<long long> ship_reward(second, -INF_LL);
  for (int i = 0; i < int(second); i++) {
    Ship s = ships[i];
    for (int base = 0; base < int(n); base++)
      if (dist[s.loc][base] < INF) {
        int lo = 0, hi = (int)reward[base].size() - 1;
        int idx = -1;
        while (lo <= hi) {
          int mid = (lo + hi) / 2;
          if (reward[base][mid].first <= s.attack) {
            idx = mid;
            lo = mid + 1;
          } else {
            hi = mid - 1;
          }
        }
        if (idx == -1) {
          continue;
        }
        max_self(ship_reward[i], (long long)reward[base][idx].second - s.price);
      }
  }
  vector<pair<int, int>> dependencies;
  for (int i = 0; i < int(K); i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    dependencies.emplace_back(a, b);
  }
  long long ans = 0;
  for (int i = 0; i < int(second); i++) {
    if (ship_reward[i] > 0) {
      ans += ship_reward[i];
    }
  }
  map<int, int> id;
  int nodes = 0;
  for (auto [u, v] : dependencies) {
    if (!id.count(u)) {
      id[u] = nodes++;
    }
    if (!id.count(v)) {
      id[v] = nodes++;
    }
  }
  int source = nodes++;
  int sink = nodes++;
  Dinic<long long> graph(nodes, source, sink);
  for (auto [u, _] : id) {
    if (ship_reward[u] >= 0) {
      graph.add_edge(source, id[u], ship_reward[u]);
    } else {
      graph.add_edge(id[u], sink, -ship_reward[u]);
    }
  }
  for (auto [u, v] : dependencies) {
    graph.add_edge(id[u], id[v], INF_LL);
  }
  ans -= graph.max_flow();
  cout << ans << "\n";
}
