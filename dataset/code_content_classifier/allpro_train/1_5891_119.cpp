#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
inline char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
long long T;
int n, m, i, j, k, l, p;
char c1[1100];
int x[1100];
const int L = 125;
const int mod = 12345;
struct mat {
  int s[L][L];
} G, E;
mat operator+(mat a, mat b) {
  mat c;
  int i, j;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= n; j++) c.s[i][j] = (a.s[i][j] + b.s[i][j]) % mod;
  return c;
}
mat operator*(mat a, mat b) {
  mat c;
  int i, j, k;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= n; j++) {
      c.s[i][j] = 0;
      for (k = 0; k <= n; k++)
        c.s[i][j] = (c.s[i][j] + 1LL * a.s[i][k] * b.s[k][j]) % mod;
    }
  return c;
}
mat operator^(mat a, long long x) {
  mat ans = E;
  for (; x; x >>= 1, a = a * a)
    if (x & 1) ans = ans * a;
  return ans;
}
mat ten(mat a) {
  mat t0 = a * a;
  mat t1 = t0 * t0;
  t1 = t1 * t1;
  return t0 * t1;
}
void print(mat a) {
  int i, j;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= n; j++) printf("%d%s", a.s[i][j], j == n ? "\n" : " ");
}
int a[1100], b[1100];
bool vv[30], can[30];
int st[1100];
void dfs(int i) {
  if (i > m) {
    memcpy(b, a, sizeof(a));
    int d = 0;
    for (int j = 1; j <= m; j++) d = d * x[j] + b[j];
    E.s[d][d] = 1;
    n = max(n, d);
    memset(can, 0, sizeof(can));
    for (int j = 1; j <= m; j++)
      if (b[j] == 0) can[c1[j] - 'A'] = 1;
    bool pd = 1;
    for (int k = 0; k <= 25; k++)
      if (vv[k] && (!can[k])) {
        pd = 0;
        break;
      }
    if (pd) st[++st[0]] = d;
    for (int k = 0; k <= 25; k++)
      if (vv[k]) {
        for (int j = 1; j <= m; j++) b[j] = a[j];
        for (int j = 1; j <= m; j++)
          if (c1[j] - 'A' == k) b[j] = (b[j] + 1) % x[j];
        int d2 = 0;
        for (int j = 1; j <= m; j++) d2 = d2 * x[j] + b[j];
        G.s[d][d2]++;
      }
    return;
  }
  for (int j = 0; j < x[i]; j++) {
    a[i] = j;
    dfs(i + 1);
  }
}
int main() {
  read(T);
  read(m);
  for (i = 1; i <= m; i++) c1[i] = getc(), vv[c1[i] - 'A'] = 1, read(x[i]);
  dfs(1);
  G = G ^ T;
  int ans = 0;
  for (i = 1; i <= st[0]; i++) ans = (ans + G.s[0][st[i]]) % mod;
  printf("%d\n", ans);
  scanf("\n");
  return 0;
}
