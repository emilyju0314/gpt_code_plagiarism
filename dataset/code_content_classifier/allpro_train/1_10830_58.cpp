#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
  return x;
}
const int N = 1e5 + 5;
long long inf = 0x3f3f3f3f3f3f3f3fll;
struct EDGE {
  int to, next;
  long long flow;
} edge[N << 1];
int head[N], cur[N], num_edge = 1;
void add_edge(int from, int to, int flow) {
  edge[++num_edge].next = head[from];
  head[from] = num_edge;
  edge[num_edge].to = to;
  edge[num_edge].flow = flow;
}
void add(int from, int to, int flow) {
  add_edge(from, to, flow), add_edge(to, from, 0);
}
queue<int> q;
int d[N];
bool bfs(int S, int T) {
  for (int i = 1; i <= T; i++) d[i] = -1;
  q.push(S), d[S] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = edge[i].next) {
      int v = edge[i].to;
      if (edge[i].flow && d[v] == -1) {
        d[v] = d[u] + 1, q.push(v);
      }
    }
  }
  return d[T] != -1;
}
long long dfs(int u, int T, long long flow) {
  if (u == T || !flow) return flow;
  long long add = 0, f;
  for (int& i = cur[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (edge[i].flow && d[v] == d[u] + 1 &&
        (f = dfs(v, T, min(flow, edge[i].flow)))) {
      edge[i].flow -= f, edge[i ^ 1].flow += f, flow -= f, add += f;
      if (!flow) return add;
    }
  }
  return add;
}
long long dinic(int S, int T) {
  long long max_flow = 0;
  while (bfs(S, T)) {
    long long d;
    for (int i = 1; i <= T; i++) cur[i] = head[i];
    while (d = dfs(S, T, inf)) max_flow += d;
  }
  return max_flow;
}
int n, m, a[N], S, T;
long long sum;
int main() {
  n = read(), m = read(), S = n + m + 1, T = n + m + 2;
  for (int i = 1; i <= n; i++) a[i] = read(), add(S, i, a[i]);
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), v = read();
    sum += v;
    add(x, n + i, inf), add(y, n + i, inf);
    add(n + i, T, v);
  }
  printf("%lld\n", max(sum - dinic(S, T), 0ll));
  return 0;
}
