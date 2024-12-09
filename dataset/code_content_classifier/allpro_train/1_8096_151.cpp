#include <bits/stdc++.h>
using namespace std;
template <typename tn>
void read(tn &a) {
  tn x = 0, f = 1;
  char c = ' ';
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  a = x * f;
}
const int N = 3510, mod = 1e9 + 7;
char c[N];
int a[N], n, m, P;
int f[N][N][2][2];
bool vis[N][N][2][2];
namespace Number {
char res[N];
int MOD(char *c, int P) {
  int now = 0;
  for (int i = strlen(c) - 1; ~i; i--) now = (now * 10ll + c[i] - '0') % P;
  return now;
}
void DIV(char *c, int P) {
  memset(res, 0, sizeof(res));
  long long now = 0;
  for (int i = strlen(c) - 1; ~i; i--) {
    now = now * 10 + c[i] - '0';
    res[i] = now / P + '0';
    now %= P;
  }
  memcpy(c, res, sizeof(res));
  int p = strlen(c);
  while (p && c[p - 1] == '0') c[p - 1] = 0, p--;
}
void turn(char *c, int *a, int &n, int P) {
  n = 0;
  while (strlen(c)) {
    a[n++] = MOD(c, P);
    DIV(c, P);
  }
}
}  // namespace Number
long long solve(int x, int k, int p1, int p2) {
  if (k < 0) return 0;
  if (x < 0) return k == 0 && p1 == 0;
  if (vis[x][k][p1][p2]) return f[x][k][p1][p2];
  vis[x][k][p1][p2] = 1;
  if (p1 == 0 && p2 == 0) {
    return f[x][k][p1][p2] =
               (solve(x - 1, k, 0, 0) * (1ll * P * (P + 1) / 2 % mod) +
                solve(x - 1, k, 1, 0) * (1ll * P * (P - 1) / 2 % mod)) %
               mod;
  }
  if (p1 == 1 && p2 == 0) {
    return f[x][k][p1][p2] =
               (solve(x - 1, k - 1, 0, 0) * (1ll * P * (P - 1) / 2 % mod) +
                solve(x - 1, k - 1, 1, 0) * (1ll * P * (P + 1) / 2 % mod)) %
               mod;
  }
  if (p1 == 0 && p2 == 1) {
    long long res =
        (solve(x - 1, k, 0, 0) * (1ll * a[x] * (a[x] + 1) / 2 % mod) +
         solve(x - 1, k, 0, 1) * (a[x] + 1)) %
        mod;
    res = (res + solve(x - 1, k, 1, 0) * (1ll * a[x] * (a[x] - 1) / 2 % mod) +
           solve(x - 1, k, 1, 1) * (a[x])) %
          mod;
    return f[x][k][p1][p2] = res;
  }
  if (p1 == 1 && p2 == 1) {
    long long res = (solve(x - 1, k - 1, 0, 0) *
                         (1ll * a[x] * (P - 1 + P - a[x]) / 2 % mod) +
                     solve(x - 1, k - 1, 0, 1) * (P - a[x] - 1)) %
                    mod;
    res = (res +
           solve(x - 1, k - 1, 1, 0) *
               (1ll * a[x] * (P + P - a[x] + 1) / 2 % mod) +
           solve(x - 1, k - 1, 1, 1) * (P - a[x])) %
          mod;
    return f[x][k][p1][p2] = res;
  }
}
int main() {
  read(P);
  read(m);
  cin >> c;
  reverse(c, c + strlen(c));
  Number::turn(c, a, n, P);
  if (m >= n) {
    puts("0");
    return 0;
  }
  long long ans = 0;
  for (int i = m; i < n; i++) ans = (ans + solve(n - 1, i, 0, 1)) % mod;
  cout << (ans + mod) % mod << '\n';
  return 0;
}
