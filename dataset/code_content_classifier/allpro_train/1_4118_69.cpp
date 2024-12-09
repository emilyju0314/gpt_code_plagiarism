#include <bits/stdc++.h>
using namespace std;
int n;
long long k, x, p;
long long gcd(long long a, long long b) {
  long long c;
  while (b) {
    c = a;
    a = b;
    b = c % b;
  }
  return a;
}
int main() {
  scanf("%d", &n);
  cin >> k;
  p = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &x);
    p = p * x / gcd(p, x) % k;
    if (p == 0) {
      printf("Yes");
      return 0;
    }
  }
  printf("No");
  return 0;
}
