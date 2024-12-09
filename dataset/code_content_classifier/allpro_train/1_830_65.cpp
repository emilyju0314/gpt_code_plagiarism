#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, i, j = -1, x, y;
  cin >> a >> b >> c >> d;
  int t[100], s[100];
  for (i = 0; i < 100; i++) {
    j++;
    x = b + a * i;
    t[i] = {x};
    y = d + c * j;
    s[i] = {y};
  }
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      if (t[i] == s[j]) {
        cout << t[i];
        return 0;
      }
    }
  }
  cout << "-1";
  return 0;
}
