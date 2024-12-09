#include <bits/stdc++.h>
using namespace std;
int d[100010];
int isLuck(int n) {
  while (n > 0) {
    int m = n % 10;
    if (m != 4 && m != 7) return 0;
    n /= 10;
  }
  return 1;
}
int n, tot, nl;
struct L {
  int n;
  int num;
};
L l[1030];
void mmm() {
  int i;
  nl = 0;
  tot = 0;
  for (i = 0; i < n; i++) {
    if (!isLuck(d[i])) {
      nl++;
      continue;
    }
    if (tot == 0 || d[i] != l[tot - 1].n) {
      l[tot].n = d[i];
      l[tot].num = 1;
      tot++;
    } else {
      l[tot - 1].num++;
    }
  }
}
int f[1030][1030];
int C[100010];
long long egcd(long long a, long long b, long long *x, long long *y) {
  long long d, t;
  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  }
  d = egcd(b, a % b, x, y);
  t = *y;
  *y = *x - (a / b) * (*y);
  *x = t;
  return d;
}
long long modni(long long a, long long m) {
  long long x, y;
  egcd(a, m, &x, &y);
  return (x + m) % m;
}
void init(int k) {
  int i;
  C[0] = 1;
  for (i = 1; i <= k; i++) {
    C[i] = (long long)C[i - 1] * (k - i + 1) % 1000000007 *
           modni(i, 1000000007) % 1000000007;
  }
}
int main() {
  int k;
  scanf("%d %d", &n, &k);
  int i, j;
  for (i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }
  sort(d, d + n);
  mmm();
  for (i = 0; i <= tot; i++) f[i][0] = 1;
  for (i = 1; i <= tot; i++) {
    for (j = 1; j <= i; j++) {
      f[i][j] = (long long)l[i - 1].num * f[i - 1][j - 1] % 1000000007;
      if (j < i) {
        f[i][j] = (f[i][j] + f[i - 1][j]) % 1000000007;
      }
    }
  }
  init(nl);
  int ans = 0;
  for (i = max(0, k - nl); i <= k && i <= tot; i++) {
    ans = (ans + (long long)f[tot][i] * C[k - i] % 1000000007) % 1000000007;
  }
  printf("%d\n", ans);
  return 0;
}
