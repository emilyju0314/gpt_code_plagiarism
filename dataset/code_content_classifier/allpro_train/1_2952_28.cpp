#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[50][50], b[50][50] = {0};
vector<pair<int, int> > op;
int c[4][2] = {{-1, -1}, {-1, +1}, {+1, -1}, {+1, +1}};
bool is_needed(int x, int y) {
  bool is_needed = false;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      is_needed = is_needed || (a[x + i][y + j] == 1 && b[x + i][y + j] == 0);
  return is_needed;
}
bool is_valid(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < m); }
bool maybe_fit(int x, int y) {
  int l, r;
  bool valid;
  l = 1;
  r = 1;
  valid = true;
  for (int j = 0; j < 2; j++) {
    for (int k = 0; k < 2; k++) {
      valid = valid && is_valid(x + l * j, y + r * k) &&
              (a[x + l * j][y + r * k] == 1);
    }
  }
  if (valid) {
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) b[x + l * j][y + r * k] = 1;
    return true;
  }
  return false;
}
int main() {
  int i, j;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < m - 1; j++) {
      if (is_needed(i, j) && maybe_fit(i, j)) {
        op.push_back(make_pair(i, j));
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i][j] != b[i][j]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << op.size() << endl;
  for (i = 0; i < op.size(); i++) {
    cout << op[i].first + 1 << " " << op[i].second + 1 << endl;
  }
  return 0;
}
