#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1001;
const long long INF = 1e10;
int n, m, k, cur = 0;
vector<vector<bool>> visited(N, vector<bool>(N));
vector<vector<int>> ans(N, vector<int>(N));
vector<string> mat(N);
vector<int> x = {-1, 0, 1, 0}, y = {0, 1, 0, -1};
vector<pair<int, int>> temp;
void dfs(int i, int j) {
  visited[i][j] = true;
  temp.push_back({i, j});
  for (int c = 0; c < 4; c++)
    if (i + x[c] >= 0 and i + x[c] < n and j + y[c] >= 0 and j + y[c] < m and
        mat[i + x[c]][j + y[c]] == '*')
      cur++;
  for (int c = 0; c < 4; c++)
    if (i + x[c] >= 0 and i + x[c] < n and j + y[c] >= 0 and j + y[c] < m and
        mat[i + x[c]][j + y[c]] == '.' and !visited[i + x[c]][j + y[c]])
      dfs(i + x[c], j + y[c]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> mat[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '.' and !visited[i][j]) {
        cur = 0;
        temp.clear();
        dfs(i, j);
        for (auto i : temp) ans[i.first][i.second] = cur;
      }
    }
  }
  while (k--) {
    int i, j;
    cin >> i >> j;
    cout << ans[i - 1][j - 1] << '\n';
  }
}
