#include <bits/stdc++.h>
using namespace std;
long long maxn = 0, minn = 1e18;
long long tot;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void js(long long x) {
  if (x <= 0 || x > tot) return;
  long long gg = gcd(x, tot);
  long long tmp = tot / gg;
  maxn = max(maxn, tmp);
  minn = min(minn, tmp);
}
int main() {
  long long n, k;
  cin >> n >> k;
  long long a, b;
  cin >> a >> b;
  tot = n * k;
  for (int i = 0; i <= n + 1; ++i) {
    js(i * k + (a + b));
    js(i * k - (a + b));
    js(i * k + (a - b));
    js(i * k + (b - a));
  }
  printf("%lld %lld\n", minn, maxn);
  return 0;
}
