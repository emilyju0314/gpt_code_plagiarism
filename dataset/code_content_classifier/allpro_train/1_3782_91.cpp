#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, inv = 5e8 + 4;
long long n, m, k;
long long pow(long long base, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp & 1) (res *= base) %= mod;
    exp >>= 1;
    (base *= base) %= mod;
  }
  return res;
}
int main() {
  cin >> n >> m >> k;
  --n;
  --m;
  if (k == -1 && n + m & 1)
    cout << 0;
  else
    cout << pow(pow(2, n), m);
}
