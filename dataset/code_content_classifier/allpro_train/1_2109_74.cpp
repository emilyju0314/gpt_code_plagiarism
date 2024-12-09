#include <bits/stdc++.h>
using namespace std;
string a;
long long i, t, j;
int main() {
  cin >> a;
  if (a[0] == 'h') {
    cout << "http://";
    if (a[4] != 'r')
      t = 4;
    else
      t = 5;
    for (i = t; i < a.size(); i++) {
      if (a[i] == 'r' && a[i + 1] == 'u') {
        for (j = 4; j <= i - 1; j++) {
          cout << a[j];
        }
        cout << ".ru";
        if (i + 1 != a.size() - 1) {
          cout << "/";
          for (j = i + 2; j < a.size(); j++) {
            cout << a[j];
          }
        }
        return 0;
      }
    }
  }
  if (a[0] == 'f') {
    cout << "ftp://";
    if (a[3] != 'r')
      t = 3;
    else
      t = 4;
    for (i = t; i < a.size(); i++) {
      if (a[i] == 'r' && a[i + 1] == 'u') {
        for (j = 3; j <= i - 1; j++) {
          cout << a[j];
        }
        cout << ".ru";
        if (i + 1 != a.size() - 1) {
          cout << "/";
          for (j = i + 2; j < a.size(); j++) {
            cout << a[j];
          }
        }
        return 0;
      }
    }
  }
}
