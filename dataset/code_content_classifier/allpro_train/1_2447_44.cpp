#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, t;
  cin >> n >> m >> t;
  string A[n];
  for (long long i = 0; i < n; i++) cin >> A[i];
  queue<pair<long long, long long> > q;
  long long ans[n][m];
  memset(ans, -1, sizeof(ans));
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      bool flag = 0;
      if (i > 0 && A[i][j] == A[i - 1][j]) flag = 1;
      if (j > 0 && A[i][j] == A[i][j - 1]) flag = 1;
      if (i < n - 1 && A[i][j] == A[i + 1][j]) flag = 1;
      if (j < m - 1 && A[i][j] == A[i][j + 1]) flag = 1;
      if (flag) {
        q.push({i, j});
        ans[i][j] = 1;
      }
    }
  while (!q.empty()) {
    pair<long long, long long> curr = q.front();
    long long i = curr.first;
    long long j = curr.second;
    q.pop();
    if (i > 0 && ans[i - 1][j] == -1) {
      q.push({i - 1, j});
      ans[i - 1][j] = ans[i][j] + 1;
    }
    if (j > 0 && ans[i][j - 1] == -1) {
      q.push({i, j - 1});
      ans[i][j - 1] = ans[i][j] + 1;
    }
    if (j < m - 1 && ans[i][j + 1] == -1) {
      q.push({i, j + 1});
      ans[i][j + 1] = ans[i][j] + 1;
    }
    if (i < n - 1 && ans[i + 1][j] == -1) {
      q.push({i + 1, j});
      ans[i + 1][j] = ans[i][j] + 1;
    }
  }
  while (t--) {
    long long i, j, p;
    cin >> i >> j >> p;
    i--;
    j--;
    if (ans[i][j] == -1) {
      cout << A[i][j] - '0' << endl;
      continue;
    }
    if (p < ans[i][j])
      cout << A[i][j] - '0' << endl;
    else {
      p = p - ans[i][j] + 1;
      if (p % 2)
        cout << '1' - A[i][j] << endl;
      else
        cout << A[i][j] - '0' << endl;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
