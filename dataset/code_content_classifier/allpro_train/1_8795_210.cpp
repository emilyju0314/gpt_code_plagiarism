#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a[4] = {0}, r, g, y, b;
  string s;
  cin >> s;
  n = s.size();
  for (i = 0; i < n; i++) {
    if (s[i] == '!') {
      if (i % 4 == 0) a[i % 4]++;
      if (i % 4 == 1) a[i % 4]++;
      if (i % 4 == 2) a[i % 4]++;
      if (i % 4 == 3) a[i % 4]++;
    }
  }
  for (i = 0; i < n; i++) {
    if (s[i] == 'R') r = a[i % 4];
    if (s[i] == 'G') g = a[i % 4];
    if (s[i] == 'B') b = a[i % 4];
    if (s[i] == 'Y') y = a[i % 4];
  }
  cout << r << " " << b << " " << y << " " << g;
}
