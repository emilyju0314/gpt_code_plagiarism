#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long k, ans = 0;
long long pw(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = pw(x, y / 2);
  if (y % 2 == 0)
    return temp * temp % MOD;
  else
    return ((x * temp) % MOD) * temp % MOD;
}
int main() {
  string s;
  cin >> s >> k;
  for (int i = s.size() - 1; i >= 0; i--)
    if (s[i] == '0' || s[i] == '5') ans = (ans + pw(2, i)) % MOD;
  cout << ans * (pw(pw(2, s.size()), k) - 1) % MOD *
              pw((pw(2, s.size()) - 1), (MOD - 2) % (MOD - 1)) % MOD
       << endl;
}
