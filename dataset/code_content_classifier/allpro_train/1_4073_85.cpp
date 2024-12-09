#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0, sum1 = 0;
  if (n == 1 || n == 2) {
    printf("No");
    return 0;
  }
  sum = 1LL * n * (n + 1) / 2;
  for (int i = 2; i <= n; i++) {
    if (sum % i == 0) {
      printf("Yes\n");
      printf("1 ");
      printf("%d\n", i);
      printf("%d ", n - 1);
      for (int k = 1; k <= n; k++)
        if (k != i) printf("%d ", k);
      return 0;
    }
  }
  return 0;
}
