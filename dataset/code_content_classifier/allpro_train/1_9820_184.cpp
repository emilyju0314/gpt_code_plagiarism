#include <bits/stdc++.h>
using namespace std;
long long id[2][2] = {{1, 0}, {0, 1}}, fib[2][2] = {{1, 1}, {1, 0}};
long long m, l, r, k, x, ans;
struct matrix {
  long long a[2][2];
  matrix() {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) a[i][j] = 0;
  }
  matrix(long long x[2][2]) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) a[i][j] = x[i][j];
  }
  matrix operator*(matrix x) {
    matrix res;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          res.a[i][k] = (res.a[i][k] + a[i][j] * x.a[j][k]) % m;
    return res;
  }
};
matrix step(matrix x, long long p) {
  if (!p) return matrix(id);
  matrix y = step(x, p >> 1);
  y = y * y;
  if (p & 1) y = y * x;
  return y;
}
void opt(long long x) {
  if (x && r / x - l / x >= k) ans = max(ans, x);
}
int main() {
  scanf("%lld %lld %lld %lld", &m, &l, &r, &k);
  l--;
  for (long long i = 1; i * i <= r; i++) opt(i), opt(r / i), opt(l / i);
  printf("%lld", step(fib, ans - 1).a[0][0] % m);
  return 0;
}
