#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int a[n][m];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      a[i][j] = 0;
    }
  }
  long long int x, y;
  for (long long int i = 0; i < k; i++) {
    cin >> x >> y;
    a[x - 1][y - 1] = 1;
  }
  for (long long int i = 0; i < k; i++) {
    cin >> x >> y;
  }
  if (n + m - 3 > n * m) {
    cout << "-1\n";
    return 0;
  }
  string s = "";
  for (long long int i = 0; i < m - 1; i++) {
    s += 'L';
  }
  for (long long int i = 0; i < n - 1; i++) {
    s += 'D';
  }
  bool dir = false;
  for (long long int i = 0; i < n; i++) {
    if (!dir) {
      for (long long int i = 0; i < m - 1; i++) {
        s += 'R';
      }
      dir = true;
    } else {
      for (long long int i = 0; i < m - 1; i++) {
        s += 'L';
      }
      dir = false;
    }
    if (i == n - 1) continue;
    s += 'U';
  }
  cout << s.size() << "\n";
  cout << s << "\n";
  return 0;
}
