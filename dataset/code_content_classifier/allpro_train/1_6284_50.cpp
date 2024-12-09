#include <bits/stdc++.h>
using namespace std;
int Read() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int t = c - '0';
  c = getchar();
  while (c >= '0' && c <= '9') t = (t << 3) + (t << 1) + c - '0', c = getchar();
  return t;
}
int n, Q, s;
int Head[900001], To[3200001], Next[3200001], t1;
int W[3200001];
void add(int a, int b, int c) {
  t1++;
  Next[t1] = Head[a];
  Head[a] = t1;
  To[t1] = b;
  W[t1] = c;
}
void Build(int bh, int x, int y) {
  if (x == y) {
    add(bh, n * 8 + x, 0), add(n * 8 + x, bh, 0);
    add(n * 4 + bh, n * 8 + x, 0), add(n * 8 + x, n * 4 + bh, 0);
    return;
  }
  add(bh, bh * 2, 0), add(bh, bh * 2 + 1, 0);
  add(n * 4 + bh * 2, n * 4 + bh, 0), add(n * 4 + bh * 2 + 1, n * 4 + bh, 0);
  int mid = (x + y) / 2;
  Build(bh * 2, x, mid);
  Build(bh * 2 + 1, mid + 1, y);
}
void add(int bh, int x, int y, int a, int b, int c, bool t, int u) {
  if (x == a && y == b) {
    if (!t)
      add(n * 8 + u, bh, c);
    else
      add(n * 4 + bh, n * 8 + u, c);
    return;
  }
  int mid = (x + y) / 2;
  if (b <= mid)
    add(bh * 2, x, mid, a, b, c, t, u);
  else if (a > mid)
    add(bh * 2 + 1, mid + 1, y, a, b, c, t, u);
  else
    add(bh * 2, x, mid, a, mid, c, t, u),
        add(bh * 2 + 1, mid + 1, y, mid + 1, b, c, t, u);
}
struct Node {
  int id;
  long long d;
  bool operator<(const Node& a) const { return a.d < d; }
} t;
priority_queue<Node> q;
bool vis[900001];
long long dis[900001];
void Dij() {
  for (int i = 1; i <= n * 9; i++) dis[i] = 1e18;
  dis[n * 8 + s] = 0;
  t.id = n * 8 + s;
  t.d = 0;
  q.push(t);
  while (!q.empty()) {
    while (!q.empty() && vis[q.top().id]) q.pop();
    if (q.empty()) break;
    int curr = q.top().id;
    q.pop();
    vis[curr] = 1;
    for (int i = Head[curr]; i; i = Next[i]) {
      if (!vis[To[i]]) {
        if (dis[To[i]] > dis[curr] + W[i]) {
          dis[To[i]] = dis[curr] + W[i];
          t.id = To[i];
          t.d = dis[To[i]];
          q.push(t);
        }
      }
    }
  }
}
int main() {
  n = Read();
  Q = Read();
  s = Read();
  Build(1, 1, n);
  for (int i = 1, t, u, v, w, l, r; i <= Q; i++) {
    t = Read();
    if (t == 1) {
      u = Read();
      v = Read();
      w = Read();
      add(n * 8 + u, n * 8 + v, w);
    } else if (t == 2) {
      u = Read();
      l = Read();
      r = Read();
      w = Read();
      add(1, 1, n, l, r, w, 0, u);
    } else {
      u = Read();
      l = Read();
      r = Read();
      w = Read();
      add(1, 1, n, l, r, w, 1, u);
    }
  }
  Dij();
  for (int i = n * 8 + 1; i <= n * 8 + n; i++) {
    if (!vis[i])
      printf("-1 ");
    else
      printf("%lld ", dis[i]);
  }
  return 0;
}
