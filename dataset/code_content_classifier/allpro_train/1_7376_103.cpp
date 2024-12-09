#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 5e5 + 10, mod = 998244353;
int n, q;
char s[N];
struct mat {
  int a[2][2];
  inline int calc(int x) {
    if (x >= 19 || x <= 9) return 0;
    return 19 - x;
  }
  inline void init(int x, int y) {
    a[0][0] = 0, a[1][0] = 1;
    a[0][1] = calc(x * 10 + y), a[1][1] = x + 1;
  }
  inline mat operator*(const mat &p) const {
    mat ret;
    for (register int i = (0); i <= (1); i++)
      for (register int j = (0); j <= (1); j++) {
        ret.a[i][j] =
            (1ll * a[i][0] * p.a[0][j] + 1ll * a[i][1] * p.a[1][j]) % mod;
      }
    return ret;
  }
} v[N << 2];
inline void Build(int u, int l, int r) {
  if (l == r) return v[u].init(s[l] - '0', s[l - 1] - '0'), void(0);
  int mid = l + r >> 1;
  Build(u << 1, l, mid), Build(u << 1 ^ 1, mid + 1, r);
  v[u] = v[u << 1] * v[u << 1 ^ 1];
}
inline void update(int u, int l, int r, int ql) {
  if (l == r) return v[u].init(s[l] - '0', s[l - 1] - '0'), void(0);
  int mid = l + r >> 1;
  if (ql <= mid)
    update(u << 1, l, mid, ql);
  else
    update(u << 1 ^ 1, mid + 1, r, ql);
  v[u] = v[u << 1] * v[u << 1 ^ 1];
}
int main() {
  n = read(), q = read(), scanf("%s", s + 1);
  reverse(s + 1, s + 1 + n);
  if (n >= 2) Build(1, 2, n);
  for (register int i = (1); i <= (q); i++) {
    int x = n - read() + 1, y = read();
    s[x] = y + '0';
    if (n == 1) {
      printf("%d\n", y + 1);
      continue;
    }
    if (x > 1) update(1, 2, n, x);
    if (x + 1 <= n) update(1, 2, n, x + 1);
    mat tmp;
    tmp.a[0][0] = 1, tmp.a[0][1] = s[1] - '0' + 1;
    tmp.a[1][0] = tmp.a[1][1] = 0;
    tmp = tmp * v[1];
    printf("%d\n", tmp.a[0][1]);
  }
}
