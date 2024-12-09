#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long sum[1000010], fac[1000010], v[2010][2010], f[2010][2010],
    flag1[1000010], a[2010][2010], b[1000010], h1[1000010], h2[1000010],
    h3[1000010], flag[1000010], p[1000010], vis[1000010], n;
long long js(long long x, long long y) {
  if (v[x][y]) return f[x][y];
  v[x][y] = 1;
  if (x == 0) return f[x][y] = 1;
  if (x != y) {
    f[x][y] += js(x - 1, y) * (x - y) % mod;
    if (y) f[x][y] += js(x - 1, y - 1) * y % mod;
  } else {
    if (y >= 2) f[x][y] += js(x - 1, y - 2) * (y - 1) % mod;
    if (x != y) f[x][y] += js(x - 1, y - 1) * (x - y) % mod;
  }
  f[x][y] %= mod;
  return f[x][y];
}
void clear(long long num, long long r, long long l) {
  if (r == l) {
    b[num] = 1;
    return;
  }
  long long mid = (r + l) / 2;
  clear(num * 2, r, mid);
  clear(num * 2 + 1, mid + 1, l);
  b[num] = b[num * 2] + b[num * 2 + 1];
}
void change(long long num, long long r, long long l, long long x) {
  if (r == l) {
    b[num] = 0;
    return;
  }
  long long mid = (r + l) / 2;
  if (x <= mid)
    change(num * 2, r, mid, x);
  else
    change(num * 2 + 1, mid + 1, l, x);
  b[num] = b[num * 2] + b[num * 2 + 1];
}
long long find(long long num, long long r, long long l, long long x) {
  if (l <= x) return b[num];
  long long mid = (r + l) / 2, ans = 0;
  ans += find(num * 2, r, mid, x);
  if (mid < x) ans += find(num * 2 + 1, mid + 1, l, x);
  return ans;
}
long long find1(long long x) {
  long long ans = 0;
  while (x) {
    ans += p[x];
    x -= x & (-x);
  }
  return ans;
}
void add(long long x) {
  while (x <= n) {
    p[x]++;
    x += x & (-x);
  }
}
signed main() {
  long long i, j, ans = 0;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%lld", &a[i][j]);
  long long w = js(n, n);
  long long now = 1;
  for (i = n; i >= 1; i--) {
    sum[i] = now;
    now = now * w % mod;
  }
  fac[0] = 1;
  for (i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  for (i = 1; i <= n; i++) {
    ans = (ans + fac[n - i] * (a[1][i] - 1 - find1(a[1][i] - 1) + mod) % mod *
                     sum[1] % mod) %
          mod;
    add(a[1][i]);
  }
  for (i = 2; i <= n; i++) {
    clear(1, 1, n);
    for (j = 1; j <= n; j++) {
      vis[j] = 0;
      p[j] = 0;
      flag[j] = 0;
      flag1[j] = 0;
    }
    for (j = 1; j <= n; j++) {
      if (!vis[a[i - 1][j]] && a[i - 1][j] < a[i][j]) flag[j] = 1;
      if (!vis[a[i - 1][j]]) flag1[j] = 1;
      if (a[i][j] != 1)
        h1[j] = find(1, 1, n, a[i][j] - 1);
      else
        h1[j] = 0;
      h2[j] = b[1];
      change(1, 1, n, a[i - 1][j]);
      change(1, 1, n, a[i][j]);
      vis[a[i][j]] = 1;
    }
    for (j = n; j >= 1; j--) {
      h3[j] = find1(a[i][j]) - flag[j];
      add(a[i][j]);
    }
    for (j = 1; j <= n; j++) {
      h1[j] -= flag[j];
      if (h1[j]) {
        ans += h1[j] * js(n - j, h2[j] - 1 - flag1[j]) % mod * sum[i] % mod;
        ans %= mod;
      }
      if (h3[j] - h1[j]) {
        ans +=
            (h3[j] - h1[j]) * js(n - j, h2[j] - flag1[j]) % mod * sum[i] % mod;
        ans %= mod;
      }
    }
  }
  printf("%lld\n", ans);
}
