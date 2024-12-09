#include <bits/stdc++.h>
using namespace std;
const long long SZ = 1210, INF = 1e9 + 100;
long long n, x, y;
struct edge {
  long long v, u, f, s, su, c;
};
vector<edge> edges;
vector<vector<long long>> gr;
void add(long long v, long long u, long long c, long long s) {
  s = -s;
  gr[v].push_back(edges.size());
  edges.push_back({v, u, c, s, s, c});
  gr[u].push_back(edges.size());
  edges.push_back({u, v, 0, -s, -s, 0});
}
long long dist[SZ], type[SZ], p[SZ];
bool dists(int s, int t) {
  for (int i = 0; i < SZ; i++) {
    type[i] = 0;
    dist[i] = INF;
  }
  dist[s] = 0;
  type[s] = 2;
  queue<long long> q1, q2;
  q1.push(s);
  while (!(q1.empty() && q2.empty())) {
    long long v;
    if (!q2.empty()) {
      v = q2.front();
      q2.pop();
    } else {
      v = q1.front();
      q1.pop();
    }
    for (auto to : gr[v]) {
      long long u = edges[to].u;
      if (edges[to].f <= 0) continue;
      if (type[u] == 1 || type[u] == 2) {
        dist[u] = min(dist[u], dist[v] + edges[to].s);
      } else if (type[u] == 0) {
        dist[u] = min(dist[u], dist[v] + edges[to].s);
        type[u] = 1;
        q1.push(u);
      } else if (dist[u] > dist[v] + edges[to].s) {
        type[u] = 2;
        q2.push(u);
        dist[u] = dist[v] + edges[to].s;
      }
    }
    type[v] = 3;
  }
  return dist[t] < INF;
}
long long nw[SZ];
bool used[SZ];
pair<long long, long long> dfs(long long v, long long t, long long pr = INF) {
  if (t == v) return {pr, 0};
  used[v] = 1;
  for (auto to : gr[v]) {
    long long u = edges[to].u;
    if (!used[u] && edges[to].su == 0 && edges[to].f > 0) {
      pair<long long, long long> k = dfs(u, t, min(pr, edges[to].f));
      long long q = k.first, q2 = k.second;
      if (q) {
        edges[to].f -= q;
        edges[to ^ 1].f += q;
        return {q, q2 + q * edges[to].s};
      }
    }
  }
  return {0, 0};
}
void djikstra(int s, int t) {
  for (int i = 0; i < SZ; i++) nw[i] = INF;
  nw[s] = 0;
  while (true) {
    pair<long long, long long> v = {INF, INF};
    for (int i = 0; i < SZ; i++) {
      if (!used[i]) {
        v = min(v, {nw[i], i});
      }
    }
    if (v.first == INF) return;
    used[v.second] = 1;
    for (auto to : gr[v.second]) {
      long long u = edges[to].u;
      if (edges[to].f > 0 && nw[u] > nw[v.second] + (edges[to].su)) {
        nw[u] = nw[v.second] + (edges[to].su);
      }
    }
  }
}
pair<long long, long long> mcmf(long long s, long long t) {
  dists(s, t);
  for (int i = 0; i < SZ; i++) p[i] = dist[i];
  for (auto& cur : edges) {
    cur.su = cur.su + p[cur.v] - p[cur.u];
  }
  long long flow = 0, cost = 0;
  pair<long long, long long> k;
  while ((k = dfs(s, t)) != make_pair(0ll, 0ll)) {
    flow += k.first;
    cost += k.second;
    for (int j = 0; j < SZ; j++) used[j] = 0;
    djikstra(s, t);
    for (int j = 0; j < SZ; j++) {
      used[j] = 0;
      dist[j] = nw[j];
      p[j] = dist[j];
    }
    for (auto& cur : edges) {
      cur.su = cur.su + p[cur.v] - p[cur.u];
    }
  }
  return {flow, cost};
}
vector<vector<long long>> tree1, tree2;
vector<long long> vec, b1, b2, ind1, ind2;
long long dfs1(int v, int par = -1) {
  long long sm = 0;
  for (auto to : tree1[v]) {
    if (to != par) {
      sm += dfs1(to, v);
    }
  }
  if (b1[v] != INF) {
    if (b1[v] < sm) {
      cout << "-1";
      exit(0);
    }
    ind1[v] = edges.size();
    add(0, v + 1, b1[v] - sm, 0);
  } else {
    add(par + 1, v + 1, b1[v], 0);
    ind1[v] = -1;
  }
  if (b1[v] != INF) sm = b1[v];
  return sm;
}
long long dfs2(int v, int par = -1) {
  long long sm = 0;
  for (auto to : tree2[v]) {
    if (to != par) {
      sm += dfs2(to, v);
    }
  }
  if (b2[v] != INF) {
    if (b2[v] < sm) {
      cout << "-1";
      exit(0);
    }
    ind2[v] = edges.size();
    add(v + n + 2, 2 * n + 2, b2[v] - sm, 0);
  } else {
    add(v + n + 2, par + n + 2, b2[v], 0);
    ind2[v] = -1;
  }
  if (b2[v] != INF) sm = b2[v];
  return sm;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  cin >> n >> x >> y;
  x--;
  y--;
  vec.resize(n);
  gr.resize(2 * n + 4);
  int i = 0;
  for (auto& c : vec) {
    cin >> c;
    add(i + 1, i + n + 2, 1, c);
    i++;
  }
  tree1.resize(n);
  tree2.resize(n);
  for (int i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    tree1[u].push_back(v);
    tree1[v].push_back(u);
  }
  for (int i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    tree2[u].push_back(v);
    tree2[v].push_back(u);
  }
  b1.resize(n);
  ind1.resize(n);
  for (auto& c : b1) c = INF;
  b2.resize(n);
  ind2.resize(n);
  for (auto& c : b2) c = INF;
  long long q1;
  cin >> q1;
  for (int i = 0; i < q1; i++) {
    long long k, x;
    cin >> k >> x;
    k--;
    b1[k] = x;
  }
  long long q2;
  cin >> q2;
  for (int i = 0; i < q2; i++) {
    long long k, x;
    cin >> k >> x;
    k--;
    b2[k] = x;
  }
  dfs1(x);
  dfs2(y);
  pair<long long, long long> q = mcmf(0, 2 * n + 2);
  for (auto c : ind1) {
    if (c == -1) continue;
    if (edges[c].c != INF && edges[c].f != 0) {
      cout << "-1";
      return 0;
    }
  }
  for (auto c : ind2) {
    if (c == -1) continue;
    if (edges[c].c != INF && edges[c].f != 0) {
      cout << "-1";
      return 0;
    }
  }
  cout << -q.second;
  return 0;
}
