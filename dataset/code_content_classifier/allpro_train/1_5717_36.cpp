#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, p;
int bit[1 << 23];
int ansl[25];
long long ansr[25];
int tot, b[25], tot1, c[25];
long long dp[1 << 23], tag[1 << 23];
inline long long rd() {
  long long x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f ? -x : x;
}
struct node {
  int l, r, t, id;
  inline bool operator<(const node &b) const { return l < b.l; }
} a[25];
inline bool cmp(int x, int y) { return a[x].t < a[y].t; }
void dfs(int s, int tg) {
  if (!s) return;
  int x = tag[s];
  ansr[a[x].id] = dp[s] - a[x].t;
  ansl[a[x].id] = tg;
  dfs(s - (1 << x - 1), tg);
}
int main() {
  n = rd();
  p = rd();
  for (int i = 1; i <= n; ++i) {
    a[i].l = rd();
    int x = rd();
    a[i].r = a[i].l + x - 1;
    a[i].t = rd();
    a[i].id = i;
  }
  sort(a + 1, a + n + 1);
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; ++i) bit[1 << i - 1] = i;
  int maxn = (1 << n);
  dp[0] = 1;
  for (int i = 0; i < maxn; ++i)
    if (dp[i] < 1e15) {
      tot = tot1 = 0;
      for (int j = 1; j <= n; ++j)
        if (!(i & (1 << j - 1)))
          b[++tot] = j;
        else
          c[++tot1] = j;
      sort(b + 1, b + tot + 1, cmp);
      int p1 = 1, p2 = 1;
      long long last = dp[i];
      for (int j = 1; j <= tot; ++j) {
        int now = b[j];
        while (1) {
          bool tg = 0;
          if (last >= a[p1].l && p1 <= n) {
            last = max(last, (long long)a[p1].r + 1);
            p1++;
            tg = 1;
          }
          while (last > a[c[p2]].l && p2 < tot1) p2++;
          if (last <= a[c[p2]].l && p2 <= tot1) {
            int xx = c[p2];
            if (a[xx].l <= last + a[now].t)
              last = max(last, (long long)a[xx].r + 1), p2++, tg = 1;
          }
          if (!tg) break;
        }
        int s = i ^ (1 << now - 1);
        if (last + a[now].t < a[now].l && last + a[now].t < dp[s])
          dp[s] = last + a[now].t, tag[s] = now;
      }
    }
  if (p == 1) {
    if (dp[maxn - 1] < 1e15) {
      dfs(maxn - 1, 1);
      puts("YES");
      for (int j = 1; j <= n; ++j) cout << ansl[j] << " " << ansr[j] << "\n";
    } else
      puts("NO");
  } else {
    for (int i = 0; i < maxn; ++i)
      if (dp[i] < 1e15 && dp[maxn - 1 - i] < 1e15) {
        dfs(i, 1);
        dfs(maxn - 1 - i, 2);
        puts("YES");
        for (int j = 1; j <= n; ++j) cout << ansl[j] << " " << ansr[j] << "\n";
        return 0;
      }
    puts("NO");
  }
  return 0;
}
