#include <bits/stdc++.h>
using namespace std;
int ini() {
  int x;
  scanf("%d", &x);
  return x;
}
long long inl() {
  long long x;
  scanf("%lld", &x);
  return x;
}
pair<int, int> grid[1005][1005];
char ans[1005][1005];
int n;
void dfs(int i, int j) {
  if (i > 1) {
    if (ans[i - 1][j] == '*' && grid[i - 1][j] == grid[i][j]) {
      ans[i - 1][j] = 'D';
      dfs(i - 1, j);
    }
  }
  if (i < n) {
    if (ans[i + 1][j] == '*' && grid[i + 1][j] == grid[i][j]) {
      ans[i + 1][j] = 'U';
      dfs(i + 1, j);
    }
  }
  if (j > 1) {
    if (ans[i][j - 1] == '*' && grid[i][j - 1] == grid[i][j]) {
      ans[i][j - 1] = 'R';
      dfs(i, j - 1);
    }
  }
  if (j < n) {
    if (ans[i][j + 1] == '*' && grid[i][j + 1] == grid[i][j]) {
      ans[i][j + 1] = 'L';
      dfs(i, j + 1);
    }
  }
}
void dfs2(int i, int j) {
  if (ans[i][j] != '*') return;
  if (i > 1 && grid[i - 1][j] == make_pair(-1, -1)) {
    ans[i][j] = 'U';
    dfs2(i - 1, j);
  } else if (i < n && grid[i + 1][j] == make_pair(-1, -1)) {
    ans[i][j] = 'D';
    dfs2(i + 1, j);
  } else if (j > 1 && grid[i][j - 1] == make_pair(-1, -1)) {
    ans[i][j] = 'L';
    dfs2(i, j - 1);
  } else if (j < n && grid[i][j + 1] == make_pair(-1, -1)) {
    ans[i][j] = 'R';
    dfs2(i, j + 1);
  }
}
int main() {
  n = ini();
  vector<pair<int, int> > start, neg;
  bool is = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans[i][j] = '*';
      grid[i][j] = {ini(), ini()};
      if (grid[i][j] == make_pair(i, j))
        ans[i][j] = 'X', start.push_back(make_pair(i, j));
      if (grid[i][j] == make_pair(-1, -1)) neg.push_back({i, j});
    }
  }
  for (auto x : start) {
    dfs(x.first, x.second);
  }
  for (auto x : neg) {
    dfs2(x.first, x.second);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (ans[i][j] == '*') is = false;
  if (is) {
    cout << "VALID\n";
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) cout << ans[i][j];
      cout << "\n";
    }
  } else
    cout << "INVALID\n";
  return 0;
}
