#include <bits/stdc++.h>
using namespace std;
string s;
int n, i, j, k, mx = 0, sum = 0, vis[5005], letter[26], check[26][5005][26], ok;
double ans = 0;
int main() {
  cin >> s;
  n = s.length();
  s = s + s;
  for (i = 0; i < n; i++) {
    letter[s[i] - 'a']++;
    for (j = i; j < i + n; j++) {
      check[s[i] - 'a'][j - i + 1][s[j] - 'a']++;
    }
  }
  for (i = 0; i < 26; i++) {
    if (!letter[i]) continue;
    mx = -1;
    for (j = 2; j <= n; j++) {
      sum = 0;
      for (k = 0; k < 26; k++)
        if (check[i][j][k] == 1) sum += 1;
      mx = max(mx, sum);
    }
    ans += 1.0 * mx / n;
  }
  printf("%lf", ans);
  return 0;
}
