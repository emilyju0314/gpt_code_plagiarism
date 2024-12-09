#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long num = 0, neg = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar();
  }
  return num * neg;
}
int got[21], n, m, id[1000010], id_cnt;
int stk[21], tot, f[2000010];
bool vis[1000010];
int cnt, to[2000010], nxt[2000010], head[1000010], in[1000010], out[1000010];
inline void insert(int x, int y) {
  to[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt;
  out[x]++, in[y]++;
}
inline void dfs(int u, int s) {
  vis[u] = s;
  if (id[u]) {
    got[s] |= (1 << id[u] - 1);
  }
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (vis[v] == s) continue;
    dfs(v, s);
  }
  return;
}
inline int getcnt(int x) {
  int res = 0;
  while (x) res++, x -= x & -x;
  return res;
}
int main() {
  n = read(), m = read();
  for (int i = 1, x, y; i <= m; i++) x = read(), y = read(), insert(x, y);
  for (int i = 1; i <= n; i++)
    if (!out[i]) id[i] = ++id_cnt;
  for (int i = 1; i <= n; i++)
    if (!in[i]) {
      stk[++tot] = i;
      dfs(i, i);
    }
  for (int i = 1; i <= tot; i++)
    for (int j = 0; j < (1 << tot); j++) f[j | (1 << i - 1)] |= got[stk[i]];
  for (int j = 1; j < (1 << tot) - 1; j++) {
    if (getcnt(j) == getcnt(f[j])) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
