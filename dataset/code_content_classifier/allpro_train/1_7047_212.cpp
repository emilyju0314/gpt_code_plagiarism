#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<bool> > tk(n, vector<bool>(n, false));
  for (int i = 0; i + 3 <= n; i++) {
    for (int j = 0; j + 3 <= n; j++) {
      int sz = 0;
      if (a[i][j + 1] == '#') sz++;
      if (a[i + 1][j] == '#') sz++;
      if (a[i + 1][j + 1] == '#') sz++;
      if (a[i + 1][j + 2] == '#') sz++;
      if (a[i + 2][j + 1] == '#') sz++;
      if (sz == 5) {
        sz = 0;
        if (!tk[i][j + 1]) sz++;
        if (!tk[i + 1][j]) sz++;
        if (!tk[i + 1][j + 1]) sz++;
        if (!tk[i + 1][j + 2]) sz++;
        if (!tk[i + 2][j + 1]) sz++;
        if (sz < 5) {
          continue;
        }
        tk[i][j + 1] = true;
        tk[i + 1][j] = true;
        tk[i + 1][j + 1] = true;
        tk[i + 1][j + 2] = true;
        tk[i + 2][j + 1] = true;
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '#') {
        if (!tk[i][j]) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  cout << "YES" << endl;
}
