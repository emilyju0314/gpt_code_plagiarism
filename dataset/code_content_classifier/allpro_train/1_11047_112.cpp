#include <bits/stdc++.h>
using namespace std;
struct flow_graph {
  int MAX_V, E, s, t, head, tail;
  int *cap, *to, *next, *last, *dist, *q, *now;
  flow_graph() {}
  flow_graph(int V, int MAX_E) {
    MAX_V = V;
    E = 0;
    cap = new int[2 * MAX_E], to = new int[2 * MAX_E],
    next = new int[2 * MAX_E];
    last = new int[MAX_V], q = new int[MAX_V], dist = new int[MAX_V],
    now = new int[MAX_V];
    fill(last, last + MAX_V, -1);
  }
  void clear() {
    fill(last, last + MAX_V, -1);
    E = 0;
  }
  void add_edge(int u, int v, int uv, int vu = 0) {
    to[E] = v, cap[E] = uv, next[E] = last[u];
    last[u] = E++;
    to[E] = u, cap[E] = vu, next[E] = last[v];
    last[v] = E++;
  }
  bool bfs() {
    fill(dist, dist + MAX_V, -1);
    head = tail = 0;
    q[tail] = t;
    ++tail;
    dist[t] = 0;
    while (head < tail) {
      int v = q[head];
      ++head;
      for (int e = last[v]; e != -1; e = next[e]) {
        if (cap[e ^ 1] > 0 && dist[to[e]] == -1) {
          q[tail] = to[e];
          ++tail;
          dist[to[e]] = dist[v] + 1;
        }
      }
    }
    return dist[s] != -1;
  }
  int dfs(int v, int f) {
    if (v == t) return f;
    for (int &e = now[v]; e != -1; e = next[e]) {
      if (cap[e] > 0 && dist[to[e]] == dist[v] - 1) {
        int ret = dfs(to[e], min(f, cap[e]));
        if (ret > 0) {
          cap[e] -= ret;
          cap[e ^ 1] += ret;
          return ret;
        }
      }
    }
    return 0;
  }
  long long max_flow(int source, int sink) {
    s = source;
    t = sink;
    long long f = 0;
    int x;
    while (bfs()) {
      for (int i = 0; i < MAX_V; ++i) now[i] = last[i];
      while (true) {
        x = dfs(s, INT_MAX);
        if (x == 0) break;
        f += x;
      }
    }
    return f;
  }
};
int w[7], npv[40];
vector<int> mopper;
vector<pair<pair<int, int>, int> > vs;
vector<string> sol[40];
int main() {
  int V, E, u, v, c;
  map<string, int> has;
  map<int, string> rhas;
  string tmp;
  has["S"] = 1;
  has["M"] = 2;
  has["L"] = 3;
  has["XL"] = 4;
  has["XXL"] = 5;
  has["XXXL"] = 6;
  rhas[1] = "S";
  rhas[2] = "M";
  rhas[3] = "L";
  rhas[4] = "XL";
  rhas[5] = "XXL";
  rhas[6] = "XXXL";
  for (int i = 1; i <= 6; i++) {
    cin >> w[i];
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string tmp, a, b;
    cin >> tmp;
    int coun = 0;
    for (int j = 0; j < tmp.size(); j++) {
      if (tmp[j] == ',') {
        coun++;
      } else if (coun == 0) {
        a.push_back(tmp[j]);
      } else
        b.push_back(tmp[j]);
    }
    if (coun == 0) {
      npv[has[a]]++;
      mopper.push_back(has[a]);
    } else {
      if (has[a] > has[b]) swap(a, b);
      npv[has[a] * 6 + has[b]]++;
      mopper.push_back(has[a] * 6 + has[b]);
    }
  }
  for (int i = 0; i < n; i++) {
  }
  for (int i = 1; i <= 6; i++) {
    vs.push_back(make_pair(make_pair(0, i), w[i]));
  }
  for (int i = 1; i <= 6; i++) {
    vs.push_back(make_pair(make_pair(i, i + 6), w[i]));
    vs.push_back(make_pair(make_pair(i + 6, 59), npv[i]));
  }
  for (int i = 1; i <= 6; i++) {
    for (int j = i + 1; j <= 6; j++) {
      vs.push_back(make_pair(make_pair(i, i * 6 + j + 6), w[i]));
      vs.push_back(make_pair(make_pair(j, i * 6 + j + 6), w[j]));
    }
  }
  for (int i = 1; i <= 6; i++) {
    for (int j = i + 1; j <= 6; j++) {
      vs.push_back(make_pair(make_pair(i * 6 + j + 6, 59), npv[i * 6 + j]));
    }
  }
  flow_graph G(100, vs.size() + 1), G2(100, vs.size() + 1);
  for (int i = 0; i < vs.size(); i++) {
    if (vs[i].second) {
      G.add_edge(vs[i].first.first, vs[i].first.second, vs[i].second, 0);
      G2.add_edge(vs[i].first.first, vs[i].first.second, vs[i].second, 0);
    }
  }
  int ff = G.max_flow(0, 59), sumd = 0;
  if (ff >= n) {
    cout << "YES\n";
    for (int i = 0; i < G.E; i += 2) {
      int u = G.to[i], v = G.to[i + 1];
      swap(u, v);
      if (u >= 1 && u <= 6 && v >= 7 && v <= 42) {
        int del = G2.cap[i] - G.cap[i];
        sumd += del;
        while (del >= 1) {
          sol[v - 6].push_back(rhas[u]);
          w[u]--;
          if (w[u] < 0) {
            cout << "fucking failed: " << v - 6 << " " << del << endl;
          }
          del--;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << sol[mopper[i]].back() << endl;
      sol[mopper[i]].pop_back();
    }
  } else
    cout << "NO\n";
  return 0;
}
