#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
namespace star {
const int maxn = 2e5 + 5;
int head[maxn], len[maxn], dis[maxn], pre[maxn];
int n, cnt = 1, m, ans;
char ch[maxn];
bool vis[maxn];
priority_queue<pair<int, int> > q;
queue<int> qt;
struct edge {
  int to, nxt, val;
} e[maxn];
void add(int u, int v, int w) {
  e[++cnt].to = v;
  e[cnt].val = w;
  e[cnt].nxt = head[u];
  head[u] = cnt;
  e[++cnt].to = u;
  e[cnt].val = w;
  e[cnt].nxt = head[v];
  head[v] = cnt;
}
inline void dijkstra() {
  memset(pre, 0, sizeof(pre));
  memset(dis, 0x3f, sizeof(dis));
  memset(len, 0x3f, sizeof(len));
  qt.push(n);
  dis[n] = 0;
  len[n] = 1;
  while (!qt.empty()) {
    int u = qt.front();
    qt.pop();
    q.push(make_pair(0, u));
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      int w = e[i].val;
      if (dis[v] && w == 0) {
        dis[v] = 0;
        len[v] = len[u] + 1;
        pre[v] = (i ^ 1);
        qt.push(v);
      }
    }
  }
  int pos = 0, lst = -1;
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    if (lst != dis[u]) pos++, lst = dis[u];
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      int w = e[i].val;
      if (dis[v] > pos * 10 + w) {
        dis[v] = pos * 10 + w;
        len[v] = len[u] + 1;
        pre[v] = i ^ 1;
        q.push(make_pair(-dis[v], v));
      } else if (dis[v] == pos * 10 + w && len[v] > len[u] + 1) {
        len[v] = len[u] + 1;
        pre[v] = i ^ 1;
        q.push(make_pair(-dis[v], v));
      }
    }
  }
}
void work() {
  n = read();
  m = read();
  for (int a, b, i = 1; i <= m; i++)
    a = read() + 1, b = read() + 1, add(a, b, read());
  dijkstra();
  int tmp = 1;
  stack<int> s;
  while (tmp != n) {
    s.push(e[pre[tmp]].val);
    tmp = e[pre[tmp]].to;
  }
  while (!s.empty() && s.top() == 0) s.pop();
  if (s.empty())
    printf("0");
  else
    while (!s.empty()) printf("%d", s.top()), s.pop();
  putchar('\n');
  printf("%d\n0 ", len[1]);
  tmp = 1;
  while (tmp != n) {
    tmp = e[pre[tmp]].to;
    printf("%d ", tmp - 1);
  }
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
