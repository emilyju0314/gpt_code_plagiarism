#include <bits/stdc++.h>
using namespace std;
int dp[51][51];
void dfs(vector<vector<char> > &a, long long i, long long j,
         vector<vector<bool> > &visited, bool &ans) {
  visited[i][j] = true;
  long long n = a.size();
  long long m = a[0].size();
  if (i == n - 1 && j == m - 1 && a[i][j] != '#') {
    dp[i][j] = 1;
    ans = true;
    return;
  }
  if (dp[i][j] == 0) {
    return;
  }
  if (dp[i][j] == 1) {
    ans = true;
    return;
  }
  if (i - 1 >= 0 && a[i - 1][j] != '#' && !visited[i - 1][j]) {
    dfs(a, i - 1, j, visited, ans);
    if (ans) {
      dp[i][j] = 1;
      return;
    }
  }
  if (i + 1 < n && a[i + 1][j] != '#' && !visited[i + 1][j]) {
    dfs(a, i + 1, j, visited, ans);
    if (ans) {
      dp[i][j] = 1;
      return;
    }
  }
  if (j - 1 >= 0 && a[i][j - 1] != '#' && !visited[i][j - 1]) {
    dfs(a, i, j - 1, visited, ans);
    if (ans) {
      dp[i][j] = 1;
      return;
    }
  }
  if (j + 1 < m && a[i][j + 1] != '#' && !visited[i][j + 1]) {
    dfs(a, i, j + 1, visited, ans);
    if (ans) {
      dp[i][j] = 1;
      return;
    }
  }
  if (ans) {
    dp[i][j] = 1;
    return;
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    vector<vector<char> > a(n, vector<char>(m, 'a'));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    bool ans = true;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (a[i][j] == '.') {
          if (i - 1 >= 0 && a[i - 1][j] == 'B')
            a[i][j] = '#';
          else if (i + 1 < n && a[i + 1][j] == 'B')
            a[i][j] = '#';
          else if (j - 1 >= 0 && a[i][j - 1] == 'B')
            a[i][j] = '#';
          else if (j + 1 < m && a[i][j + 1] == 'B')
            a[i][j] = '#';
        }
        if (a[i][j] == 'G') {
          if (i - 1 >= 0 && a[i - 1][j] == 'B') {
            ans = false;
            break;
          } else if (i + 1 < n && a[i + 1][j] == 'B') {
            ans = false;
            break;
          } else if (j - 1 >= 0 && a[i][j - 1] == 'B') {
            ans = false;
            break;
          } else if (j + 1 < m && a[i][j + 1] == 'B') {
            ans = false;
            break;
          }
        }
      }
    }
    if (!ans) {
      cout << "No" << endl;
      continue;
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (a[i][j] == 'G') {
          vector<vector<bool> > visited(n, vector<bool>(m, false));
          bool curAns = false;
          if (dp[i][j] != 1) {
            dfs(a, i, j, visited, curAns);
          } else if (dp[i][j] == 1) {
            curAns = true;
          }
          if (!curAns) {
            ans = false;
            break;
          }
        }
      }
      if (!ans) break;
    }
    if (ans)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
