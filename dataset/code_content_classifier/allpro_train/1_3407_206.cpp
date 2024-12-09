#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<string> a(n, "");
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    string h = "";
    int p = 0;
    for (int j = 0; j < s.size(); ++j)
      if (s[j] == '.') {
        for (int w = 0; w < 3 - p; ++w) a[i] += '0';
        a[i] += h;
        h = "";
        p = 0;
      } else {
        ++p;
        h += s[j];
      }
    for (int w = 0; w < 3 - p; ++w) a[i] += '0';
    a[i] += h;
  }
  sort(a.begin(), a.end());
  vector<vector<int> > m(32, vector<int>(4, 0));
  int t = 128;
  int b = 0;
  int z = 0;
  for (int i = 0; i < 32; ++i) {
    if (b == 255) {
      b = 0;
      t = 128;
      ++z;
    }
    b += t;
    t = t / 2;
    for (int j = 0; j < z; ++j) m[i][j] = 255;
    m[i][z] = b;
  }
  vector<vector<int> > c(n, vector<int>(4, 0));
  for (int i = 0; i < n; ++i) {
    int k = 0;
    for (int j = 0; j < 12; ++j) {
      if (k == 3) k = 0;
      int q = a[i][j] - '0';
      c[i][j / 3] = 10 * c[i][j / 3] + q;
      ++k;
    }
  }
  vector<vector<int> > ans(n, vector<int>(4, 0));
  for (int i = 0; i < 32; ++i) {
    for (int j = 0; j < n; ++j)
      for (int v = 0; v < 4; ++v) ans[j][v] = c[j][v] & m[i][v];
    int q = 1;
    for (int j = 1; j < n; ++j)
      for (int v = 0; v < 4; ++v)
        if (ans[j - 1][v] != ans[j][v]) {
          ++q;
          break;
        }
    if (k == q) {
      for (int j = 0; j < 4; ++j)
        if (j == 3)
          cout << m[i][j];
        else
          cout << m[i][j] << ".";
      return 0;
    }
  }
  cout << -1;
  return 0;
}
