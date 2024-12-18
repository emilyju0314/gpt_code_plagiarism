#include <bits/stdc++.h>
struct tpl {
  int r, a, b;
};
std::string s[501];
std::pair<int, int> rx[501];
int memo[502][27][27];
tpl par[502][27][27];
int n, m;
int main(void) {
  std::cin >> n >> m;
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= 26; j++) {
      for (int k = 0; k <= 26; k++) {
        memo[i][j][k] = 100000000;
        par[i][j][k] = {i, j, k};
      }
    }
  }
  for (int i = 1; i <= n; i++) std::cin >> s[i];
  for (int i = 0; i <= 26; i++) {
    for (int j = 0; j <= 26; j++) memo[n + 1][i][j] = 0;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= 26; j++) {
      for (int k = 1; k <= 26; k++) {
        if (j != k) {
          int d = 0;
          for (int t = 0; t < m; t++) {
            if (t & 1) {
              if ((s[i][t] - 'a') != k - 1) d++;
            } else {
              if ((s[i][t] - 'a') != j - 1) d++;
            }
          }
          if (m == 1) {
            for (int a = 1; a <= 26; a++) {
              if (j != a) {
                if (d + memo[i + 1][a][0] < memo[i][j][0]) {
                  memo[i][j][0] =
                      std::min(memo[i][j][0], d + memo[i + 1][a][0]);
                  par[i][j][0] = {i + 1, a, 0};
                }
              }
            }
          } else {
            for (int a = 1; a <= 26; a++) {
              for (int b = 1; b <= 26; b++) {
                if (a != b && j != a && k != b) {
                  if (d + memo[i + 1][a][b] < memo[i][j][k]) {
                    memo[i][j][k] =
                        std::min(memo[i][j][k], d + memo[i + 1][a][b]);
                    par[i][j][k] = {i + 1, a, b};
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  for (int j = 0; j <= 26; j++) {
    for (int k = 0; k <= 26; k++) {
      if (j != k) {
        if (m == 1) {
          if (memo[1][j][0] < memo[0][0][0]) {
            memo[0][0][0] = memo[1][j][0];
            par[0][0][0] = {1, j, 0};
          }
        } else {
          if (memo[1][j][k] < memo[0][0][0]) {
            memo[0][0][0] = memo[1][j][k];
            par[0][0][0] = {1, j, k};
          }
        }
      }
    }
  }
  std::cout << memo[0][0][0] << "\n";
  int r = 0, a = 0, b = 0;
  while (par[r][a][b].r != n + 1) {
    tpl x = par[r][a][b];
    rx[x.r] = std::make_pair(x.a, x.b);
    r = x.r;
    a = x.a;
    b = x.b;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j & 1)
        std::cout << (char)(rx[i].first - 1 + 'a');
      else
        std::cout << (char)(rx[i].second - 1 + 'a');
    }
    std::cout << "\n";
  }
  return 0;
}
