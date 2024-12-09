#include <bits/stdc++.h>
using namespace std;
char arr[200][200];
int main() {
  bool is = false;
  int n, m, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> arr[i][j];
  bool flag = false;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (arr[i][j] == 'B' && !flag) {
        flag = true;
        is = true;
        x1 = i;
      }
    }
  }
  if (!is) {
    cout << 1;
    return 0;
  }
  flag = false;
  for (int i = n; i > 0; --i) {
    for (int j = m; j > 0; --j) {
      if (arr[i][j] == 'B' && !flag) {
        flag = true;
        x2 = i;
      }
    }
  }
  flag = false;
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      if (arr[i][j] == 'B' && !flag) {
        flag = true;
        y1 = j;
      }
    }
  }
  flag = false;
  for (int j = m; j > 0; --j) {
    for (int i = n; i > 0; --i) {
      if (arr[i][j] == 'B' && !flag) {
        flag = true;
        y2 = j;
      }
    }
  }
  int len = max(abs(y1 - y2) + 1, abs(x1 - x2) + 1), ans = 0;
  if (len > m || len > n) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i <= max(x1, x2) && i >= min(x1, x2) && j >= min(y1, y2) &&
          j <= max(y1, y2)) {
        if (arr[i][j] == 'W') ans++;
      }
    }
  }
  ans += abs(abs(y1 - y2) - abs(x1 - x2)) * len;
  cout << ans;
  cin >> ans;
  return 0;
}
