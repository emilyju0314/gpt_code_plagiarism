#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool ok(long long x) { return k * (k - 1) / 2 - x * (x - 1) / 2 + 1 >= n; }
long long bs() {
  long long L = 1, R = k;
  while (L < R) {
    long long M = (L + R) / 2;
    if (ok(M))
      L = M + 1;
    else
      R = M;
  }
  return (L - 1);
}
int main() {
  cin >> n >> k;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  long long res = bs();
  if (ok(res))
    cout << k - res;
  else
    cout << -1;
  return 0;
}
