#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
vector<long long> p;
int main() {
  long long x, y;
  scanf("%lld%lld", &x, &y);
  long long t = x;
  for (long long i = 2; i * i <= t; i++)
    if (t % i == 0) {
      p.push_back(i);
      while (t % i == 0) t /= i;
    }
  if (t > 1) p.push_back(t);
  long long ans = 0;
  while (y) {
    long long g = gcd(x, y);
    x /= g;
    y /= g;
    long long mx = 0;
    for (long long a : p)
      if (x % a == 0) {
        mx = max(mx, y / a * a);
      }
    ans += y - mx;
    y = mx;
  }
  printf("%lld\n", ans);
  return 0;
}
