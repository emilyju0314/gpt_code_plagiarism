#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, ans = 0;
  cin >> n >> m;
  bool a[n][m];
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (m); (j)++) cin >> a[i][j];
  bool f;
  for (int(i) = (0); (i) < (n); (i)++) {
    f = false;
    for (int(j) = (0); (j) < (m); (j)++)
      if (a[i][j] == 1)
        f = true;
      else if (f)
        ans++;
  }
  for (int(i) = (0); (i) < (n); (i)++) {
    f = false;
    for (int(j) = (m)-1; (j) >= (0); (j)--)
      if (a[i][j] == 1)
        f = true;
      else if (f)
        ans++;
  }
  for (int(i) = (0); (i) < (m); (i)++) {
    f = false;
    for (int(j) = (0); (j) < (n); (j)++)
      if (a[j][i] == 1)
        f = true;
      else if (f)
        ans++;
  }
  for (int(i) = (0); (i) < (m); (i)++) {
    f = false;
    for (int(j) = (n)-1; (j) >= (0); (j)--)
      if (a[j][i] == 1)
        f = true;
      else if (f)
        ans++;
  }
  cout << ans;
  return 0;
}
