#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int base = 1000003;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vector<vector<int>> d(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1' || s[i][j] == '4') d[i][j] = 2;
      if (s[i][j] == '2' || s[i][j] == '3') d[i][j] = 1;
    }
  int cnt = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (d[i][j] == 1) {
        if (i + 1 < n)
          if (d[i + 1][j] == 1)
            cnt = 0;
          else
            d[i + 1][j] = 2;
      }
      if (d[i][j] == 2) {
        if (i > 0)
          if (d[i - 1][j] == 2)
            cnt = 0;
          else
            d[i - 1][j] = 1;
      }
    }
  long long c = 1, cc = 1;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (d[i][j] == 0) {
        int a = i;
        while (i < n && d[i][j] == 0) i++;
        if ((i - a) % 2 && a != 0 && i != n)
          cnt = 0;
        else if (a == 0 && i == n)
          c = c * 2 % base;
      }
    }
  }
  vector<vector<int>> e(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1' || s[i][j] == '2') e[i][j] = 2;
      if (s[i][j] == '4' || s[i][j] == '3') e[i][j] = 1;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (e[i][j] == 1) {
        if (j + 1 < m)
          if (e[i][j + 1] == 1)
            cnt = 0;
          else
            e[i][j + 1] = 2;
      }
      if (e[i][j] == 2) {
        if (j > 0)
          if (e[i][j - 1] == 2)
            cnt = 0;
          else
            e[i][j - 1] = 1;
      }
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (e[i][j] == 0) {
        int a = j;
        while (j < m && e[i][j] == 0) j++;
        if ((j - a) % 2 && a != 0 && j != m)
          cnt = 0;
        else if (a == 0 && j == m)
          cc = cc * 2 % base;
      }
    }
  }
  if (cnt == 0)
    cout << cnt << endl;
  else
    cout << c * cc % base << endl;
}
