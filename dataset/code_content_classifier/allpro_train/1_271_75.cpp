#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t e = pow(10, 9) + 7;
  int64_t n, l, m, i, prod = 1, com = 1;
  cin >> n;
  for (i = 1; i <= n; i++) {
    prod = prod * i;
    if (prod > e) prod %= e;
  }
  for (i = 1; i < n; i++) {
    com *= 2;
    if (com > e) com %= e;
  }
  if (prod >= com)
    cout << prod - com;
  else
    cout << prod + e - com;
  return 0;
}
