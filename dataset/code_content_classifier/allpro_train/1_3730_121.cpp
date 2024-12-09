#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, cnt = 0;
int to[N << 2];
int nxt[N << 1];
int head[N];
int siz[N];
int d[N];
void add(int u, int v) {
  to[++cnt] = v;
  nxt[cnt] = head[u];
  head[u] = cnt;
}
void dfs(int u, int fa) {
  siz[u] = 1;
  for (int i = head[u]; i; i = nxt[i]) {
    if (to[i] != fa) {
      d[to[i]] = d[u] + 1;
      dfs(to[i], u);
      siz[u] += siz[to[i]];
    }
  }
}
int main() {
  scanf("%d", &n);
  int a, b;
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &a, &b);
    add(a, b);
    add(b, a);
  }
  dfs(1, -1);
  long long ans = 0, num = 0;
  for (int i = 1; i <= n; i++) {
    ans += (long long)siz[i] * (long long)(n - siz[i]);
    if (d[i] & 1) num++;
  }
  ans += num * (long long)(n - num);
  printf("%lld", ans >> 1);
  return 0;
}
