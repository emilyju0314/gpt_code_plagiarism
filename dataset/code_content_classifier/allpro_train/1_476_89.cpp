#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
using namespace std;
struct EDGE {
  int to, next;
  EDGE() {}
  EDGE(int to, int next) : to(to), next(next) {}
} edge[maxn * 2];
int head[maxn], edgecnt;
void init() {
  memset(head, -1, sizeof(head));
  edgecnt = 0;
}
void add(int s, int t) {
  edge[edgecnt] = EDGE(t, head[s]);
  head[s] = edgecnt++;
}
int sz[maxn];
int mxsz[maxn], mxid[maxn], submx[maxn];
int mx[maxn];
int mxxxx[maxn];
int n;
void dfs(int u, int fa) {
  sz[u] = 1;
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs(v, u);
    sz[u] += sz[v];
    if (sz[v] > mx[u]) {
      mx[u] = sz[v];
      mxxxx[u] = v;
    }
    if (sz[v] <= n / 2) {
      if (sz[v] >= mxsz[u]) {
        mxsz[u] = sz[v];
        mxid[u] = v;
      }
    }
    if (mxsz[v] >= mxsz[u]) {
      mxsz[u] = mxsz[v];
      mxid[u] = v;
    }
  }
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    if (sz[v] <= n / 2 && mxid[u] != v && sz[v] > submx[u]) submx[u] = sz[v];
    if (mxid[u] != v && mxsz[v] > submx[u]) submx[u] = mxsz[v];
  }
}
bool ans[maxn];
void dfs2(int u, int fa, int mxs) {
  if (max(n - sz[u], mx[u]) <= n / 2) ans[u] = 1;
  if (n - sz[u] > mx[u]) {
    if (n - sz[u] - mxs <= n / 2)
      ans[u] = 1;
    else
      ans[u] = 0;
  } else {
    int v = mxxxx[u];
    if (sz[v] - mxsz[v] <= n / 2)
      ans[u] = 1;
    else
      ans[u] = 0;
  }
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    if (v == mxid[u]) {
      int m = mxs;
      if (n - sz[u] <= n / 2) m = n - sz[u];
      m = max(m, submx[u]);
      dfs2(v, u, m);
    } else {
      int m = mxs;
      if (n - sz[u] <= n / 2) m = n - sz[u];
      m = max(m, mxsz[u]);
      dfs2(v, u, m);
    }
  }
}
int main() {
  scanf("%d", &n);
  init();
  for (int i = 1; i < n; i++) {
    int s, t;
    scanf("%d %d", &s, &t);
    add(s, t);
    add(t, s);
  }
  dfs(1, 0);
  dfs2(1, 0, 0);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
