#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans = 0;
  pair<int, int> cur = make_pair(0, 0);
  int n, m;
  cin >> n >> m;
  char a[150][150];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = n - 1; i >= 0; i--) {
    bool sw = 1;
    for (int j = 0; j < m; j++)
      if (a[i][j] == 'W') sw = 0;
    if (sw)
      n--;
    else
      break;
  }
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cur.first = i;
    int end1 = cur.second, end2 = cur.second;
    if (i % 2 == 0) {
      for (int j = m - 1; j > cur.second; j--)
        if (a[i][j] == 'W') {
          end1 = j;
          break;
        }
      if (i < n - 1)
        for (int j = m - 1; j > cur.second; j--)
          if (a[i + 1][j] == 'W') {
            end2 = j;
            break;
          }
    } else {
      for (int j = 0; j < cur.second; j++)
        if (a[i][j] == 'W') {
          end1 = j;
          break;
        }
      if (i < n - 1)
        for (int j = 0; j < cur.second; j++)
          if (a[i + 1][j] == 'W') {
            end2 = j;
            break;
          }
    }
    ans += max(abs(end1 - cur.second), abs(end2 - cur.second));
    if (abs(end1 - cur.second) > abs(end2 - cur.second))
      cur.second = end1;
    else
      cur.second = end2;
  }
  cout << ans + n - 1 << endl;
  return 0;
}
