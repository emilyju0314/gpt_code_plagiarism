#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
void getint(int &first) {
  char c;
  while (c = getchar(), c > '9' || c < '0')
    ;
  for (first = 0; c >= '0' && c <= '9'; c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
}
void print(int first) {
  if (first < 10) {
    putchar(first + '0');
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
int flag[1010100], prime[1010100], np;
int ans[1010100][2];
int al[1010100], al2[1010100], deg[111], fac[111];
int qb, q[1010100], g[1010100][21], f[3][21];
void prepare() {
  for (int i = 2; i < 1010100; i++) {
    if (!flag[i]) flag[i] = i, prime[np++] = i;
    for (int j = 0; j < np && prime[j] * i < 1010100; j++) {
      flag[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
  ans[1][0] = ans[1][1] = 1;
  al[1] = al2[1] = 1;
  for (int n = 2; n < 1010100; n++) {
    int v = flag[n], u = n, cnt = 0;
    while (u % v == 0) u /= v, cnt++;
    ans[n][0] = (long long)2 * ans[u][0] % 1000000007;
    al[n] = al[u] * (1 + cnt);
    al2[n] = (long long)al2[u] * (1 + cnt * 2LL) % 1000000007;
    ans[n][1] = al2[n];
  }
  int ok = 0;
  for (int i = 0; i < 1010100; i++) {
    for (int j = 0; j < 21; j++) f[ok][j] = 0;
    for (int j = 1; j < 21; j++) {
      if (i == 0) {
        f[ok][j] = (f[ok][j - 1] + (long long)j * j) % 1000000007;
        g[i][j] = (long long)j * j % 1000000007;
      } else {
        f[ok][j] = (f[ok][j - 1] + f[ok ^ 1][j]) % 1000000007;
        g[i][j] = f[ok ^ 1][j];
      }
    }
    ok ^= 1;
  }
}
int main() {
  prepare();
  int Q, r, n;
  for (scanf("%d", &Q); Q--;) {
    getint(r);
    getint(n);
    if (r < 2)
      printf("%d\n", ans[n][r]);
    else {
      int res = 1;
      for (int u = n; u > 1;) {
        int v = flag[u], cnt = 0;
        while (u % v == 0) u /= v, cnt++;
        res = (long long)res * g[r - 2][cnt + 1] % 1000000007;
      }
      printf("%d\n", res);
    }
  }
  return 0;
}
