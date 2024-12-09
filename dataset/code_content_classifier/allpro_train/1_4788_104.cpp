#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int MOD = 1000000007;
long long n, st[N], en[N];
int solve() {
  string s;
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) {
    int j = 0;
    while (i + j < n && i - j >= 0 && s[i + j] == s[i - j]) {
      st[i - j]++;
      en[i + j]++;
      j++;
    }
    j = 0;
    while (i + j + 1 < n && i - j >= 0 && s[i + j + 1] == s[i - j]) {
      st[i - j]++;
      en[i + j + 1]++;
      j++;
    }
  }
  for (int i = n - 1; i >= 0; i--) st[i] += st[i + 1];
  long long ans = 0;
  for (int i = 0; i < n; i++) ans += st[i + 1] * en[i];
  return cout << ans, 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
