#include <bits/stdc++.h>
using namespace std;
long long mypow(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % 1000003;
    x = x * x % 1000003;
    n /= 2;
  }
  return res;
}
int main() {
  long long n, m;
  scanf("%I64d%I64d", &n, &m);
  long long x = 1, flag = 1;
  for (int i = 1; i <= min((long long)60, n); i++) {
    x *= 2;
  }
  if (x < m) flag = 0;
  if (!flag) {
    printf("1 1");
    return 0;
  }
  long long tmp, A, B, i;
  A = B = 1;
  for (tmp = 0, i = 2; i <= m - 1; i *= 2) tmp += (m - 1) / i;
  B = mypow(2, n % (1000003 - 1) *
                   ((m % (1000003 - 1) - 1 + (1000003 - 1)) % (1000003 - 1)) %
                   (1000003 - 1));
  long long GCD =
      mypow(2, tmp % (1000003 - 1) * (1000003 - 2) % (1000003 - 1)) % 1000003;
  B = B * GCD % 1000003;
  if (m - 1 >= 1000003) {
    printf("%I64d %I64d", B, B);
    return 0;
  } else {
    for (int i = 1; i <= m - 1; i++)
      A = A * (mypow(2, n % (1000003 - 1)) - i + 1000003 % 1000003) % 1000003;
    A = A * mypow(2, tmp % (1000003 - 1) * (1000003 - 2) % (1000003 - 1)) %
        1000003;
    printf("%I64d %I64d", (B - A + 1000003) % 1000003, B);
  }
  return 0;
}
