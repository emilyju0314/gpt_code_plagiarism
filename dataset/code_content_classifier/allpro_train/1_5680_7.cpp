#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2222;
int l[MAXN], r[MAXN], p[MAXN];
bool flag[MAXN];
int s[MAXN];
int n, m;
vector<int> v;
int Query(int a, int b, int c) {
  char st[5];
  printf("%d %d %d\n", a, b, c);
  fflush(stdout);
  scanf("%s", st);
  return st[0] - 'X';
}
void DFS(int u, int pre) {
  v.push_back(u);
  s[u] = 1;
  if (l[u] > 0 && !flag[l[u]]) DFS(l[u], u), s[u] += s[l[u]];
  if (r[u] > 0 && !flag[r[u]]) DFS(r[u], u), s[u] += s[r[u]];
  return;
}
void InsertNode(int x, int y, int z) {
  if (l[p[x]] == x)
    l[p[x]] = z;
  else
    r[p[x]] = z;
  p[z] = p[x];
  p[x] = p[y] = z;
  l[z] = x;
  r[z] = y;
  return;
}
void AddLeaf(int root, int newleaf) {
  int c = 0;
  v.clear();
  memset(s, 0, sizeof(s));
  DFS(root, p[root]);
  for (auto &i : v)
    if (s[i] * 2 > s[root] && (c == 0 || s[i] < s[c])) c = i;
  if (l[c] == 0)
    InsertNode(c, newleaf, n + newleaf);
  else {
    int lm = c, rm = c, res;
    flag[c] = true;
    while (l[lm]) lm = l[lm];
    while (r[rm]) rm = r[rm];
    res = Query(lm, newleaf, rm);
    if (res == 2) {
      if (c == root)
        InsertNode(c, newleaf, n + newleaf);
      else
        AddLeaf(root, newleaf);
    } else if (res == 0) {
      if (flag[l[c]])
        InsertNode(l[c], newleaf, n + newleaf);
      else
        AddLeaf(l[c], newleaf);
    } else {
      if (flag[r[c]])
        InsertNode(r[c], newleaf, n + newleaf);
      else
        AddLeaf(r[c], newleaf);
    }
  }
  return;
}
int main() {
  int root;
  scanf("%d", &n);
  m = 2 * n - 1;
  root = n;
  for (int i = 1; i < n; ++i) {
    memset(flag, 0, sizeof(flag));
    AddLeaf(root, i);
    while (p[root] > 0) root = p[root];
  }
  printf("-1\n");
  for (int i = 1; i <= m; ++i) printf("%d ", p[i] == 0 ? -1 : p[i]);
  fflush(stdout);
  return 0;
}
