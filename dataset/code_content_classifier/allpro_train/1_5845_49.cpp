#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
string s[N];
int h[N][N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < 6; k++)
        if (s[i][k] != s[j][k]) h[i][j]++;
  int ans = 0;
  for (int k = 0; k <= 6; k++) {
    bool fl = 1;
    for (int i = 0; i < n && fl; i++)
      for (int j = i + 1; j < n; j++)
        if (2 * k >= h[i][j]) {
          fl = 0;
          break;
        }
    if (fl) ans = k;
  }
  cout << ans << endl;
  return 0;
}
