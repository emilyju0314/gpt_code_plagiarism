#include <bits/stdc++.h>
using namespace std;
long long pre[100005], power[100005];
int main() {
  string s;
  cin >> s;
  long long i, j, number, x, a, y, ans = 0, m;
  m = s.size();
  pre[0] = power[0] = 1;
  for (i = 1; i <= (100005 - 5); i++)
    power[i] = (10LL * power[i - 1]) % 1000000007;
  for (i = 1; i <= (100005 - 5); i++) {
    pre[i] = ((i + 1) * power[i]) % 1000000007;
    pre[i] = (pre[i] + pre[i - 1]) % 1000000007;
  }
  for (i = 0; i < m; i++) {
    a = s[i] - '0';
    if (i > 0) {
      x = (i * (i + 1) / 2) % 1000000007;
      x = (x * power[m - i - 1]) % 1000000007;
      x = (x * a) % 1000000007;
      ans = (ans + x) % 1000000007;
    }
    if (i < m - 1) {
      y = (pre[m - i - 2] * a) % 1000000007;
      ans = (ans + y) % 1000000007;
    }
  }
  cout << ans << endl;
}
