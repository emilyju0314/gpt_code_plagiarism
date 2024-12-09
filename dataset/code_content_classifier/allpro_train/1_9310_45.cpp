#include <bits/stdc++.h>
using namespace std;
int w, m;
int a[105];
string sol() {
  int len = 0, x = m;
  while (x) {
    a[len++] = x % w;
    x /= w;
  }
  for (int(i) = (0); (i) <= (len); ++(i)) {
    if (a[i] != 0 && a[i] != 1) {
      if (a[i] == w - 1 || a[i] == w) {
        ++a[i + 1];
      } else {
        return "NO";
      }
    }
  }
  return "YES";
}
int main() {
  cin >> w >> m;
  cout << sol();
  return 0;
}
