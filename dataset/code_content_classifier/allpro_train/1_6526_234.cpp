#include <bits/stdc++.h>
using namespace std;
int n;
long long x, y;
long long a[100001];
long long s[100001];
long long gcd(long long p, long long q) {
  if (p == 0) return q;
  return gcd(q % p, p);
}
int main() {
  scanf("%d", &n);
  y = n;
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  x = s[n];
  for (int i = 1; i < n; i++)
    x += 2 * ((s[n] - s[i]) - (a[i] * ((long long)(n - i))));
  long long d = gcd(x, y);
  printf("%I64d %I64d\n", x / d, y / d);
  return 0;
}
