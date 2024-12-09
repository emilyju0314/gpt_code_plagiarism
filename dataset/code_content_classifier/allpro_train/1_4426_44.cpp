#include <bits/stdc++.h>
inline int read() {
  char c = getchar();
  int x = 0, ft = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') ft = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x * ft;
}
const int N = 2e5 + 5;
int n, q, p[N], val[N], ch[N][2], deg[N], dep[N], mx_dep;
int col[N], cnt[N][27], f[N][27], tag[N], no_solution;
inline void upd(int u) {
  if (tag[u]) --tag[u], --no_solution;
  int sum = 0;
  for (int c = 1; c <= 26; ++c) {
    f[u][c] = 0;
    for (int i = 0; i < deg[u]; ++i) {
      int v = ch[u][i];
      f[u][c] = std::max(f[u][c], f[v][c] + (val[v] == c));
    }
    sum += f[u][c];
  }
  if (sum > mx_dep - dep[u]) ++tag[u], ++no_solution;
  for (int c = 1; c <= 26; ++c) f[u][c] += cnt[u][c];
}
int main() {
  n = read();
  q = read();
  static char opt[5];
  col[1] = 1;
  for (int i = 2; i <= n; ++i) {
    p[i] = read();
    scanf("%s", opt);
    col[i] = i;
    val[i] = (opt[0] == '?' ? 0 : opt[0] - 'a' + 1);
    ch[p[i]][deg[p[i]]++] = i;
    dep[i] = dep[p[i]] + 1;
  }
  for (int i = 1; i <= n; ++i)
    if (!deg[i]) {
      if (!mx_dep)
        mx_dep = dep[i];
      else if (dep[i] != mx_dep) {
        while (q--) puts("Fou");
        return 0;
      }
    }
  for (int i = n; i >= 1; --i)
    if (deg[p[i]] == 1) {
      ch[p[i]][0] = ch[i][0];
      ch[p[i]][1] = ch[i][1];
      deg[p[i]] = deg[i];
      for (int c = 1; c <= 26; ++c) cnt[p[i]][c] += cnt[i][c];
      ++cnt[p[i]][val[i]];
      dep[p[i]] = dep[i];
      col[i] = p[i];
    }
  for (int i = 1; i <= n; ++i) col[i] = col[col[i]];
  for (int i = n; i >= 1; --i)
    if (i == col[i]) upd(i);
  for (int i = 1; i <= q; ++i) {
    int x = read(), v;
    scanf("%s", opt);
    v = (opt[0] == '?' ? 0 : opt[0] - 'a' + 1);
    if (x == col[x])
      val[x] = v;
    else {
      --cnt[col[x]][val[x]];
      ++cnt[col[x]][val[x] = v];
    }
    for (x = col[x]; x != 1; x = col[p[x]]) upd(x);
    upd(1);
    if (no_solution)
      puts("Fou");
    else {
      printf("Shi ");
      int cw = mx_dep, ans = 0;
      for (int c = 1; c <= 26; ++c) ans += c * f[1][c], cw -= f[1][c];
      ans += cw * 351;
      printf("%d\n", ans);
    }
  }
  return 0;
}
