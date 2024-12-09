#include <bits/stdc++.h>
using namespace std;
const int INF = ~(1 << 31);
int main() {
  int n, i, j, g = 0, m, k, h, z, c, mx = -INF, mn = INF, b;
  char ch;
  string s1, s2;
  cin >> s1 >> s2;
  n = s1.size();
  vector<vector<int> > a(n, vector<int>(26, -1));
  a[n - 1][s1[n - 1] - 'a'] = 0;
  for (i = n - 2; i >= 0; i--) {
    for (j = 0; j < 26; j++) {
      if (s1[i] - 'a' == j)
        a[i][j] = 0;
      else {
        g = a[i + 1][j];
        if (g != -1) a[i][j] = g + 1;
      }
    }
  }
  g = 0;
  j = 0;
  for (i = 0; i < s2.size(); i++) {
    if (j >= s1.size()) {
      j = 0;
      g++;
    }
    ch = s2[i] - 'a';
    if (a[0][ch] == -1) {
      cout << "-1";
      return 0;
    }
    if (a[j][ch] == -1) {
      j = 0;
      g++;
    }
    j += a[j][ch] + 1;
  }
  cout << g + 1;
  return 0;
}
