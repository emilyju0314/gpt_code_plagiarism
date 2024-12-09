#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5143;
const long long Linf = 1e18 + 5413;
const double eps = 1e-10;
const double pi = acos(-1);
template <class T>
inline void umax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void umin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <class T>
inline T lcm(T a, T b) {
  return a / __gcd(a, b) * b;
}
inline int read() {
  int res = 0LL;
  int neg;
  while (1) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9' || ch == '-') {
      if (ch == '-')
        neg = -1;
      else
        neg = 1, res = ch - '0';
      break;
    }
  }
  while (1) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9')
      res *= 10, res += ch - '0';
    else
      break;
  }
  return res * neg;
}
const int N = 25;
const int K = 25;
long long dp[N][K][K];
int a[N], b[N];
long long res[K][K];
long long temp[K][K];
long long bin[K][K];
void mul(long long a[K][K], long long b[K][K]) {
  for (int(i) = (0); (i) < (K); (i)++)
    for (int(j) = (0); (j) < (K); (j)++) temp[i][j] = Linf;
  for (int(i) = (0); (i) < (K); (i)++)
    for (int(j) = (0); (j) < (K); (j)++)
      for (int(k) = (0); (k) < (K); (k)++) umin(temp[i][j], a[i][k] + b[k][j]);
  for (int(i) = (0); (i) < (K); (i)++)
    for (int(j) = (0); (j) < (K); (j)++) a[i][j] = temp[i][j];
}
int main() {
  int n = read();
  int m = read();
  for (int(i) = (0); (i) < (n); (i)++) a[i] = read();
  for (int(i) = (0); (i) < (n); (i)++) b[i] = read();
  for (int(i) = (0); (i) < (N); (i)++)
    for (int(j) = (0); (j) < (K); (j)++)
      for (int(k) = (0); (k) < (K); (k)++) dp[i][j][k] = Linf;
  for (int(i) = (0); (i) < (K); (i)++) dp[0][i][i] = 0;
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (K); (j)++)
      for (int(k) = (0); (k) < (K); (k)++) {
        if (dp[i][j][k] < inf) {
          if (k + 1 < K) umin(dp[i + 1][j][k + 1], dp[i][j][k] + a[i]);
          if (k - 1 >= 0) umin(dp[i + 1][j][k - 1], dp[i][j][k] + b[i]);
        }
      }
  for (int(i) = (0); (i) < (K); (i)++)
    for (int(j) = (0); (j) < (K); (j)++) bin[i][j] = dp[n][i][j];
  for (int(i) = (0); (i) < (K); (i)++)
    for (int(j) = (0); (j) < (K); (j)++) {
      if (i == j) {
        res[i][j] = 0;
      } else {
        res[i][j] = Linf;
      }
    }
  while (m > 0) {
    if (m & 1) {
      mul(res, bin);
    }
    m >>= 1;
    mul(bin, bin);
  }
  cout << res[0][0] << endl;
  return 0;
}
