#include <bits/stdc++.h>
inline char fgc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long readint() {
  register long long res = 0, neg = 1;
  char c = fgc();
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = fgc();
  }
  while (c >= '0' && c <= '9') {
    res = res * 10 + c - '0';
    c = fgc();
  }
  return res * neg;
}
const int MAXN = 100005;
int N;
std::vector<int> gra[MAXN];
int rt;
std::queue<int> que;
bool vis[MAXN];
int dis[MAXN];
struct Node {
  int u, rt, dis;
  inline bool operator<(const Node &rhs) const { return dis < rhs.dis; }
};
std::priority_queue<Node> pq;
bool del[MAXN];
inline void dfs(int u, int fa, int rt, int d) {
  pq.push(Node{u, rt, d});
  for (int v : gra[u]) {
    if (del[v] || v == fa) continue;
    dfs(v, u, rt, d + 1);
  }
}
int fa[MAXN];
inline void dfsfa(int u, int f) {
  fa[u] = f;
  for (int v : gra[u]) {
    if (v == f) continue;
    dfsfa(v, u);
  }
}
int ut, vt, ans[MAXN], tot = 1;
int main() {
  N = readint();
  ans[1] = 1;
  for (int i = 1; i < N; i++) {
    ut = readint();
    vt = readint();
    gra[vt].push_back(ut);
    gra[ut].push_back(vt);
  }
  que.push(1);
  vis[1] = true;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (dis[u] > dis[rt]) {
      rt = u;
    }
    for (int v : gra[u]) {
      if (vis[v]) continue;
      vis[v] = true;
      dis[v] = dis[u] + 1;
      que.push(v);
    }
  }
  dfsfa(rt, 0);
  del[rt] = true;
  for (int v : gra[rt]) {
    dfs(v, rt, v, 1);
  }
  while (!pq.empty() && ans[tot] < N) {
    rt = pq.top().rt;
    ans[++tot] = ans[tot - 1] + pq.top().dis;
    for (int u = pq.top().u; u != rt; u = fa[u]) {
      del[u] = true;
      for (int v : gra[u]) {
        if (v == fa[u]) continue;
        dfs(v, u, v, 1);
      }
    }
    del[rt] = true;
    for (int v : gra[rt]) {
      if (v == fa[rt]) continue;
      dfs(v, rt, v, 1);
    }
    while (!pq.empty() && del[pq.top().rt]) pq.pop();
  }
  for (int i = 1; i <= N; i++) {
    printf("%d ", ans[i] ? ans[i] : N);
  }
  return 0;
}
