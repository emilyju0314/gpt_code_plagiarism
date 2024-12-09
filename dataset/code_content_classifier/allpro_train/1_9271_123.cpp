#include <bits/stdc++.h>
using namespace std;
bool pr[1000007];
void sieve() {
  pr[0] = 1;
  pr[1] = 1;
  for (int i = 2; i * i < (1000007); i++) {
    for (int j = 2 * i; j <= 1000007; j += i) {
      pr[j] = 1;
    }
  }
}
long long fpow(long long x, long long y) {
  x = x % 998244353;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= 998244353;
    y = y >> 1;
    x = x * x;
    x %= 998244353;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int a[n + 1];
  int b[m + 1];
  int i = 0;
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  for (auto e : s) {
    if (e == '1') a[i] = 1;
    i++;
  }
  i = 0;
  for (auto e : t) {
    if (e == '1') b[i] = 1;
    i++;
  }
  long long pre[m + 1];
  pre[0] = b[0];
  for (int i = 1; i < m; i++) {
    pre[i] = pre[i - 1] + b[i];
  }
  int j = m - 1;
  long long ans = 0;
  int ii = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 1) {
      if (j >= 0)
        ans = (ans + fpow(2, ii) % 998244353 * pre[j] % 998244353) % 998244353;
    }
    ii++;
    j--;
  }
  cout << ans;
}
