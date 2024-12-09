#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p = 1;
  cin >> n;
  string a, f;
  int c = 0, k = 0, u;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a[0] == '0') {
      k = 1;
    }
    u = 0;
    if (a[0] == '1') {
      for (int i = 1; i < a.size(); i++) {
        if (a[i] != '0') {
          f = a;
          u = 1;
          break;
        }
      }
    } else {
      f = a;
      u = 1;
    }
    if (u == 0) {
      c += a.size() - 1;
    }
  }
  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }
  cout << f;
  if (f.size() == 0) cout << 1;
  for (int i = 0; i < c; i++) {
    cout << 0;
  }
  cout << endl;
  return 0;
}
