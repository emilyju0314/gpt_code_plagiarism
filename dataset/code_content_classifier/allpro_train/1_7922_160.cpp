#include <bits/stdc++.h>
using namespace std;
int n;
string s[60];
string ans[110];
void print() {
  for (int i = 0; i < 2 * n + 1; i++) {
    cout << ans[i] << endl;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      ans[i] += 'x';
    }
  }
  ans[n - 1][n - 1] = 'o';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'o') {
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < n; l++) {
            if (s[k][l] == '.') {
              ans[k - i + n - 1][l - j + n - 1] = '.';
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'x') {
        bool find = false;
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < n; l++) {
            if (s[k][l] == 'o' && ans[i - k + n - 1][j - l + n - 1] == 'x')
              find = true;
          }
        }
        if (!find) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < 2 * n - 1; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
