#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e3 + 4;
struct matrix {
  long long mat[2][2];
  void null() { memset(mat, 0, sizeof(mat)); }
  void identity() {
    null();
    mat[0][0] = mat[1][1] = 1;
  }
  matrix operator*(matrix &obj) {
    matrix res;
    res.null();
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          long long here = (mat[i][k] * obj.mat[k][j]) % mod;
          res.mat[i][j] = (res.mat[i][j] + here) % mod;
        }
      }
    }
    return res;
  }
};
matrix me(matrix a, long long b) {
  matrix res;
  res.identity();
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int main() {
  long long a, b, n, x;
  cin >> a >> b >> n >> x;
  matrix base;
  base.identity();
  base.mat[0][0] = a;
  base.mat[0][1] = 1;
  matrix res = me(base, n);
  long long ans = (res.mat[0][0] * x) % mod;
  long long val = (res.mat[0][1] * b) % mod;
  ans = (ans + val) % mod;
  cout << ans;
  return 0;
}
