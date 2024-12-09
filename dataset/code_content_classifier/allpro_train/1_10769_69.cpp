#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  register int c = getchar();
  x = 0;
  bool neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) x = (x << 1) + (x << 3) + c - 48;
  if (neg) x = -x;
}
vector<int> e[100005];
int d[100005];
bool b[100005];
long long p[100005], q[100005], z = 0;
void dfs(int x) {
  b[x] = 1;
  for (int u : e[x])
    if (!b[u]) {
      dfs(u);
      p[x] = max(p[x], p[u]);
      q[x] = max(q[x], q[u]);
    }
  z = d[x] + p[x] - q[x];
  if (z > 0)
    q[x] += z;
  else
    p[x] -= z;
}
int main() {
  int n, i, u, v;
  scanf("%d", &n);
  for (i = 1; i < n; ++i) {
    read(u);
    read(v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (i = 1; i <= n; ++i) read(d[i]), b[i] = 0;
  dfs(1);
  printf("%I64d", p[1] + q[1]);
}
