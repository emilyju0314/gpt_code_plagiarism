#include <bits/stdc++.h>
using namespace std;
long long n, mod = 1000000007;
long long mypow(long long tm) {
  if (tm == 0) return 1;
  long long ret = mypow(tm / 2);
  ret *= ret;
  if (tm % 2) ret *= 2;
  ret %= mod;
  return ret;
}
int main() {
  cin >> n;
  if (n < 1)
    cout << 1;
  else
    cout << mypow(n - 1) * (mypow(n) + 1) % mod;
}
