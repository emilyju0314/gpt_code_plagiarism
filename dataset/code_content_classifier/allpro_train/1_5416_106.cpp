#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 107;
struct matrix {
  int n, m;
  long long a[MAXN][MAXN];
  matrix() {
    for (int i = 0; i < MAXN; i++) {
      for (int j = 0; j < MAXN; j++) {
        a[i][j] = 0;
      }
    }
  }
};
matrix operator*(matrix a, matrix b) {
  assert(a.m == b.n);
  matrix ans;
  ans.n = a.n;
  ans.m = a.m;
  for (int i = 1; i <= ans.n; i++) {
    for (int j = 1; j <= ans.m; j++) {
      for (int k = 1; k <= a.m; k++) {
        ans.a[i][j] += ((a.a[i][k] % MOD) * (b.a[k][j]) % MOD) % MOD;
        ans.a[i][j] %= MOD;
      }
    }
  }
  return ans;
}
matrix matPow(matrix x, long long k) {
  if (k == 1) return x;
  if (k % 2 == 0) {
    matrix tmp = matPow(x, k / 2);
    return tmp * tmp;
  } else {
    matrix tmp = matPow(x, k - 1);
    return x * tmp;
  }
}
bool check(long long x, long long y) {
  x ^= y;
  int res = 0;
  while (x > 0) {
    if (x % 2 == 1) {
      res++;
    }
    x /= 2;
  }
  return (res % 3 == 0);
}
int main() {
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  vector<long long> aa;
  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%lld", &x);
    aa.push_back(x);
  }
  matrix a;
  a.n = n;
  a.m = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (check(aa[i], aa[j])) {
        a.a[i + 1][j + 1] = 1;
        a.a[j + 1][i + 1] = 1;
      }
    }
  }
  if (k == 1) {
    printf("%d\n", n);
    return 0;
  }
  a = matPow(a, k - 1);
  matrix b;
  b.n = 1;
  b.m = n;
  for (int i = 1; i <= n; i++) {
    b.a[1][i] = 1;
  }
  b = b * a;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    res = (res + b.a[1][i]) % MOD;
  }
  printf("%lld\n", res);
}
