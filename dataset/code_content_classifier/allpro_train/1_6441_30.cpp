#include <bits/stdc++.h>
using namespace std;
struct Tree {
  vector<int> a[300005];
  long long g[300005], f[300005], sum;
  int ch, size[300005], n;
  void dfs1(int k, int fa) {
    size[k] = 0;
    f[k] = 0;
    for (int i = 0, x; i < a[k].size(); i++)
      if ((x = a[k][i]) != fa) dfs1(x, k), f[k] += f[x], size[k] += size[x];
    f[k] += (size[k]++);
  }
  void dfs2(int k, int fa) {
    g[k] = (k > 1) ? g[fa] - size[k] + (n - size[k]) : f[k];
    for (int i = 0, x; i < a[k].size(); i++)
      if ((x = a[k][i]) != fa) dfs2(x, k);
  }
  void init() {
    dfs1(1, 0);
    dfs2(1, 0);
    g[ch = 0] = -1;
    sum = 0;
    for (int i = 1; i <= n; sum += g[i++])
      if (g[i] > g[ch]) ch = i;
    sum >>= 1;
  }
  void read() {
    for (int i = 1; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      a[x].push_back(y);
      a[y].push_back(x);
    }
  }
} A[3], B, C;
int i, j;
long long ans;
void Clear(Tree &c) {
  for (int i = 1; i <= c.n; i++)
    c.a[i].clear(), c.f[i] = c.g[i] = c.size[i] = 0;
  c.n = c.sum = c.ch = 0;
}
void Merge(Tree &c, const Tree &a, const Tree &b) {
  c.n = a.n + b.n;
  for (int i = 1; i <= c.n; i++) c.a[i].clear();
  for (int i = 1; i <= a.n; i++)
    for (int j = 0; j < a.a[i].size(); j++) c.a[i].push_back(a.a[i][j]);
  for (int i = 1; i <= b.n; i++)
    for (int j = 0; j < b.a[i].size(); j++)
      c.a[i + a.n].push_back(b.a[i][j] + a.n);
  c.a[a.ch].push_back(b.ch + a.n);
  c.init();
}
int main() {
  scanf("%d%d%d", &A[0].n, &A[1].n, &A[2].n);
  ans = 0;
  A[0].read();
  A[1].read();
  A[2].read();
  A[0].init();
  A[1].init();
  A[2].init();
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      if (i != j) {
        Clear(B);
        Clear(C);
        Merge(B, A[i], A[j]);
        Merge(C, A[3 - i - j], B);
        ans = max(ans, C.sum);
        Clear(B);
        Clear(C);
        Merge(B, A[i], A[j]);
        Merge(C, B, A[3 - i - j]);
        ans = max(ans, C.sum);
      }
  printf("%I64d\n", ans);
}
