#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vii = vector<pair<int, int>>;
template <class t>
ostream &operator<<(ostream &os, const vector<t> &v) {
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << " ";
    cout << v[i];
  }
  return os;
}
const int N = 1007;
int n, m, a[N][N], b[N][N];
vector<int> row[N], col[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> a[r][c];
      row[r].push_back(a[r][c]);
      col[c].push_back(a[r][c]);
    }
  }
  for (int r = 0; r < n; r++) {
    sort(row[r].begin(), row[r].end());
    row[r].erase(unique((row[r]).begin(), (row[r]).end()), row[r].end());
  }
  for (int c = 0; c < m; c++) {
    sort(col[c].begin(), col[c].end());
    col[c].erase(unique((col[c]).begin(), (col[c]).end()), col[c].end());
  }
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      int less = max(lower_bound((row[r]).begin(), (row[r]).end(), a[r][c]) -
                         row[r].begin(),
                     lower_bound((col[c]).begin(), (col[c]).end(), a[r][c]) -
                         col[c].begin());
      int more = max(
          row[r].end() - upper_bound((row[r]).begin(), (row[r]).end(), a[r][c]),
          col[c].end() -
              upper_bound((col[c]).begin(), (col[c]).end(), a[r][c]));
      b[r][c] = less + 1 + more;
    }
  }
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (c) cout << ' ';
      cout << b[r][c];
    }
    cout << '\n';
  }
}
