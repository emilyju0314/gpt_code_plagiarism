#include <bits/stdc++.h>
using namespace std;
long long f(long long n) {
  long long p = 1;
  while (n >= p) p = p * 10;
  return p - n - 1;
}
int main() {
  long long l, r, cur = 5, res;
  cin >> l >> r;
  res = max(l * f(l), r * f(r));
  while (cur < l) cur = cur * 10;
  while (cur <= r) {
    res = max(res, cur * f(cur));
    cur = cur * 10;
  }
  cout << res << endl;
  return 0;
}
