#include <bits/stdc++.h>
using namespace std;
string s[20];
int t, n, m, cnt;
bool check(string a) {
  for (int i = 2; i <= n; i++) {
    cnt = 0;
    for (int j = 1; j <= m; j++)
      if (a[j] != s[i][j]) cnt++;
    if (cnt > 1) return 0;
  }
  return 1;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      s[i] = '$' + s[i];
    }
    string ans = s[1];
    bool f = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 0; j < 26; j++) {
        char c = ans[i];
        ans[i] = j + 'a';
        if (check(ans)) {
          f = 1;
          break;
        }
        ans[i] = c;
      }
      if (f) break;
    }
    if (f) {
      for (int i = 1; i <= m; i++) printf("%c", ans[i]);
      printf("\n");
    } else
      printf("-1\n");
  }
}
