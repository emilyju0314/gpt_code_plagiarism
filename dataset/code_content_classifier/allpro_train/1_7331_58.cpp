#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
const int N = 102000;
int n, k, l[N], r[N], f[102][N];
int q[N], cnt[N], F, R;
inline void push(int p, int v) {
  while (F <= R && q[R] > v) R--;
  if (F <= R && q[R] == v) {
    cnt[R]++;
  } else {
    q[++R] = v;
    cnt[R] = 1;
  }
}
inline void del(int v) {
  if (F <= R && q[F] == v) {
    cnt[F]--;
    if (!cnt[F]) F++;
  }
}
int main() {
  read(n);
  read(k);
  for (int i = 1; i <= k; i++) read(l[i]), read(r[i]);
  l[k + 1] = n * 2;
  r[k + 1] = n * 2;
  k++;
  memset(f, 0x3f3f3f3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= k; i++) {
    int dis = r[i] - r[i - 1], d = l[i] - r[i - 1];
    for (int j = 0; j <= n; j++)
      if (j - dis >= 0) f[i][j] = min(f[i][j], f[i - 1][j - dis]);
    F = 1;
    R = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int j = 0; j <= n; j++) {
      if (j - 1 - dis >= 0) del(f[i - 1][j - 1 - dis]);
      if (j - d >= 0) push(j - d, f[i - 1][j - d]);
      if (F <= R) f[i][j] = min(f[i][j], q[F] + 2);
    }
    F = 1;
    R = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int j = r[i - 1] + r[i] - l[i]; j >= r[i - 1]; j--)
      if (j >= 0 && j <= n) push(j, f[i - 1][j]);
    if (F <= R) f[i][0] = min(f[i][0], q[F] + 1);
    for (int j = 1; j <= n; j++) {
      if (r[i - 1] + r[i] - l[i] - (j - 1) >= 0)
        del(f[i - 1][r[i - 1] + r[i] - l[i] - (j - 1)]);
      if (r[i - 1] - j >= 0) push(r[i - 1] - j, f[i - 1][r[i - 1] - j]);
      if (F <= R) f[i][j] = min(f[i][j], q[F] + 1);
    }
  }
  if (f[k][n] < 0x3f3f3f3f)
    printf("Full\n%d", f[k][n]);
  else
    puts("Hungry");
  return 0;
}
