#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > records;
void construct(vector<vector<int> >& grid, int n) {
  if (n == 1) return;
  int emp = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (emp != -1) break;
    for (int j = 0; j < n; j++) {
      if (grid[j][i]) break;
      if (j == n - 1) {
        emp = i;
      }
    }
  }
  if (emp != n - 1) {
    records.push_back(make_pair(2, make_pair(emp + 1, n)));
    for (int i = 0; i < n; i++) {
      swap(grid[i][emp], grid[i][n - 1]);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (!grid[i][n - 1] && count((grid[i]).begin(), (grid[i]).end(), 1)) {
      emp = i;
      break;
    }
  }
  if (emp != n - 1) {
    records.push_back(make_pair(1, make_pair(emp + 1, n)));
    swap(grid[emp], grid[n - 1]);
  }
  construct(grid, n - 1);
}
int main() {
  int n;
  cin >> n;
  vector<vector<int> > grid(n, vector<int>(n, 0));
  int x, y;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    grid[x - 1][y - 1] = 1;
  }
  construct(grid, n);
  cout << (int)(records).size() << endl;
  for (int i = 0; i < (int)(records).size(); i++) {
    cout << records[i].first << " " << records[i].second.first << " "
         << records[i].second.second << "\n";
  }
  return 0;
}
