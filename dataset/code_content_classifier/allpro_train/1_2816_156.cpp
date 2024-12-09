#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  k = 0;
  cin >> n >> m;
  char s[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((s[i][j] == 'C') || (s[i][j] == 'M') || (s[i][j] == 'Y')) {
        k++;
        i = n;
        j = m;
      }
    }
  }
  if (k == 1) {
    cout << "#Color";
  } else {
    cout << "#Black&White";
  }
  return 0;
}
