#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 1e9 + 7;
const int MAXN = 300005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int a[MAXN], vis[20], match[20], bse[20], id[20], n;
void solve(int l, int r, int p) {
  if (l == r) {
    int ans = 0;
    for (int i = 0; i <= p; i++)
      if ((l >> i) & 1) ans ^= a[id[i]];
    printf("%d ", ans);
    return;
  }
  int mid = (l + r) >> 1;
  if (l < r) {
    solve(l, mid, p);
    solve(r, mid + 1, p);
  } else {
    solve(mid + 1, l, p);
    solve(mid, r, p);
  }
}
void insert(int x, int n, int p) {
  for (int i = n; i >= 0; i--)
    if ((x >> i) & 1) {
      if (!bse[i]) {
        bse[i] = x, id[i] = p;
        return;
      } else
        x ^= bse[i];
    }
}
int query(int x, int n) {
  for (int i = n; i >= 0; i--)
    if (((x >> i) & 1) && (bse[i])) x ^= bse[i];
  return x;
}
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 17; i >= 0; i--) {
    for (int j = 0; j <= i; j++) bse[j] = 0;
    for (int j = 1; j <= n; j++)
      if (a[j] < 1 << (i + 1)) insert(a[j], i, j);
    bool flag = 1;
    for (int j = 0; j <= i; j++)
      if (!bse[j]) flag = 0;
    if (!flag) continue;
    printf("%d\n", i + 1);
    solve(0, (1 << (i + 1)) - 1, i);
    return 0;
  }
  puts("0"), puts("0");
  return 0;
}
