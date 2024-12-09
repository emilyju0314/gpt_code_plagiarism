#include <bits/stdc++.h>
int n, s, e, minP;
long long a[5005];
long long b[5005];
long long c[5005];
long long d[5005];
long long x[5005];
long long sum, mn, co;
int next[5005];
long long getC(int i, int j) {
  if (j < i) {
    return labs(x[i] - x[j]) + c[i] + b[j];
  } else {
    return labs(x[i] - x[j]) + d[i] + a[j];
  }
}
int main() {
  scanf("%d%d%d", &n, &s, &e);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &c[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &d[i]);
  }
  next[s] = e;
  sum = getC(s, e);
  for (int i = n; i >= 1; i--) {
    if (i != s && i != e) {
      mn = 10000000000;
      for (int xi = s; xi != e; xi = next[xi]) {
        co = getC(xi, i) - getC(xi, next[xi]) + getC(i, next[xi]);
        if (co < mn) {
          mn = co;
          minP = xi;
        }
      }
      sum += mn;
      next[i] = next[minP];
      next[minP] = i;
    }
  }
  printf("%lld\n", sum);
}
