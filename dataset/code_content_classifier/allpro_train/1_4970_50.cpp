#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  T k = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') k = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= k;
}
const int INF = 1e9;
const int N = 2e5;
char s[2][N];
struct seg {
  int dist[2][2];
  const int *operator[](const int &x) const { return dist[x]; }
  int *operator[](const int &x) { return dist[x]; }
} tr[N << 2];
inline seg operator+(const seg &a, const seg &b) {
  seg ret;
  int ans;
  ans = INF;
  ans = min(ans, a[0][0] + b[0][0] + 1);
  ans = min(ans, a[0][1] + b[1][0] + 1);
  ret[0][0] = ans;
  ans = INF;
  ans = min(ans, a[0][0] + b[0][1] + 1);
  ans = min(ans, a[0][1] + b[1][1] + 1);
  ret[0][1] = ans;
  ans = INF;
  ans = min(ans, a[1][0] + b[0][1] + 1);
  ans = min(ans, a[1][1] + b[1][1] + 1);
  ret[1][1] = ans;
  ans = INF;
  ans = min(ans, a[1][0] + b[0][0] + 1);
  ans = min(ans, a[1][1] + b[1][0] + 1);
  ret[1][0] = ans;
  return ret;
}
inline void build(int rt, int l, int r) {
  if (l == r) {
    tr[rt][0][0] = tr[rt][0][1] = tr[rt][1][1] = tr[rt][1][0] = INF;
    if (s[0][l] == '.') {
      tr[rt][0][0] = 0;
      if (s[1][l] == '.') tr[rt][0][1] = 1;
    }
    if (s[1][l] == '.') {
      tr[rt][1][1] = 0;
      if (s[0][l] == '.') tr[rt][1][0] = 1;
    }
    return;
  }
  int mid = (l + r) >> 1;
  build((rt << 1), l, mid);
  build((rt << 1 | 1), mid + 1, r);
  tr[rt] = tr[(rt << 1)] + tr[(rt << 1 | 1)];
}
inline seg query(int rt, int l, int r, int x, int y) {
  if (x <= l && r <= y) return tr[rt];
  int mid = (l + r) >> 1;
  if (y <= mid)
    return query((rt << 1), l, mid, x, y);
  else if (x > mid)
    return query((rt << 1 | 1), mid + 1, r, x, y);
  else
    return query((rt << 1), l, mid, x, y) +
           query((rt << 1 | 1), mid + 1, r, x, y);
}
int n, m;
inline int Query(int x, int y) {
  int l = (x - 1) % n + 1;
  int r = (y - 1) % n + 1;
  if (l > r) swap(l, r), swap(x, y);
  return query(1, 1, n, l, r)[x > n][y > n];
}
int main() {
  read(n), read(m);
  scanf("%s", s[0] + 1);
  scanf("%s", s[1] + 1);
  build(1, 1, n);
  for (int a, b; m; --m) {
    read(a), read(b);
    int ans = Query(a, b);
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
  }
}
