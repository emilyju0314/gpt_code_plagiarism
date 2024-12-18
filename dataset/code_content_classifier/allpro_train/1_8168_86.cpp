#include <bits/stdc++.h>
using namespace std;
int prime[100], flag[100], num, u[100];
long long cal(long long x, int n) {
  long long temp, ans = 0, sum;
  for (int i = 1; i < n; i++)
    if (n % i == 0) {
      temp = x >> (n - i);
      sum = 0;
      for (int j = 0; j < n / i; j++) sum += 1LL << (j * i);
      sum *= temp;
      if (sum > x) temp--;
      temp = temp - (1LL << (i - 1)) + 1;
      ans -= temp * u[n / i];
    }
  return ans;
}
long long solve(long long n) {
  long long A = 0;
  for (int i = 1; (1LL << (i - 1)) <= n; i++)
    A += cal(min((1LL << i) - 1, n), i);
  return A;
}
int main() {
  u[1] = 1;
  for (int i = 2; i < 100; i++) {
    if (!flag[i]) prime[++num] = i, u[i] = -1;
    for (int j = 1; j <= num && i * prime[j] < 100; j++) {
      flag[i * prime[j]] = 1;
      if (i % prime[j] == 0)
        break;
      else
        u[i * prime[j]] = -u[i];
    }
  }
  long long l, r;
  while (~scanf("%I64d %I64d", &l, &r))
    printf("%I64d\n", solve(r) - solve(l - 1));
}
