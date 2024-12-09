#include <bits/stdc++.h>
using namespace std;
int ni() {
  int a;
  scanf("%d", &a);
  return a;
}
double nf() {
  double a;
  scanf("%lf", &a);
  return a;
}
char sbuf[100005];
string ns() {
  scanf("%s", sbuf);
  return sbuf;
}
long long nll() {
  long long a;
  scanf("%lld", &a);
  return a;
}
template <class T>
void out(T a, T b) {
  bool first = true;
  for (T i = a; i != b; ++i) {
    if (!first) printf(" ");
    first = false;
    cout << *i;
  }
  printf("\n");
}
template <class T>
void outl(T a, T b) {
  for (T i = a; i != b; ++i) {
    cout << *i << "\n";
  }
}
int n, m;
const long long mod = 1000000007;
bool h[300][300];
bool v[300][300];
string f[1500];
long long memo[300][300][2];
long long doIt(int x, int y, int a) {
  if (x == m) return 1LL;
  if (x > m) return 0LL;
  if (y == n) {
    if (a) return doIt(x + 2, 0, 0);
    return 0;
  }
  long long& ret = memo[x][y][a];
  if (ret != -1) return ret;
  ret = 0;
  if (y == 0 && n % 2 == 0) {
    bool ok = true;
    int i;
    for (i = (0); i < (((n))); ++i)
      if (!v[i][x]) ok = false;
    if (ok) (ret += doIt(x + 1, 0, 0)) %= mod;
  }
  if (x == m - 1) return ret;
  if (h[y][x] && h[y][x + 1]) (ret += doIt(x, y + 1, 1)) %= mod;
  if (y < n - 1 && v[y][x] && v[y][x + 1] && v[y + 1][x] && v[y + 1][x + 1])
    (ret += doIt(x, y + 2, a)) %= mod;
  return ret % mod;
}
int main() {
  int i, j, k;
  n = ni();
  m = ni();
  for (i = (0); i < (((4 * n + 1))); ++i) f[i] = ns();
  for (i = (0); i < (((n))); ++i)
    for (j = (0); j < (((m))); ++j) {
      h[i][j] = v[i][j] = 1;
      int ii = i * 4, jj = j * 4;
      if (f[ii + 1][jj + 2] == 'O' ||
          f[ii + 1][jj + 1] == 'O' && f[ii + 3][jj + 1] != 'O')
        v[i][j] = 0;
      if (f[ii + 2][jj + 1] == 'O' ||
          f[ii + 1][jj + 1] != 'O' && f[ii + 3][jj + 1] == 'O')
        h[i][j] = 0;
    }
  memset(memo, -1, sizeof(memo));
  printf("%lld\n", doIt(0, 0, 0) % mod);
  return 0;
}
