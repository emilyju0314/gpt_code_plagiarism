#include <bits/stdc++.h>
using namespace std;
int read() {
  char c;
  int sum = 0, f = 1;
  c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * f;
}
vector<int> edge[1000005];
int n, m, num, cnt, fa[1000005];
bool vis[1000005], loop[1000005];
long long ans;
void init() {
  for (int i = 1; i <= n; i++) fa[i] = i;
}
int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
void unio(int x, int y) {
  x = getfa(x);
  y = getfa(y);
  if (x != y) fa[y] = x;
}
int main() {
  n = read();
  m = read();
  init();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    edge[u].push_back(v);
    if (u == v) {
      num++, loop[u] = 1;
      continue;
    }
    edge[v].push_back(u);
    unio(u, v);
  }
  for (int i = 1; i <= n; i++) {
    if (edge[i].size() == 0) continue;
    if (fa[i] == i) cnt++;
  }
  if (cnt > 1) return puts("0"), 0;
  for (int i = 1; i <= n; i++) {
    long long tmp = edge[i].size();
    if (loop[i]) tmp--;
    ans += tmp * (tmp - 1) / 2;
  }
  ans += (long long)num * (m - num);
  ans += (long long)num * (num - 1) / 2;
  printf("%lld\n", ans);
  return 0;
}
