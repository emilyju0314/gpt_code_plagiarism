#include <bits/stdc++.h>
using namespace std;
inline void sol() {
  long long n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for (auto &i : grid)
    for (auto &j : i) cin >> j;
  long long s1 = grid[0][1] + grid[1][0] - 2 * '0';
  long long s2 = grid[n - 1][n - 2] + grid[n - 2][n - 1] - 2 * '0';
  if (s1 == s2 and (s1 == 2 or s1 == 0)) {
    cout << 2 << endl;
    cout << "1 2\n2 1\n";
    return;
  }
  if ((s1 == 2 and s2 == 0) or (s1 == 0 and s2 == 2)) {
    cout << 0 << endl;
    return;
  }
  if ((s1 == 0 or s2 == 0) and (s1 == 1 or s2 == 1)) {
    cout << 1 << endl;
    if (s1 == 0) {
      if (grid[n - 1][n - 2] == '0')
        cout << n << " " << n - 1 << endl;
      else
        cout << n - 1 << " " << n << endl;
    } else {
      if (grid[0][1] == '0')
        cout << "1 2\n";
      else
        cout << "2 1\n";
    }
    return;
  }
  if ((s1 == 2 or s2 == 2) and (s1 == 1 or s2 == 1)) {
    cout << 1 << endl;
    if (s1 == 2) {
      if (grid[n - 1][n - 2] == '1')
        cout << n << " " << n - 1 << endl;
      else
        cout << n - 1 << " " << n << endl;
    } else {
      if (grid[0][1] == '1')
        cout << "1 2\n";
      else
        cout << "2 1\n";
    }
    return;
  }
  cout << 2 << endl;
  if (grid[0][1] == '1')
    cout << "1 2\n";
  else
    cout << "2 1\n";
  if (grid[n - 1][n - 2] == '0')
    cout << n << " " << n - 1 << endl;
  else
    cout << n - 1 << " " << n << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) sol();
  return 0;
}
