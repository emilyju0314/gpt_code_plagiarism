#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
const long long mod = 1e9 + 7;
long long f[N][3], p3[N], pre[N], n, i;
string s;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> s;
  p3[0] = 1;
  pre[0] = (s[0] == '?') ? 1 : 0;
  for (i = 1; i <= n; i++) p3[i] = p3[i - 1] * 3 % mod;
  for (i = 1; i < n; i++) pre[i] = (s[i] == '?') ? pre[i - 1] + 1 : pre[i - 1];
  memset(f, 0, sizeof(f));
  if (s[0] == 'a' || s[0] == '?') f[0][0] = 1;
  for (i = 1; i < n; i++) {
    if (s[i] == '?') {
      f[i][0] = (3 * f[i - 1][0] + p3[pre[i - 1]]) % mod;
      f[i][1] = (3 * f[i - 1][1] + f[i - 1][0]) % mod;
      f[i][2] = (3 * f[i - 1][2] + f[i - 1][1]) % mod;
    } else {
      f[i][0] = f[i - 1][0] % mod;
      f[i][1] = f[i - 1][1] % mod;
      f[i][2] = f[i - 1][2] % mod;
      if (s[i] == 'a') f[i][0] = (f[i][0] + p3[pre[i - 1]]) % mod;
      if (s[i] == 'b') f[i][1] = (f[i][1] + f[i - 1][0]) % mod;
      if (s[i] == 'c') f[i][2] = (f[i][2] + f[i - 1][1]) % mod;
    }
  }
  cout << f[n - 1][2] << endl;
  return 0;
}
