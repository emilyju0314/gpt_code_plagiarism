#include <bits/stdc++.h>
#pragma GCC optimize("O2")
char xB[1 << 15], *xS = xB, *xT = xB;
const int inf = 0x3fffffff;
const int maxn = 2017;
const int mod = 1000000007;
using namespace std;
__attribute__((optimize("-O3"))) inline int read() {
  int f = 1, x = 0;
  char ch =
      (xS == xT && (xT = (xS = xB) + fread(xB, 1, 1 << 15, stdin), xS == xT)
           ? 0
           : *xS++);
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = (xS == xT && (xT = (xS = xB) + fread(xB, 1, 1 << 15, stdin), xS == xT)
              ? 0
              : *xS++);
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = (xS == xT && (xT = (xS = xB) + fread(xB, 1, 1 << 15, stdin), xS == xT)
              ? 0
              : *xS++);
  }
  return f * x;
}
int p[100001], q[100001], ans;
int n, m, s;
__attribute__((optimize("-O3"))) bool jud(int x) {
  int ac = 0, now = 1;
  for (register int i = 1; i <= n; ++i) {
    while (abs(q[now] - p[i]) + abs(q[now] - s) > x && now <= m) now++;
    if (now <= m)
      now++, ac++;
    else
      break;
  }
  if (ac < n) return 0;
  return 1;
}
__attribute__((optimize("-O3"))) int main() {
  n = read(), m = read(), s = read();
  for (register int i = 1; i <= n; ++i) {
    p[i] = read();
  }
  for (register int i = 1; i <= m; ++i) {
    q[i] = read();
  }
  sort(p + 1, p + n + 1);
  sort(q + 1, q + m + 1);
  long long l = 0, r = inf << 1;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (jud(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  cout << ans;
}
