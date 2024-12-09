#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  if ( n == 1LL ) {
    cout << (m+1) % MOD << endl;
    return 0;
  }
  
  int b = m / (n-1LL);
  int sum = (b-1LL) % MOD;
  sum = (sum * (b % MOD)) % MOD;
  sum = (sum * ((n-1LL) % MOD)) % MOD;

  int sum2 = (2LL * b) % MOD;
  sum2 = (sum2 * ((m - ((n-1LL) % MOD) * (b % MOD) + 1LL) % MOD)) % MOD;
  //cout <<  2 * b * (m - (n-1) * b + 1) << endl;
  sum += (m+1LL);
  sum += sum2;

  cout << sum % MOD << endl;
  return 0;
}