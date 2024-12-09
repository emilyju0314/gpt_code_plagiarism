#include <bits/stdc++.h>
int main() {
  long long n, ll, rr, q1, q2;
  long long w[100010];
  long long l[100010];
  long long r[100010];
  long long sum, min = 30000000000000;
  long long i, j;
  scanf("%I64d %I64d %I64d %I64d %I64d", &n, &ll, &rr, &q1, &q2);
  for (i = 1; i <= n; i++) scanf("%I64d", &w[i]);
  l[0] = 0;
  for (i = 1; i <= n; i++) {
    l[i] = l[i - 1] + w[i] * ll;
  }
  r[n + 1] = 0;
  for (i = n; i >= 1; i--) {
    r[i] = r[i + 1] + w[i] * rr;
  }
  for (i = 0; i <= n; i++) {
    j = n - i;
    sum = r[i + 1] + l[i];
    if (j - i >= 2) {
      sum += (j - i - 1) * q2;
    }
    if (i - j >= 2) {
      sum += (i - j - 1) * q1;
    }
    if (sum < min) {
      min = sum;
    }
  }
  printf("%I64d", min);
  return 0;
}
