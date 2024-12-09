#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p;
  cin >> n >> p;
  string a;
  cin >> a;
  int i = 0;
  int l = 0;
  int cnt = 0;
  while (i + p <= n - 1) {
    if (a[i] != a[i + p] && a[i] != '.' && a[i + p] != '.') {
      l = 1;
    }
    if (a[i] == '.' || a[i + p] == '.') {
      l = 1;
    }
    i++;
  }
  if (l == 0) {
    cout << "No";
  } else {
    i = 0;
    char ans = '0';
    while (i + p <= n - 1) {
      if (a[i] == '.') {
        if (a[i + p] != '.') {
          if (a[i + p] == '1') {
            a[i] = '0';
            ans = '0';
          } else {
            a[i] = '1';
            ans = '1';
          }
          break;
        }
      } else if (a[i] != '.') {
        if (a[i + p] == '.') {
          if (a[i] == '0') {
            a[i + p] = '1';
            ans = '1';
          } else {
            a[i + p] = '0';
            ans = '0';
          }
          break;
        }
      }
      i++;
    }
    i = 0;
    while (i <= n - 1) {
      if (a[i] == '.') {
        a[i] = '0';
        if (i + p <= n - 1 && a[i + p] == '.') {
          a[i + p] = '1';
        }
      }
      i++;
    }
    for (int i = 0; i < n; i++) {
      cout << a[i];
    }
  }
  cout << endl;
}
