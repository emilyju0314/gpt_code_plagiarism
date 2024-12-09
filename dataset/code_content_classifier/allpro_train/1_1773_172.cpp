#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph, Rgraph, conn, rrgraph;
vector<int> parent;
int n, s, t, V;
bool bfs() {
  bool visited[V];
  for (int i = 0; i < V; ++i) visited[i] = 0;
  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 0; v < V; v++) {
      if (visited[v] == false && Rgraph[u][v] > 0) {
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }
  return (visited[t] == true);
}
int fordFulkerson() {
  int u, v;
  parent.assign(V, -1);
  int max_flow = 0;
  while (bfs()) {
    int path_flow = INT_MAX;
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      path_flow = min(path_flow, Rgraph[u][v]);
    }
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      Rgraph[u][v] -= path_flow;
      Rgraph[v][u] += path_flow;
    }
    max_flow += path_flow;
  }
  return max_flow;
}
int limit = 20000;
vector<int> lp, prime;
void linear_sieve() {
  lp.assign(limit + 1, 0);
  for (int i = 2; i <= limit; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      prime.push_back(i);
    }
    for (int j = 0;
         j < prime.size() && prime[j] <= lp[i] && i * prime[j] <= limit; ++j) {
      lp[i * prime[j]] = prime[j];
    }
  }
}
int main() {
  linear_sieve();
  scanf("%d", &n);
  int a[n], i, j, odd = 0, even = 0;
  V = n + 2;
  s = 0, t = V - 1;
  conn.assign(n, vector<int>(n, 0));
  graph.assign(V, vector<int>(V, 0));
  Rgraph.assign(V, vector<int>(V, 0));
  rrgraph.assign(V, vector<int>(V, 0));
  for (i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] % 2 == 0) ++even;
    if (a[i] % 2 == 1) ++odd;
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (lp[a[i] + a[j]] == a[i] + a[j]) {
        conn[i][j] = 1;
      }
    }
  }
  if (odd != even) {
    printf("Impossible");
    return 0;
  }
  for (i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      graph[i + 1][n + 1] = 2;
      Rgraph[i + 1][n + 1] = 2;
    }
    if (a[i] % 2 == 1) {
      graph[0][i + 1] = 2;
      Rgraph[0][i + 1] = 2;
    }
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (conn[i][j] == 1) {
        if (a[i] % 2 == 1) {
          graph[i + 1][j + 1] = 1;
          Rgraph[i + 1][j + 1] = 1;
        }
        if (a[i] % 2 == 0) {
          graph[j + 1][i + 1] = 1;
          Rgraph[j + 1][i + 1] = 1;
        }
      }
    }
  }
  int ans = fordFulkerson();
  for (i = 1; i < V - 1; ++i) {
    for (j = 1; j < V - 1; ++j) {
      rrgraph[j][i] = Rgraph[i][j];
    }
  }
  vector<int> chose(n + 1, 0);
  vector<vector<int> > res;
  int k;
  for (k = 1; k <= n; ++k) {
    if (chose[k] == 0) {
      i = k;
      res.push_back(vector<int>());
      int begin = i;
      res[res.size() - 1].push_back(i);
      do {
        int check = 0;
        chose[i] = 1;
        if (a[i - 1] % 2 == 1) {
          for (j = 1; j < V - 1; ++j) {
            if (rrgraph[i][j] != 0 && chose[j] == 0) {
              res[res.size() - 1].push_back(j);
              i = j;
              check = 1;
              break;
            }
          }
        } else {
          for (j = 1; j < V - 1; ++j) {
            if (Rgraph[i][j] != 0 && chose[j] == 0) {
              res[res.size() - 1].push_back(j);
              i = j;
              check = 1;
              break;
            }
          }
        }
        if (check == 0) break;
      } while (1);
    }
  }
  for (i = 0; i < res.size(); ++i) {
    if (res[i].size() < 3) {
      printf("Impossible");
      return 0;
    }
  }
  printf("%d\n", res.size());
  for (i = 0; i < res.size(); ++i) {
    printf("%d ", res[i].size());
    for (j = 0; j < res[i].size(); ++j) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
}
