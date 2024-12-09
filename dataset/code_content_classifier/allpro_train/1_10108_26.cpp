#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  char a[500][500];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  bool cek = true;
  int it = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int q = (a[i - 1][j]);
      int w = (a[i + 1][j]);
      int e = (a[i][j - 1]);
      int r = (a[i][j + 1]);
      int t = (a[i - 1][j + 1]);
      int y = (a[i - 1][j - 1]);
      int u = (a[i + 1][j - 1]);
      int o = (a[i + 1][j + 1]);
      if (a[i][j] != '*' && a[i][j] != '.') {
        if (q == '*') it++;
        if (w == '*') it++;
        if (e == '*') it++;
        if (r == '*') it++;
        if (t == '*') it++;
        if (y == '*') it++;
        if (u == '*') it++;
        if (o == '*') it++;
        if (it != (a[i][j] - '0')) cek = false;
        it = 0;
      }
      if (a[i][j] == '.') {
        if (q == '*' || w == '*' || e == '*' || r == '*' || t == '*' ||
            y == '*' || u == '*' || o == '*')
          cek = false;
      }
    }
  }
  if (!cek)
    puts("NO");
  else
    puts("YES");
}
