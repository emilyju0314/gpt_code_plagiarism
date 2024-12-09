#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int c[30];
int t[30];
int main() {
  int ans = 0;
  string s, p;
  cin >> s >> p;
  int n = s.length(), m = p.length();
  if (n < m) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < m; i++)
    if (s[i] != '?') c[s[i] - '0' - 49]++;
  for (int i = 0; i < m; i++) t[p[i] - '0' - 49]++;
  int k = 0;
  for (int i = 0; i < 26; i++)
    if (t[i] >= c[i]) k++;
  if (k == 26) ans++;
  for (int i = 1; i <= n - m; i++) {
    k = 0;
    if (s[i + m - 1] != '?') c[s[i + m - 1] - '0' - 49]++;
    if (s[i - 1] != '?') c[s[i - 1] - '0' - 49]--;
    for (int j = 0; j < 26; j++)
      if (t[j] >= c[j]) k++;
    if (k == 26) ans++;
  }
  cout << ans;
  return 0;
}
