#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
  return s * f;
}
const int N = 2e5 + 10;
struct Edge {
  int to, next;
} e[N << 1];
int head[N], ecnt;
inline void adde(int u, int v) {
  e[++ecnt].next = head[u];
  e[ecnt].to = v;
  head[u] = ecnt;
}
int n, m;
int deg[N];
struct QUEUE {
  int a[N], head, tail;
  inline void init() {
    head = 1;
    tail = 0;
  }
  inline int front() { return a[head]; }
  inline void push(int x) { a[++tail] = x; }
  inline void pop() { ++head; }
  inline bool empty() { return head > tail; }
} q;
bool del[N];
bool path[N];
int tot = 0;
inline void dele(int u) {
  del[u] = 1;
  ++tot;
  for (int i = head[u], v; i; i = e[i].next) {
    v = e[i].to;
    deg[v]--;
    if (!deg[v]) q.push(v);
  }
}
inline void toposort() {
  q.init();
  for (int i = 1; i <= n; ++i)
    if (!deg[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (del[u]) continue;
    for (int i = head[u], v; i; i = e[i].next) {
      v = e[i].to;
      if (del[v]) continue;
      if (path[u]) {
        dele(v);
        continue;
      }
      path[v] = 1;
      --deg[v];
      if (!deg[v]) q.push(v);
    }
  }
}
inline void init() {
  fill(head, head + n + 5, 0);
  fill(path, path + n + 5, 0);
  fill(deg, deg + n + 5, 0);
  fill(del, del + n + 5, 0);
  ecnt = 0;
  tot = 0;
}
int T;
int main() {
  T = read();
  while (T--) {
    n = read();
    m = read();
    init();
    for (int i = 1, u, v; i <= m; ++i) {
      u = read();
      v = read();
      adde(u, v);
      ++deg[v];
    }
    toposort();
    printf("%d\n", tot);
    for (int i = 1; i <= n; ++i)
      if (del[i]) printf("%d ", i);
    puts("");
  }
  return 0;
}
