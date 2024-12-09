#include <bits/stdc++.h>
using namespace std;
int n, i, j, x, vst[1005][1005] = {0}, s[1005] = {0}, ans = 0;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x;
    for (j = 1; j <= n; j++)
      if (!vst[j][x]) {
        vst[j][x] = 1;
        s[j]++;
        break;
      }
  }
  for (i = 1; i <= n; i++)
    if (s[i]) ans += s[i] - 1;
  cout << ans << endl;
  return 0;
}
