#include <bits/stdc++.h>
using namespace std;
int n, a[3][2010], len[3], l[3], ans[4010][2], cnt = 0, st[2010], t, mx, mn;
void op(int x, int k) {
  if (!k) return;
  if (k > l[x] || n - len[x] + 1 < k) puts("NO"), exit(0);
  for (int i = len[x] + k - 1; i >= len[x]; i--)
    a[x + 1][--len[x + 1]] = a[x][i];
  len[x] += k;
  ans[++cnt][0] = x + 1, ans[cnt][1] = k;
}
int main() {
  scanf("%d%d%d", &n, &l[0], &l[1]), len[0] = 1, len[1] = n + 1, len[2] = n + 1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[0][i]);
  while (len[2] > 1) {
    bool falg = true;
    while (falg) {
      falg = false;
      for (int i = len[0]; i <= n; i++) {
        if (a[0][i] == len[2] - 1) {
          int l = i - len[0] + 1;
          while (l--) op(0, 1);
        } else if (a[0][i] + 1 < a[0][i + 1])
          break;
      }
      for (int i = len[1]; i <= n; i++) {
        if (a[1][i] == len[2] - 1) {
          op(1, i - len[1] + 1);
          falg = true;
        }
      }
    }
    st[t = 0] = len[0] - 1, mn = mx = a[0][len[0]];
    for (int i = len[0]; i <= n; i++) {
      mn = min(mn, a[0][i]), mx = max(mx, a[0][i]);
      if (a[0][i] + 1 != a[0][i + 1]) st[++t] = i;
      if (i == n || a[0][i] + 1 < a[0][i + 1]) break;
    }
    if (mx - mn + 1 > st[t] - len[0] + 1)
      op(0, st[t] - len[0] + 1);
    else {
      mx = st[1] - st[0];
      for (int i = 1; i <= t; i++) mx = max(st[i] - st[i - 1], mx);
      if (mx <= l[0] && st[t] - st[0] <= l[1]) {
        for (int i = 1; i <= t; i++) op(0, st[i] - len[0] + 1);
      } else if (t == 1)
        while (len[0] - 1 < st[t]) op(0, 1);
      else if (t > 2)
        op(0, st[t] - len[0] + 1);
      else {
        bool falg = false;
        for (int i = len[0]; i <= st[t]; i++) {
          if (max(i - len[0] + 1, st[2] - i) <= l[0] &&
              max(abs(st[1] - i), st[2] - len[0] + 1 - abs(st[1] - i)) <=
                  l[1]) {
            op(0, i - len[0] + 1);
            if (st[t] - i) op(0, st[t] - i);
            falg = true;
            break;
          }
        }
        if (!falg) puts("NO"), exit(0);
      }
    }
    for (int i = len[1]; i < n; i++)
      if (a[1][i] + 1 < a[1][i + 1]) puts("NO"), exit(0);
  }
  printf("YES\n%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
}
