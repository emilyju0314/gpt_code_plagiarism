#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const int MOD = 1000003;
template <typename tn>
inline tn read() {
  char ch;
  tn f = 1;
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  tn x = ch - '0';
  while (isdigit(ch = getchar())) x = x * 10 + ch - '0';
  return x * f;
}
template <typename tn>
inline void cmax(tn &a, tn b) {
  if (a < b) a = b;
}
template <typename tn>
inline void cmin(tn &a, tn b) {
  if (a > b) a = b;
}
const int K = 100 + 5;
int n;
struct Matrix {
  int n[K][K];
  Matrix(int x) {
    memset(n, 0, sizeof(n));
    if (x)
      for (int i = 0; i < (K); i++) n[i][i] = 1;
  }
} a(0), Fir(0);
inline Matrix operator*(const Matrix a, const Matrix b) {
  Matrix c(0);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      for (int k = (1); k <= (n); k++)
        c.n[i][k] = (c.n[i][k] + (long long)a.n[i][j] * b.n[j][k]) % MOD;
  return c;
}
inline Matrix power(Matrix a, long long k) {
  Matrix s(1);
  for (; k; k >>= 1, a = a * a)
    if (k & 1) s = s * a;
  return s;
}
void prematrix() {}
int main() {
  int k = read<int>();
  n = read<int>() + 1;
  int h = read<int>(), tmp = 1;
  for (int i = (1); i <= (n - 1); i++) a.n[i][i + 1] = 1;
  for (int i = (n); i >= (1); i--) {
    a.n[n][i] = tmp;
    tmp = tmp * h % MOD;
  }
  Matrix ans = power(a, k + 1);
  cout << ans.n[n][n] << endl;
}
