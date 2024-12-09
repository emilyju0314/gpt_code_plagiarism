#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000;
int a[maxn], b[maxn];
int f[maxn], c;
int sum(int l, int r) { return (f[r] - f[l - 1] + c) % c; }
int main() {
  int n, m;
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= m; i++) f[i] = (f[i - 1] + b[i]) % c;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    if (i + m - 1 <= n)
      x = 1;
    else
      x = i + m - n;
    if (i - m >= 0)
      y = m;
    else
      y = i;
    a[i] = (a[i] + sum(x, y)) % c;
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
