#include <bits/stdc++.h>
using namespace std;
const long long N = 502;
const long long M = 5e5 + 2;
const long long inf = 1e15 + 7;
struct robot {
  long long x, y, d, t, e;
  void init(long long _x, long long _y, long long _d, long long _t,
            long long _e) {
    x = _x, y = _y, d = _d, t = _t, e = _e;
  }
} trans[M];
vector<pair<long long, long long> > lis[N][N];
long long dp[2][2][N][N], dx[] = {0, 1, 1, 0}, dy[] = {0, -1, 0, 1}, cnt[2][N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, i, j, k, l, num, x, y, d, t, e, sum, id, tim;
  cin >> n >> m >> num;
  for (i = 1; i <= num; i++) {
    cin >> x >> y >> d >> t >> e;
    trans[i].init(x, y, d, t, e);
    lis[x][y].push_back({i, 0});
    lis[x + d][y - d].push_back({i, 1});
    lis[x + d][y].push_back({i, 2});
    lis[x][y + d].push_back({i, 3});
  }
  for (i = 0; i < 2; i++) {
    for (j = 0; j < m; j++) {
      for (k = 0; k <= n + 1; k++) {
        dp[1][i][j][k] = inf;
      }
      for (k = 0; k <= m + 1; k++) {
        dp[0][i][j][k] = inf;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      sum = 0;
      for (k = 1; k <= j + 1; k++) {
        cnt[0][k] = 0;
      }
      for (k = 1; k <= i + 1; k++) {
        cnt[1][k] = 0;
      }
      for (k = 0; k < lis[i][j].size(); k++) {
        id = lis[i][j][k].first;
        tim = lis[i][j][k].second;
        if (trans[id].t + tim > i + j ||
            (trans[id].t + tim) % 4 != (i + j) % 4) {
          continue;
        }
        sum += trans[id].e;
        for (l = 0; l < 4; l++) {
          if (l == tim) {
            continue;
          }
          x = trans[id].x + dx[l] * trans[id].d;
          y = trans[id].y + dy[l] * trans[id].d;
          if (x <= i && y <= j && (trans[id].t + l) <= (x + y) &&
              (trans[id].t + l) % 4 == (x + y) % 4) {
            if (x == i) {
              cnt[0][j - y] += trans[id].e;
            }
            if (y == j) {
              cnt[1][i - x] += trans[id].e;
            }
          }
        }
      }
      if (!i && !j) {
        dp[0][0][0][1] = dp[1][0][0][1] = sum;
        continue;
      }
      if (j) {
        for (k = 1; k <= j + 1; k++) {
          cnt[0][k] += cnt[0][k - 1];
          if (k == 1) {
            for (l = 0; l <= i + 1; l++) {
              dp[0][i & 1][j][1] = min(
                  dp[0][i & 1][j][1], dp[1][i & 1][j - 1][l] + sum - cnt[0][k]);
            }
          } else {
            dp[0][i & 1][j][k] =
                min(dp[0][i & 1][j][k],
                    dp[0][i & 1][j - 1][k - 1] + sum - cnt[0][k]);
          }
        }
      }
      if (i) {
        for (k = 1; k <= i + 1; k++) {
          cnt[1][k] += cnt[1][k - 1];
          if (k == 1) {
            for (l = 0; l <= j + 1; l++) {
              dp[1][i & 1][j][1] =
                  min(dp[1][i & 1][j][1],
                      dp[0][1 - (i & 1)][j][l] + sum - cnt[1][k]);
            }
          } else {
            dp[1][i & 1][j][k] =
                min(dp[1][i & 1][j][k],
                    dp[1][1 - (i & 1)][j][k - 1] + sum - cnt[1][k]);
          }
        }
      }
    }
    for (j = 0; j < m; j++) {
      for (k = 0; k <= m + 1; k++) {
        dp[0][1 - (i & 1)][j][k] = inf;
      }
      for (k = 0; k <= n + 1; k++) {
        dp[1][1 - (i & 1)][j][k] = inf;
      }
    }
  }
  long long ans = inf;
  for (i = 1; i <= n + 1; i++) {
    ans = min(ans, dp[1][(n - 1) & 1][m - 1][i]);
  }
  for (i = 1; i <= m + 1; i++) {
    ans = min(ans, dp[0][(n - 1) & 1][m - 1][i]);
  }
  cout << ans;
}
