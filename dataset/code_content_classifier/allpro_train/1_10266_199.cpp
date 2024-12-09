#include <bits/stdc++.h>
using namespace std;
int is_here(char *a, char x) {
  for (int i = 0; i < 26; ++i)
    if (a[i] == x) return i;
  return -1;
}
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  char ans[26];
  for (int i = 0; i < 26; ++i) ans[i] = i + 'a';
  char x, y;
  int i_x, i_y;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    i_x = is_here(ans, x);
    i_y = is_here(ans, y);
    if (i_x >= 0)
      ans[i_x] = y;
    else
      ans[x - 'a'] = y;
    if (i_y >= 0)
      ans[i_y] = x;
    else
      ans[y - 'a'] = x;
  }
  for (int i = 0; i < n; ++i) cout << ans[s[i] - 'a'];
  return 0;
}
