#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
int dfn[100010], depth[100010], fa[100010][23];
int head[100010], nxt[200010], end[200010], cou = 0, cnt = 0;
void link(int a, int b) {
  nxt[++cou] = head[a];
  head[a] = cou;
  end[cou] = b;
}
int ans = 0, n, k, idx = 0;
struct cmp {
  bool operator()(int a, int b) { return dfn[a] < dfn[b]; }
};
std::set<int, cmp> s;
int lca(int a, int b) {
  if (depth[a] < depth[b]) std::swap(a, b);
  int delta = depth[a] - depth[b];
  for (int i = 0; i <= 20; i++)
    if (delta & (1 << i)) a = fa[a][i];
  if (a == b) return a;
  for (int i = 20; i >= 0; i--)
    if (fa[a][i] != fa[b][i]) {
      a = fa[a][i];
      b = fa[b][i];
    }
  return fa[a][0];
}
void insert(int x) {
  s.insert(x);
  std::set<int, cmp>::iterator it = s.find(x);
  int pre, nxt;
  if (it != s.begin()) {
    it--;
    pre = *it;
    it++;
  } else
    pre = *(s.rbegin());
  it++;
  if (it != s.end())
    nxt = *it;
  else
    nxt = *s.begin();
  if (pre == x)
    ans++;
  else
    ans += depth[x] + depth[lca(pre, nxt)] - depth[lca(pre, x)] -
           depth[lca(nxt, x)];
}
void erase(int x) {
  std::set<int, cmp>::iterator it = s.find(x);
  int pre, nxt;
  if (it != s.begin()) {
    it--;
    pre = *it;
    it++;
  } else
    pre = *(s.rbegin());
  it++;
  if (it != s.end())
    nxt = *it;
  else
    nxt = *s.begin();
  if (pre == x)
    ans--;
  else
    ans -= depth[x] + depth[lca(pre, nxt)] - depth[lca(pre, x)] -
           depth[lca(nxt, x)];
  s.erase(x);
}
bool check(int lim) {
  s.clear();
  ans = 0;
  for (int i = 1; i < lim; i++) insert(i);
  for (int i = 1; i <= n - lim + 1; i++) {
    insert(i + lim - 1);
    if (ans <= k) return true;
    erase(i);
  }
  return false;
}
void dfs(int cur, int last) {
  dfn[cur] = ++idx;
  fa[cur][0] = last;
  for (int i = 1; i <= 20; i++) fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
  depth[cur] = depth[last] + 1;
  for (int x = head[cur]; x != -1; x = nxt[x])
    if (end[x] != last) dfs(end[x], cur);
}
int main() {
  memset(head, -1, sizeof(head));
  n = inp();
  k = inp();
  for (int i = 1; i < n; i++) {
    int a = inp();
    int b = inp();
    link(a, b);
    link(b, a);
  }
  dfs(1, 0);
  int l = 1;
  int r = n;
  check(n);
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  printf("%d\n", l);
}
