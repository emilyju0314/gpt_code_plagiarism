#include <bits/stdc++.h>
using namespace std;
int n, m, g1, g2, s1, s2;
vector<vector<int>> d;
vector<vector<vector<long long>>> dp;
void floyd() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
      }
    }
  }
}
void make_list() {
  for (auto& v : d) {
    sort(v.begin(), v.end());
  }
}
bool canup(int x, int y) {
  return d[x][1] < d[y][1] || (d[x][1] == d[y][1] && x <= y);
}
bool candown(int x, int y) {
  return d[x][n - 1] > d[y][n - 1] || (d[x][n - 1] == d[y][n - 1] && x >= y);
}
bool between(int z, int x, int y) {
  int it;
  if (z > x) {
    it = lower_bound(d[z].begin() + 1, d[z].end(), d[x][1]) - d[z].begin();
  } else {
    it = upper_bound(d[z].begin() + 1, d[z].end(), d[x][1]) - d[z].begin();
  }
  if (it == d[z].size()) {
    return false;
  }
  return d[z][it] < d[y][n - 1] || (d[z][it] == d[y][n - 1] && z < y);
}
long long count(int gl, int bf) {
  if (d[gl][1] > d[bf][n - 1] || (d[gl][1] == d[bf][n - 1] && gl > bf)) {
    return 0;
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int g = 0; g <= i; g++) {
      for (int s = 0; s <= i - g; s++) {
        dp[i][g][s] = 0;
        if (i - 1 != bf && g > 0 && canup(i - 1, gl)) {
          dp[i][g][s] += dp[i - 1][g - 1][s];
        }
        if (i - 1 != gl && g + s < i && candown(i - 1, bf)) {
          dp[i][g][s] += dp[i - 1][g][s];
        }
        if (s > 0 && (i - 1 != bf && i - 1 != gl) && between(i - 1, gl, bf)) {
          dp[i][g][s] += dp[i - 1][g][s - 1];
        }
      }
    }
  }
  long long res = 0;
  for (int g = g1; g <= g2; g++)
    for (int s = s1; s <= s2; s++) res += dp[n][g][s];
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  const long long max = 1000 * 1000 + 1;
  d = vector<vector<int>>(n);
  for (auto& v : d) {
    v = vector<int>(n, max);
  }
  for (int i = 0; i < n; i++) {
    d[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    d[a][b] = d[b][a] = c;
  }
  floyd();
  make_list();
  cin >> g1 >> g2 >> s1 >> s2;
  dp = vector<vector<vector<long long>>>(n + 1);
  for (auto& vec : dp) {
    vec = vector<vector<long long>>(n + 1);
    for (auto& v : vec) {
      v = vector<long long>(n + 1, 0);
    }
  }
  long long ans = 0;
  for (int gl = 0; gl < n; gl++) {
    for (int bf = 0; bf < n; bf++) {
      if (gl != bf) {
        ans += count(gl, bf);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
