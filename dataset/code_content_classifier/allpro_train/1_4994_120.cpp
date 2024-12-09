#include <bits/stdc++.h>
using namespace std;
long long p, q, b;
int n, flag;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%lld%lld%lld", &p, &q, &b);
    flag = 1;
    q /= gcd(q, p);
    while (q != 1) {
      long long x = gcd(q, b);
      q /= x;
      b = x;
      if (q != 1 && b == 1) {
        printf("Infinite\n");
        flag = 0;
        break;
      }
    }
    if (flag) printf("Finite\n");
  }
  return 0;
}
