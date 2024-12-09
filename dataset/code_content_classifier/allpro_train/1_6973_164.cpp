#include <bits/stdc++.h>
int n;
long long a[100100];
int b[100100];
long long c[100100];
long long ans[100100];
int l[100100];
int r[100100];
int x;
long long mx = 0;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    c[i] = -1;
    l[i] = r[i] = i;
  }
  c[0] = c[n + 1] = -1;
  for (int i = n; i >= 1; i--) {
    ans[i] = mx;
    int x = b[i];
    c[x] = a[x];
    mx = std::max(mx, c[x]);
    if (c[x - 1] >= 0) {
      long long tmp = c[x];
      c[x] += c[x - 1];
      c[l[x - 1]] += tmp;
      l[x] = l[x - 1];
      r[l[x - 1]] = x;
      mx = std::max(mx, c[x]);
    }
    if (c[x + 1] >= 0) {
      long long tmp = c[x];
      c[l[x]] += c[x + 1];
      c[r[x + 1]] += tmp;
      l[r[x + 1]] = l[x];
      r[l[x]] = r[x + 1];
      mx = std::max(mx, c[l[x]]);
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%I64d\n", ans[i]);
  }
  return 0;
}
