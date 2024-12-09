#include <bits/stdc++.h>
using namespace std;
const long long N = 104, MOD = 1e9 + 7;
long long n, m;
struct Matrix {
  long long f[102][102];
  Matrix() { memset(f, 0, sizeof(f)); }
  void debug() {
    cerr << "MATRIX: \n";
    for (long long i = 1; i <= (long long)m; ++i) {
      for (long long j = 1; j <= (long long)m; ++j) cerr << f[i][j] << " ";
      cerr << '\n';
    }
    cerr << '\n';
  }
};
Matrix operator*(Matrix a, Matrix b) {
  Matrix c;
  for (long long i = 1; i <= (long long)m; ++i)
    for (long long j = 1; j <= (long long)m; ++j)
      for (long long k = 1; k <= (long long)m; ++k)
        c.f[i][j] = (c.f[i][j] + a.f[i][k] * b.f[k][j] % MOD) % MOD;
  return c;
}
Matrix operator^(Matrix a, long long b) {
  Matrix c;
  for (long long i = 1; i <= (long long)m; ++i) c.f[i][i] = 1;
  for (; b > 0; b /= 2, a = a * a)
    if (b & 1) c = c * a;
  return c;
}
Matrix bs, mul;
void sol() {
  if (n < m) {
    cout << 1 << '\n';
    exit(0);
  }
  if (n == m) {
    cout << 2 << '\n';
    exit(0);
  }
  for (long long i = 1; i <= (long long)m; ++i) bs.f[i][1] = (i == 1) ? 2 : 1;
  mul.f[1][1] = mul.f[1][m] = 1;
  for (long long i = 2; i <= (long long)m; ++i) mul.f[i][i - 1] = 1;
  mul = mul ^ (n - m);
  bs = mul * bs;
  cout << bs.f[1][1] << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  cin >> n >> m;
  sol();
  return 0;
}
