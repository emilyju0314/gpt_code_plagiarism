#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int a, b;
long long l, r;
int solve() {
  int per = a + b, overlap = max(0, a - b);
  int skip = l % per;
  long long rem = r - l + 1;
  int a1 = min(rem, (long long)max(0, per - skip - b));
  rem -= a1;
  int b1 = min(rem, (long long)min(b, per - skip));
  rem -= b1;
  int a2 = min((long long)a, rem);
  rem -= a2;
  int b2 = min((long long)b, rem);
  rem -= b2;
  int a3 = min((long long)a, rem);
  rem -= a3;
  int a1h = min(overlap, a1), a1l = a1 - a1h;
  int a2l = min(a2, a - overlap), a2h = a2 - a2l;
  int a3l = min(a3, a - overlap), a3h = a3 - a3l;
  if (b1 == 0) return a1;
  if (b2 == 0) {
    if (a1l == 0) return max(1, a1) + a2;
    if (a2h == 0) return min(a, a1 + a2);
    return min(a + overlap, a1h + a2);
  } else {
    return a + max(1, min(overlap, a1h + a3h));
  }
}
void run() {
  scanf("%d%d%lld%lld", &a, &b, &l, &r);
  --l, --r;
  printf("%d\n", solve());
}
int main() {
  run();
  return 0;
}
