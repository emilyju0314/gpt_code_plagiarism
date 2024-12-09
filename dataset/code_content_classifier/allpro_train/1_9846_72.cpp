#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10, MAXM = 400000 + 10;
int n, m, to[MAXM], nex[MAXM], beg[MAXN], fa[MAXN], dfn[MAXN], temp[MAXM],
    e = 1, vis[MAXM], cnt;
struct node {
  int x, y, z;
};
queue<node> Ans;
inline void read(int &x) {
  int data = 0, w = 1;
  char ch = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    data = (data << 3) + (data << 1) + (ch ^ '0'), ch = getchar();
  x = data * w;
}
inline void insert(int x, int y) {
  to[++e] = y;
  nex[e] = beg[x];
  beg[x] = e;
}
inline void bfs(int s) {
  queue<int> q;
  q.push(s);
  fa[s] = -1;
  cnt = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    dfn[++cnt] = x;
    for (register int i = beg[x]; i; i = nex[i])
      if (!fa[to[i]]) {
        fa[to[i]] = x;
        q.push(to[i]);
      }
  }
  for (register int i = cnt; i >= 1; --i) {
    int x = dfn[i];
    temp[0] = 0;
    for (register int i = beg[x]; i; i = nex[i])
      if (!vis[i] && to[i] != fa[x]) temp[++temp[0]] = i;
    for (register int i = beg[x]; i; i = nex[i])
      if (!vis[i] && to[i] == fa[x]) temp[++temp[0]] = i;
    for (register int i = 1; i + 1 <= temp[0]; i += 2) {
      vis[temp[i]] = vis[temp[i] ^ 1] = vis[temp[i + 1]] =
          vis[temp[i + 1] ^ 1] = 1;
      node tmp;
      tmp.x = to[temp[i]];
      tmp.y = x;
      tmp.z = to[temp[i + 1]];
      Ans.push(tmp);
    }
  }
}
int main() {
  read(n);
  read(m);
  for (register int i = 1; i <= m; ++i) {
    int u, v;
    read(u);
    read(v);
    insert(u, v);
    insert(v, u);
  }
  for (register int i = 1; i <= n; ++i)
    if (!fa[i]) bfs(i);
  printf("%d\n", (int)Ans.size());
  while (!Ans.empty()) {
    node tmp = Ans.front();
    Ans.pop();
    printf("%d %d %d\n", tmp.x, tmp.y, tmp.z);
  }
  return 0;
}
