#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 233;
string s;
long long f[100];
int vis[maxn][100];
void cal(int x) {
  long long cur = 0;
  for (int i = 0; i < 26; i++) f[i] = f[i] ? 1 : 0;
  for (int i = 0; i < s.length(); i++) {
    vis[x][s[i] - 'a'] = 1;
    if (i && s[i] == s[i - 1])
      cur++;
    else
      cur = 1;
    int c = s[i] - 'a';
    f[c] = max(f[c], cur);
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  cin >> s;
  memset(f, 0, sizeof(f));
  cal(1);
  for (int i = 2; i <= n; i++) {
    cin >> s;
    bool ok = 1;
    for (int j = 1; j < s.length(); j++)
      if (s[j] != s[j - 1]) ok = 0;
    if (ok) {
      int k = s.length();
      for (int j = 0; j < 26; j++)
        if (j != s[0] - 'a') f[j] = f[j] ? 1 : 0;
      int c = s[0] - 'a';
      f[c] = (f[c] + 1) * k + f[c];
      if (f[c] > 1e9) f[c] = 1e9;
      vis[i][c] = 1;
    } else {
      cal(i);
      int c = s[0] - 'a';
      if (vis[i - 1][c]) {
        int i = 1, len = 1;
        while (s[i] == s[i - 1]) i++, len++;
        f[c] = max(f[c], 1LL * i + 1);
      }
      int d = s[s.length() - 1] - 'a';
      if (d != c) {
        if (vis[i - 1][d]) {
          int i = s.length() - 2;
          while (s[i] == s[i + 1]) i--;
          f[d] = max(f[d], (long long)s.length() - i + 0LL);
        }
      } else if (vis[i - 1][c]) {
        int i = 1, len = 1;
        while (s[i] == s[i - 1]) i++, len++;
        i = s.length() - 2;
        len++;
        while (s[i] == s[i + 1]) i--, len++;
        f[c] = max(f[c], len + 1LL);
      }
    }
    for (int j = 0; j < 26; j++) vis[i][j] |= vis[i - 1][j];
  }
  long long ans = 0;
  for (int i = 0; i < 26; i++) ans = max(ans, f[i]);
  cout << ans << endl;
  return 0;
}
