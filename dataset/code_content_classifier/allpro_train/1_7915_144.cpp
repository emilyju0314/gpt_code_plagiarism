#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long n, m, d, t[N], f[2][N], flag, a[N];
long long deq[N * 2], head, tail, ans, sum, b[N];
int read() {
  char ch = getchar();
  int res = 0, w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * w;
}
int main() {
  n = read(), m = read(), d = read();
  for (register int i = 1; i <= m; i++) {
    a[i] = read();
    b[i] = read();
    t[i] = read();
    sum += b[i];
  }
  memset(f, 0x3f3f3f3f, sizeof(f));
  flag = 1;
  for (register int i = 1; i <= n; i++) f[1][i] = abs(a[1] - i);
  for (register int i = 2; i <= m; i++) {
    head = 1, tail = 0;
    int now = i & 1, last = i & 1 ^ 1;
    memset(f[now], 0x3f3f3f3f, sizeof(f[now]));
    for (register int j = 1; j <= n; j++) {
      while (head <= tail && deq[head] < j - d * (t[i] - t[i - 1])) ++head;
      while (head <= tail && f[last][deq[tail]] > f[last][j]) --tail;
      deq[++tail] = j;
      f[now][j] = min(f[now][j], f[last][deq[head]] + abs(a[i] - j));
    }
    head = 1, tail = 0;
    for (register int j = n; j >= 1; j--) {
      while (head <= tail && deq[head] > j + d * (t[i] - t[i - 1])) ++head;
      while (head <= tail && f[last][deq[tail]] > f[last][j]) --tail;
      deq[++tail] = j;
      f[now][j] = min(f[now][j], f[last][deq[head]] + abs(a[i] - j));
    }
    flag ^= 1;
  }
  ans = 1e18 / 2;
  for (register int i = 1; i <= n; i++) {
    ans = min(ans, f[m & 1][i]);
  }
  printf("%lld\n", sum - ans);
  return 0;
}
