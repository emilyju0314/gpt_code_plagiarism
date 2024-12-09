#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
const int INF = 2147483647;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
template <typename Type>
inline void chkmin(Type &x, const Type &y) {
  if (x > y) x = y;
}
template <typename Type>
inline void chkmax(Type &x, const Type &y) {
  if (x < y) x = y;
}
int n, m;
int mp[MAXN][MAXN];
int f[MAXN][MAXN];
struct Vector {
  int x, y;
  Vector(int x = 0, int y = 0) : x(x), y(y){};
  inline Vector operator+(const Vector &tmp) const {
    return Vector(x + tmp.x, y + tmp.y);
  }
  inline Vector operator-(const Vector &tmp) const {
    return Vector(x - tmp.x, y - tmp.y);
  }
  inline long long operator%(const Vector &tmp) const {
    return 1ll * x * tmp.y - 1ll * y * tmp.x;
  }
  inline int calc(int i) { return x * i + y; }
};
int lst[MAXN], top;
Vector stk[MAXN];
inline int sqr(int x) { return x * x; }
inline void solve() {
  int i, j, k;
  for (i = 0; i <= m; ++i) lst[i] = mp[0][i] - 1;
  for (i = 1; i <= n; ++i) {
    for (j = 0, top = 0; j <= m; ++j) {
      if (!~lst[j]) continue;
      Vector tmp(-2 * j, sqr(j) + sqr(lst[j] - i));
      while (top > 1 && (tmp - stk[top]) % (tmp - stk[top - 1]) <= 0) --top;
      stk[++top] = tmp;
    }
    for (j = 0, k = 1; j <= m; ++j) {
      if (mp[i][j]) {
        lst[j] = i;
        continue;
      }
      while (k < top && stk[k].calc(j) > stk[k + 1].calc(j)) ++k;
      if (top) chkmin(f[i][j], stk[k].calc(j) + sqr(j));
    }
  }
}
int main() {
  int i, j;
  n = read();
  m = read();
  for (i = 0; i <= n; ++i) {
    for (j = 0; j <= m; ++j) scanf("%1d", &mp[i][j]), f[i][j] = INF;
    int lst;
    for (j = 0, lst = -1; j <= m; ++j) {
      if (mp[i][j]) lst = j;
      if (~lst) chkmin(f[i][j], sqr(j - lst));
    }
    for (j = m, lst = -1; ~j; --j) {
      if (mp[i][j]) lst = j;
      if (~lst) chkmin(f[i][j], sqr(j - lst));
    }
  }
  solve();
  for (j = 0; j <= m; ++j)
    for (i = 0; i < n - i; ++i)
      swap(mp[i][j], mp[n - i][j]), swap(f[i][j], f[n - i][j]);
  solve();
  long long ans = 0;
  for (i = 0; i <= n; ++i)
    for (j = 0; j <= m; ++j) ans += f[i][j];
  printf("%lld\n", ans);
  return 0;
}
