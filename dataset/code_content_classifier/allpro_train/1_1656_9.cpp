#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
using ll = long long;
const int N = 2e4 + 10, inf = 2e9;
int a[N], f[N], f0[N], t[N], top;
struct line {
  int k, b;
  inline line(int _k = 0, int _b = 0) : k(_k), b(_b) {}
  inline int operator()(int x) { return k * x + b; }
};
line st[N];
inline bool cmp(line a, line b, line c) {
  return (ll)(a.k - b.k) * (a.b - c.b) >= (ll)(a.k - c.k) * (a.b - b.b);
}
inline void insert(line x) {
  while (top && x.k >= st[top].k) {
    x.b = min(x.b, st[top].b);
    top--;
  }
  while (top > 1 && cmp(st[top - 1], st[top], x)) top--;
  st[++top] = x;
}
inline int get(int x) {
  if (top == 0) return inf;
  int l = 1, r = top, mid;
  while (l < r) {
    mid = l + r >> 1;
    if (st[mid](x) <= st[mid + 1](x))
      r = mid;
    else
      l = mid + 1;
  }
  return st[l](x);
}
inline void solve(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  solve(l, mid);
  solve(mid + 1, r);
  t[mid] = a[mid], t[mid + 1] = a[mid + 1];
  for (int i = mid - 1; i >= l; i--) t[i] = max(t[i + 1], a[i]);
  for (int i = mid + 2; i <= r; i++) t[i] = max(t[i - 1], a[i]);
  top = 0;
  for (int i = r, j = l; i > mid; i--) {
    for (; j <= mid && t[j + 1] >= t[i]; j++)
      if (f0[j] < inf) insert(line(t[j + 1], f0[j] - j * t[j + 1]));
    f[i] = min(f[i], get(i));
  }
  top = 0;
  for (int i = mid + 1, j = mid; i <= r; i++) {
    for (; j >= l && t[j + 1] <= t[i]; j--)
      if (f0[j] < inf) insert(line(j, f0[j]));
    f[i] = min(f[i], get(-t[i]) + i * t[i]);
  }
}
int main() {
  int n = read(), k = read();
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    t[i] = max(t[i - 1], a[i]);
    f[i] = i * t[i];
  }
  for (int i = 2; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      f0[j] = f[j];
      f[j] = inf;
    }
    solve(1, n);
  }
  printf("%d\n", f[n]);
  return 0;
}
