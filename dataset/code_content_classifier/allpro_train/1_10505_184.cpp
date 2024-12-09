#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  string s, ch;
  for (int i = 0; i < n; i++) {
    cin >> s;
    bool det = true;
    for (int j = 1; j < m; j++) {
      if (s[j] != s[j - 1]) {
        det = false;
      }
    }
    if (det == false) {
      printf("NO\n");
      return 0;
    }
    if (i > 0 && ch[0] == s[0]) {
      printf("NO\n");
      return 0;
    }
    ch = s;
  }
  printf("YES\n");
  return 0;
}
