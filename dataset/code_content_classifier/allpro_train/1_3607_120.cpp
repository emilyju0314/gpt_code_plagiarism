#include <bits/stdc++.h>
long long S, d[55 * 55];
int n, cnt, a[55][55], b[55][55], e[55][55], c[55], res[55];
typedef int arr[55][55], arr1[55];
arr tmp[55];
void mul1(arr1 &res, arr &a) {
  memset(c, 0, sizeof(c));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) c[i] = (a[i][j] * res[j] + c[i]) & 1;
  memcpy(res, c, sizeof(res));
}
void mul(arr &a) {
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) b[i][j] = (a[i][k] * a[k][j] + b[i][j]) & 1;
  memcpy(a, b, sizeof(a));
}
bool work(long long y) {
  for (int i = 0; i < n; i++) res[i] = 1;
  int tmp1 = 0;
  while (y) {
    if (y & 1) mul1(res, tmp[tmp1]);
    y /= 2;
    ++tmp1;
  }
  for (int i = 0; i < n; i++)
    if (!res[i]) return 0;
  return 1;
}
bool check() {
  memcpy(tmp[0], e, sizeof(tmp[0]));
  for (int i = 1; i < n; ++i)
    memcpy(tmp[i], tmp[i - 1], sizeof(tmp[0])), mul(tmp[i]);
  long long x = S;
  if (!work(x)) return 0;
  for (int i = 1; i <= cnt; i++)
    if (work(d[i])) return 0;
  return 1;
}
int main() {
  scanf("%d", &n), S = (1LL << n) - 1;
  long long x = S, sq = (long long)sqrt(x * 1.);
  srand(time(0));
  for (int i = 2; i <= sq; i++)
    if (x % i == 0) {
      d[++cnt] = S / i;
      while (x % i == 0) x /= i;
      sq = (long long)sqrt(x * 1.);
    }
  if (x) d[++cnt] = S / x;
  for (int i = 0; i < n - 1; i++) e[i][i + 1] = 1;
  int times = 0;
  for (; ++times;) {
    for (int i = 0; i < n; i++) e[n - 1][i] = rand() % 2;
    if (check()) break;
  }
  for (int i = n - 1; i >= 0; i--) printf("%d%s", e[n - 1][i], i ? " " : "\n");
  for (int i = 1; i <= n; i++) printf("%d%s", 1, i < n ? " " : "\n");
  return 0;
}
