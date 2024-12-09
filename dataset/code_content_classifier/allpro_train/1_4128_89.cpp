#include <bits/stdc++.h>
using namespace std;
long long n, first[1000100], nxt[1000100 << 1], tot = 0, val[1000100];
long long in1[1000100], in2[1000100];
long long fa[1000100], size[1000100], vis[1000100];
long long sum, ans1, ans2, ans;
struct Node {
  long long w, num;
} p[1000100];
struct Edge {
  long long u, v;
} edge[1000100 << 1];
long long Read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
    if (c == '-') f *= -1;
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
bool cmp(const Node a, const Node b) {
  if (a.w < b.w)
    return true;
  else
    return false;
}
void Add(long long u, long long v) {
  tot++;
  nxt[tot] = first[u];
  first[u] = tot;
  edge[tot] = (Edge){u, v};
  return;
}
void Join(long long u, long long v) {
  fa[u] = v;
  size[v] += size[u];
  return;
}
long long Find(long long x) {
  if (!x) return 0;
  if (fa[x] == x)
    return x;
  else
    return fa[x] = Find(fa[x]);
}
void Push_in(long long point, long long kind) {
  vis[point] = 1;
  int sons = 0, f1, f2;
  for (long long j = first[point]; j != -1; j = nxt[j]) {
    long long v = edge[j].v;
    if (!vis[v]) continue;
    sons++;
    f1 = Find(v);
    f2 = Find(point);
    sum += val[point] * size[f1] * size[f2] * kind;
    Join(f1, f2);
  }
  return;
}
void Solve() {
  sum = 0;
  for (long long i = 1; i <= n; i++) Push_in(p[i].num, 1);
  ans1 = sum;
  for (long long i = 1; i <= n; i++) fa[i] = i, size[i] = 1;
  memset(vis, 0, sizeof(vis));
  sum = 0;
  for (long long i = n; i >= 1; i--) Push_in(p[i].num, -1);
  ans2 = sum;
  ans = ans1 + ans2;
  return;
}
int main() {
  memset(first, -1, sizeof(first));
  memset(vis, 0, sizeof(vis));
  n = Read();
  for (long long i = 1; i <= n; i++) fa[i] = i, size[i] = 1;
  for (long long i = 1; i <= n; i++)
    p[i].w = Read(), p[i].num = i, val[i] = p[i].w;
  for (long long i = 1; i < n; i++)
    in1[i] = Read(), in2[i] = Read(), Add(in1[i], in2[i]), Add(in2[i], in1[i]);
  sort(p + 1, p + n + 1, cmp);
  Solve();
  printf("%lld\n", ans);
  return 0;
}
