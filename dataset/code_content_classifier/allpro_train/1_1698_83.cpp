#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2 - 1 << endl;
  } else {
    cout << n / 2 << endl;
  }
  return 0;
}
