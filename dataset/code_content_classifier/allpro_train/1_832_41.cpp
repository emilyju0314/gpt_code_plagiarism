#include <bits/stdc++.h>
using namespace std;
long long pow3(long long a, long long b, long long m = 1000000007) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long a, b;
  scanf("%lld %lld", &a, &b);
  long long s = 0, e = 1e6 + 1;
  while (s < e) {
    long long m = (s + e) / 2;
    if (m * m * m < a * b)
      s = m + 1;
    else
      e = m;
  }
  if (s * s * s == a * b && a % s == 0 && b % s == 0)
    printf("Yes\n");
  else
    printf("No\n");
}
int main() {
  int q = 1;
  scanf("%d", &q);
  while (q--) {
    solve();
  }
  return 0;
}
