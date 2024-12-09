#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
struct Edge {
  int u, v, f, c, next;
  Edge() {}
  Edge(int _u, int _v, int _f, int _c, int _next)
      : u(_u), v(_v), f(_f), c(_c), next(_next) {}
} e[500000];
int n, m, nm, a[80][80], en, S, T, NV, head[6600];
void add(int u, int v, int f, int c) {
  e[en] = Edge(u, v, f, c, head[u]);
  head[u] = en++;
  e[en] = Edge(v, u, 0, -c, head[v]);
  head[v] = en++;
}
bool inq[6600];
int p[6600], dis[6600];
bool spfa() {
  for (int i = 0; i < NV; i++) {
    dis[i] = INF;
    inq[i] = false;
  }
  dis[S] = 0;
  queue<int> q;
  q.push(S);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (int i = head[u]; i != -1; i = e[i].next) {
      int v = e[i].v;
      if (e[i].f > 0 && dis[v] > dis[u] + e[i].c) {
        dis[v] = dis[u] + e[i].c;
        p[v] = i;
        if (!inq[v]) {
          q.push(v);
          inq[v] = true;
        }
      }
    }
  }
  if (dis[T] == INF)
    return false;
  else
    return true;
}
int feeFlow() {
  int cost = 0;
  while (spfa()) {
    cost += dis[T];
    for (int u, v = T; v != S; v = u) {
      u = e[p[v]].u;
      e[p[v]].f--;
      e[p[v] ^ 1].f++;
    }
  }
  return cost;
}
int main() {
  cin >> n >> m;
  nm = n * m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  en = 0;
  S = nm;
  T = nm + 1;
  NV = T + 1;
  memset(head, -1, sizeof(head));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if ((i + j) & 1) {
        add(S, i * m + j, 1, 0);
        for (int d = 0; d < 4; d++) {
          int x = i + dx[d];
          int y = j + dy[d];
          if (x < 0 || x == n || y < 0 || y == m) continue;
          add(i * m + j, x * m + y, 1, a[i][j] == a[x][y] ? 0 : 1);
        }
      } else
        add(i * m + j, T, 1, 0);
    }
  cout << feeFlow() << endl;
  return 0;
}
