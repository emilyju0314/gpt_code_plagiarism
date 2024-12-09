#include <bits/stdc++.h>
using namespace std;
inline void in(int &x) {
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
}
int n, m;
vector<int> v[100005];
int head[100005], success[100005], fa[100005], X[100005], Y[100005],
    dfn[100005], dep[100005], sz[100005], tree[100005 << 1], tot = 0;
inline int ID(int l, int r) { return (l + r) | (l != r); }
inline int minn(int x, int y) { return dep[x] > dep[y] ? x : y; }
void dfs(int from, int f) {
  dep[from] = dep[f] + 1;
  sz[from] = 1;
  fa[from] = f;
  int mx = 0;
  for (int i = 0; i < v[from].size(); ++i) {
    int to = v[from][i];
    if (to == f) continue;
    dfs(to, from);
    if (sz[to] > mx) {
      mx = sz[to];
      success[from] = to;
    }
    sz[from] += sz[to];
  }
}
void make_chain(int from, bool in_chain) {
  if (in_chain)
    head[from] = head[fa[from]];
  else
    head[from] = from;
  dfn[from] = ++tot;
  if (success[from]) make_chain(success[from], 1);
  for (int i = 0; i < v[from].size(); ++i) {
    int to = v[from][i];
    if (to == fa[from] || to == success[from]) continue;
    make_chain(to, 0);
  }
}
inline void push_down(int k, int l, int r) {
  int mid = l + r >> 1, ls = ID(l, mid), rs = ID(mid + 1, r);
  tree[ls] += tree[k];
  tree[rs] += tree[k];
  tree[k] = 0;
}
void update(int k, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    ++tree[k];
    return;
  }
  int mid = l + r >> 1;
  push_down(k, l, r);
  if (L <= mid) update(ID(l, mid), l, mid, L, R);
  if (mid < R) update(ID(mid + 1, r), mid + 1, r, L, R);
}
int query(int k, int l, int r, int p) {
  if (l == r) return tree[k];
  int mid = l + r >> 1;
  push_down(k, l, r);
  if (p <= mid)
    return query(ID(l, mid), l, mid, p);
  else
    return query(ID(mid + 1, r), mid + 1, r, p);
}
void Update(int x, int y) {
  while (head[x] != head[y]) {
    if (dep[head[x]] < dep[head[y]]) swap(x, y);
    update(ID(1, tot), 1, tot, dfn[head[x]], dfn[x]);
    x = fa[head[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  if (dfn[x] != dfn[y]) update(ID(1, tot), 1, tot, dfn[x] + 1, dfn[y]);
}
int main() {
  in(n);
  for (int i = 1; i < n; ++i) {
    in(X[i]);
    in(Y[i]);
    v[X[i]].push_back(Y[i]);
    v[Y[i]].push_back(X[i]);
  }
  dfs(1, 0);
  make_chain(1, 0);
  in(m);
  while (m--) {
    int s, t;
    in(s);
    in(t);
    Update(s, t);
  }
  for (int i = 1; i < n; ++i)
    printf("%d%c", query(ID(1, tot), 1, tot, dfn[minn(X[i], Y[i])]),
           i == n - 1 ? '\n' : ' ');
  return 0;
}
