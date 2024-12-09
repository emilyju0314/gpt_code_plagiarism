#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int A[1024][1024], MCOL[1024][1024], MROW[1024][1024];
long long dp[1024][1024];
bool vis[1024][1024];
vector<pair<long long, pair<int, int> > > v;
int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &A[i][j]);
      dp[i + 1][j + 1] = A[i][j];
    }
  }
  int k;
  for (int i = 0; i < n; i++) {
    deque<pair<int, int> > q;
    k = 0;
    for (int j = 0; j < b; j++) {
      while (!q.empty() && q.back().first >= A[i][j]) q.pop_back();
      q.push_back(make_pair(A[i][j], j));
    }
    MCOL[i][k++] = q.front().first;
    for (int j = b; j < m; j++) {
      while (!q.empty() && q.back().first >= A[i][j]) q.pop_back();
      q.push_back(make_pair(A[i][j], j));
      while (q.front().second <= j - b) q.pop_front();
      MCOL[i][k++] = q.front().first;
    }
  }
  for (int j = 0; j < m - b + 1; j++) {
    deque<pair<int, int> > q;
    k = 0;
    for (int i = 0; i < a; i++) {
      while (!q.empty() && q.back().first >= MCOL[i][j]) q.pop_back();
      q.push_back(make_pair(MCOL[i][j], i));
    }
    MROW[k++][j] = q.front().first;
    for (int i = a; i < n; i++) {
      while (!q.empty() && q.back().first >= MCOL[i][j]) q.pop_back();
      q.push_back(make_pair(MCOL[i][j], i));
      while (q.front().second <= i - a) q.pop_front();
      MROW[k++][j] = q.front().first;
    }
  }
  for (int i = 2; i <= m; i++) dp[1][i] += dp[1][i - 1];
  for (int i = 2; i <= n; i++) dp[i][1] += dp[i - 1][1];
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++)
      dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
  }
  for (int i = 0; i < n - a + 1; i++) {
    for (int j = 0; j < m - b + 1; j++) {
      long long val = dp[i + a][j + b] - dp[i + a][j] - dp[i][j + b] + dp[i][j];
      val -= 1ll * a * b * MROW[i][j];
      v.push_back(make_pair(val, make_pair(i, j)));
    }
  }
  sort(v.begin(), v.end());
  vector<pair<pair<int, int>, long long> > ans;
  for (int i = 0; i < v.size(); i++) {
    int x = v[i].second.first;
    int y = v[i].second.second;
    if (!vis[x][y]) {
      ans.push_back(make_pair(make_pair(x + 1, y + 1), v[i].first));
      for (int l = max(0, x - a + 1); l < x + a; l++) {
        for (int r = max(0, y - b + 1); r < y + b; r++) vis[l][r] = true;
      }
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d %I64d\n", ans[i].first.first, ans[i].first.second,
           ans[i].second);
  return 0;
}
