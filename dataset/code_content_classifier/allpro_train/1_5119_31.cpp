#include <bits/stdc++.h>
int n, m, k;
long long c[505][505];
std::vector<std::pair<int, int> > lef[505][505], up[505][505];
long long dp[2][2][505][505];
long long best[2][505][505];
const long long INF = 1000000000ll * 1000000000ll;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> m >> k;
  std::swap(n, m);
  for (int i = 0; i < (k); ++i) {
    int x, y, d, t, e;
    std::cin >> x >> y >> d >> t >> e;
    int time = x + y;
    bool fs = false, sc = false;
    if (time >= t && time % 4 == t % 4) {
      c[y + 1][x + 1] += e;
      fs = true;
    }
    if (time >= t + 1 && time % 4 == (t + 1) % 4) {
      c[y - d + 1][x + d + 1] += e;
      sc = true;
    }
    int time2 = x + y + d;
    if (time2 >= t + 2 && time2 % 4 == (t + 2) % 4) {
      c[y + 1][x + d + 1] += e;
      if (fs && d % 4 == 2) {
        lef[y + 1][x + d + 1].push_back(std::make_pair(d, e));
      }
      if (sc && d % 4 == 1) {
        up[y + 1][x + d + 1].push_back(std::make_pair(d, e));
      }
    }
    if (time2 >= t + 3 && time2 % 4 == (t + 3) % 4) {
      c[y + d + 1][x + 1] += e;
      if (fs && d % 4 == 3) {
        up[y + d + 1][x + 1].push_back(std::make_pair(d, e));
      }
    }
  }
  for (int i = 0; i < (n + 1); ++i)
    for (int j = 0; j < (m + 1); ++j)
      std::sort(lef[i][j].begin(), lef[i][j].end(),
                std::greater<std::pair<int, int> >()),
          std::sort(up[i][j].begin(), up[i][j].end(),
                    std::greater<std::pair<int, int> >());
  int MX = std::max(n, m);
  for (int xd = 0; xd < (2); ++xd)
    for (int j = 0; j < (m + 1); ++j)
      for (int x = 0; x < (MX + 1); ++x) dp[xd][0][j][x] = INF;
  for (int xd = 0; xd < (2); ++xd)
    for (int i = 0; i < (n + 1); ++i)
      for (int j = 0; j < (m + 1); ++j) best[xd][i][j] = INF;
  for (int xd = 0; xd < (2); ++xd) best[xd][1][1] = c[1][1];
  for (int i = (1); i < (n + 1); ++i) {
    int ind = i & 1;
    for (int xd = 0; xd < (2); ++xd)
      for (int j = 0; j < (m + 1); ++j)
        for (int x = 0; x < (MX + 1); ++x) dp[xd][ind][j][x] = INF;
    for (int j = (1); j < (m + 1); ++j) {
      if (i == 1 && j == 1) continue;
      long long min = 0;
      while ((int)(lef[i][j]).size() && lef[i][j].back().first <= 1)
        min += lef[i][j].back().second, lef[i][j].pop_back();
      dp[0][ind][j][1] =
          std::min(dp[0][ind][j][1], best[1][i][j - 1] - min + c[i][j]);
      best[0][i][j] = std::min(best[0][i][j], dp[0][ind][j][1]);
      for (int x = (2); x < (MX + 1); ++x) {
        while ((int)(lef[i][j]).size() && lef[i][j].back().first <= x)
          min += lef[i][j].back().second, lef[i][j].pop_back();
        dp[0][ind][j][x] = std::min(dp[0][ind][j - 1][x - 1] - min + c[i][j],
                                    dp[0][ind][j][x]);
        best[0][i][j] = std::min(best[0][i][j], dp[0][ind][j][x]);
      }
      min = 0;
      while ((int)(up[i][j]).size() && up[i][j].back().first <= 1)
        min += up[i][j].back().second, up[i][j].pop_back();
      dp[1][ind][j][1] =
          std::min(dp[1][ind][j][1], best[0][i - 1][j] - min + c[i][j]);
      best[1][i][j] = std::min(best[1][i][j], dp[1][ind][j][1]);
      for (int x = (2); x < (MX + 1); ++x) {
        while ((int)(up[i][j]).size() && up[i][j].back().first <= x)
          min += up[i][j].back().second, up[i][j].pop_back();
        dp[1][ind][j][x] = std::min(dp[1][ind ^ 1][j][x - 1] - min + c[i][j],
                                    dp[1][ind][j][x]);
        best[1][i][j] = std::min(best[1][i][j], dp[1][ind][j][x]);
      }
    }
  }
  std::cout << std::min(best[0][n][m], best[1][n][m]) << "\n";
  return 0;
}
