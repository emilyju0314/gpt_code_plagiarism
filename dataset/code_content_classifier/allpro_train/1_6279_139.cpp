#include <bits/stdc++.h>
using namespace std;
int f[27];
int main() {
  int n, i, j;
  cin >> n;
  char c;
  int flag = 0;
  for (i = 0; i < n; i++) {
    cin >> c;
    f[c - 'a']++;
  }
  if (n > 26 || flag == 1)
    cout << -1 << endl;
  else {
    int ans = 0;
    for (i = 0; i <= 26; i++) {
      if (f[i] >= 2) ans += f[i] - 1;
    }
    cout << ans << endl;
  }
  return 0;
}
