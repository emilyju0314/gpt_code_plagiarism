#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[4][100];
  for (int i = 0; i < 4; i++) {
    for (long long int j = 1; j < 100; j++) s[i][j] = '.';
  }
  long long int n, k;
  cin >> n >> k;
  cout << "YES\n";
  if (k != 0) {
    if (k % 2 == 0) {
      long long int i = 1, j = n / 2 + 1;
      s[1][j] = '#';
      s[2][j] = '#';
      j--;
      k -= 2;
      while (k != 0) {
        s[i][j] = '#';
        s[i][n - j + 1] = '#';
        k -= 2;
        j--;
        if (j == 1) {
          i = 2;
          j = n / 2;
        }
      }
    } else {
      long long int j = n / 2 + 1;
      if (k <= n - 2) {
        s[1][j] = '#';
        j--;
        k--;
        while (k != 0) {
          s[1][j] = '#';
          s[1][n - j + 1] = '#';
          j--;
          k -= 2;
        }
      } else {
        for (long long int i = 2; i < n; i++) s[1][i] = '#';
        k -= n - 2;
        if (k % 2 == 0) {
          long long int j = n / 2;
          while (k != 0) {
            s[2][j] = '#';
            s[2][n - j + 1] = '#';
            j--;
            k -= 2;
          }
        } else {
          long long int j = n / 2 + 1;
          s[2][j] = '#';
          k--;
          j--;
          while (k != 0) {
            s[2][j] = '#';
            s[2][n - j + 1] = '#';
            j--;
            k -= 2;
          }
        }
      }
    }
  }
  for (long long int i = 0; i < 4; i++) {
    for (long long int j = 1; j <= n; j++) cout << s[i][j];
    cout << "\n";
  }
  return 0;
}
