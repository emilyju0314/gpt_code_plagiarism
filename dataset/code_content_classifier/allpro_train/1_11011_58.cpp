#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int out = 0, fh = 1;
  char jp = getchar();
  while ((jp > '9' || jp < '0') && jp != '-') jp = getchar();
  if (jp == '-') fh = -1, jp = getchar();
  while (jp >= '0' && jp <= '9') out = out * 10 + jp - '0', jp = getchar();
  return out * fh;
}
const int P = 998244353;
int add(int a, int b) { return (a + b >= P) ? (a + b - P) : (a + b); }
void inc(int &a, int b) { a = add(a, b); }
int mul(int a, int b) { return 1LL * a * b % P; }
int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
const int N = 2019;
char buf[N];
int n, f[N][N], s[N];
int sum(int L, int R) {
  if (L > R) return 0;
  return add(s[R], P - s[L - 1]);
}
int main() {
  scanf("%s", buf + 1);
  n = strlen(buf + 1);
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + (buf[i] == '?');
  for (int len = 2; len <= n; ++len)
    for (int i = 1; i + len - 1 <= n; ++i) {
      int j = i + len - 1;
      if (buf[i] != '(') inc(f[i][j], f[i + 1][j]);
      if (buf[j] != ')') inc(f[i][j], f[i][j - 1]);
      if (buf[i] != '(' && buf[j] != ')') inc(f[i][j], P - f[i + 1][j - 1]);
      if (buf[i] != ')' && buf[j] != '(')
        inc(f[i][j], add(f[i + 1][j - 1], fpow(2, sum(i + 1, j - 1))));
    }
  cout << f[1][n] << '\n';
  return 0;
}
