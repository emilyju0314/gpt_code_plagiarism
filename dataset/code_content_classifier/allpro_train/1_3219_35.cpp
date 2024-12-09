#include <bits/stdc++.h>
using namespace std;
const long long N = 1009, INF = 0x3f3f3f3f3f3f;
struct AC_auto {
  long long ch[14];
  long long end, fail;
} AC[400009];
long long n, m, x, ans = -INF, cnt, num, f[(1 << 14) + 9][N];
long long stk[400009], top, g[N][18], pos[N][18];
char ch[400009];
inline void build(char *s, long long c) {
  long long now = 0, len = strlen(s + 1);
  for (long long i = 1; i <= len; i++) {
    if (!AC[now].ch[s[i] - 'a']) AC[now].ch[s[i] - 'a'] = ++cnt;
    now = AC[now].ch[s[i] - 'a'];
  }
  AC[now].end += c;
}
inline void build_fail() {
  queue<long long> Q;
  for (long long i = 0; i < 14; i++) {
    if (AC[0].ch[i]) Q.push(AC[0].ch[i]);
  }
  long long now = 0;
  while (!Q.empty()) {
    long long u = Q.front();
    Q.pop();
    AC[u].end += AC[AC[u].fail].end;
    for (long long i = 0; i < 14; i++) {
      if (AC[u].ch[i]) {
        AC[AC[u].ch[i]].fail = AC[AC[u].fail].ch[i];
        Q.push(AC[u].ch[i]);
      } else
        AC[u].ch[i] = AC[AC[u].fail].ch[i];
    }
  }
}
inline long long calc(long long u, long long x) {
  long long res = 0, bu = u;
  for (long long i = 1; i <= top; i++) {
    u = AC[u].ch[stk[i]];
    res += AC[u].end;
  }
  pos[bu][x] = u;
  return res;
}
inline long long get(long long x) {
  long long res = 0;
  while (x) {
    if (x & 1) {
      res++;
    }
    x >>= 1;
  }
  return res;
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%s", ch + 1);
    scanf("%lld", &x);
    build(ch, x);
  }
  build_fail();
  scanf("%s", ch + 1);
  long long len = strlen(ch + 1);
  for (long long i = 1; i <= len + 1; i++) {
    if (ch[i] == '?' || i == len + 1) {
      for (long long j = 0; j <= cnt; j++) g[j][num] = calc(j, num);
      top = 0;
      num++;
    } else
      stk[++top] = ch[i] - 'a';
  }
  memset(f, -INF, sizeof f);
  ans = -INF;
  f[0][pos[0][0]] = g[0][0];
  for (long long S = 0; S < (1 << 14); S++) {
    long long k = get(S) + 1;
    if (k > num) continue;
    if (k == num) {
      for (long long i = 0; i <= cnt; i++) ans = max(ans, f[S][i]);
      continue;
    }
    for (long long i = 0; i <= cnt; i++)
      for (long long j = 0; j < 14; j++)
        if (!((1 << j) & S)) {
          long long u = AC[i].ch[j], S1 = S | (1 << j), v = pos[u][k];
          f[S1][v] = max(f[S1][v], f[S][i] + AC[u].end + g[u][k]);
        }
  }
  printf("%lld", ans);
  return 0;
}
