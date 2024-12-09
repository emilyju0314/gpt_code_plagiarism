#include <bits/stdc++.h>
using namespace std;
long long sum[1000007];
int cnta;
long long Pow(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    x = (x * x) % 1000000007;
    y >>= 1;
  }
  return res;
}
void solve() {
  sum[0] = 1;
  for (int i = 1; i < 1000007; i++) {
    sum[i] = (sum[i - 1] + Pow(2, i)) % 1000000007;
  }
}
int main() {
  solve();
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a')
      cnta++;
    else if (cnta) {
      ans = (ans + sum[cnta - 1]) % 1000000007;
    }
  }
  cout << ans << endl;
  return 0;
}
