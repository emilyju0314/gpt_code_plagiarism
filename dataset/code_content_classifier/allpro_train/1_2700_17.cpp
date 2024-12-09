#include <bits/stdc++.h>
using namespace std;
void Fast_IO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
long long easy(long long n) {
  long long start = 1, tillnow = 1;
  while (tillnow + start <= n) tillnow += start, start *= 4;
  return start + n - tillnow;
}
long long hard(long long n) {
  if (n == 1) return 2;
  long long base = 4, aim = 8;
  long long adder = 4, pos = 2;
  while (pos + adder <= n) pos += adder, adder *= 4, base *= 4, aim *= 4;
  while (pos != n) {
    long long dist = n - pos;
    if (dist < base / 4) {
      base /= 4;
      continue;
    } else if (dist < (base / 4) * 2) {
      pos += base / 4;
      aim += base / 2;
      base /= 4;
      continue;
    } else if (dist < (base / 4) * 3) {
      pos += base / 2;
      aim += base / 2;
      aim += base / 4;
      base /= 4;
      continue;
    } else {
      pos += base / 2;
      pos += base / 4;
      aim += base / 4;
      base /= 4;
    }
  }
  return aim;
}
int main() {
  Fast_IO();
  int n_testcases;
  cin >> n_testcases;
  for (int n_testcase = 1; n_testcase <= n_testcases; n_testcase++) {
    long long n;
    cin >> n;
    if (n % 3 == 1)
      cout << easy(n / 3 + 1) << '\n';
    else if (n % 3 == 2)
      cout << hard(n / 3 + 1) << '\n';
    else
      cout << (easy(n / 3) ^ hard(n / 3)) << '\n';
  }
  return 0;
}
