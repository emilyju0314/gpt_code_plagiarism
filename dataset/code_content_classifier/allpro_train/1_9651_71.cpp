#include <bits/stdc++.h>
using namespace std;
int x[100000 + 100];
int y[100000 + 100];
int z[100000 + 100];
int main() {
  string s;
  int n, m, l, r;
  cin >> s;
  n = s.size();
  cin >> m;
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  memset(z, 0, sizeof(z));
  for (int i = 1; i <= n; i++) {
    x[i] = x[i - 1];
    y[i] = y[i - 1];
    z[i] = z[i - 1];
    if (s[i - 1] == 'x') x[i]++;
    if (s[i - 1] == 'y') y[i]++;
    if (s[i - 1] == 'z') z[i]++;
  }
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    if (min(x[r] - x[l - 1], min(y[r] - y[l - 1], z[r] - z[l - 1])) + 1 >=
        max(x[r] - x[l - 1], max(y[r] - y[l - 1], z[r] - z[l - 1])))
      cout << "YES\n";
    else if (r - l + 1 < 3)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
