#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
long long large = 2000000000000000000LL;
int main() {
  mod = 998244353LL;
  int n;
  cin >> n;
  vector<long long> per(n + 10, 1);
  for (long long i = 1; i <= n; i++) {
    per[i] = i * per[i - 1] % mod;
  }
  vector<long long> ans(n + 10, 0);
  ans[1] = 1;
  ans[2] = 2;
  for (long long i = 3; i <= n; i++) {
    long long c = ans[i - 1] + mod - per[i - 1];
    c %= mod;
    ans[i] = per[i] + i * (per[i - 1] + mod - 1) % mod + i * c % mod;
    ans[i] %= mod;
  }
  cout << ans[n] << endl;
  return 0;
}
