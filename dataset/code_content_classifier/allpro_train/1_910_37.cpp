#include <bits/stdc++.h>
using namespace std;
void chkmax(int &a, int b) {
  if (a < b) a = b;
}
int n, l, m, T, cnt, hubo, nT;
int a[105], b[105], dp[105][105][3], w[105][105], dist[105][105][30],
    ans[105][30], c[30], id[105];
bool vis[305], flag;
void calc_w() {
  for (int k = 0; k <= n; k++) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (i > j || !k)
          dp[i][j][k & 1] = 0;
        else if (id[k] > j || id[k] < i)
          dp[i][j][k & 1] = dp[i][j][(k - 1) & 1];
        else
          dp[i][j][k & 1] =
              max(dp[i][j][(k - 1) & 1], dp[i][id[k]][(k - 1) & 1] + 1);
      }
    }
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) {
      w[i][j] = dp[i][j][n & 1];
    }
}
void calc_dist() {
  for (int k = 0; k <= 25; k++) {
    for (int i = 0; i < m; i++) {
      for (int j = i; j < m; j++) {
        if (!k)
          dist[i][j][k] = w[i][j];
        else {
          for (int r = i; r <= j; r++) {
            chkmax(dist[i][j][k], dist[i][r][k - 1] + dist[r][j][k - 1]);
          }
        }
      }
    }
  }
}
void calc_ans() {
  for (int i = 0; i <= l; i++) {
    for (int j = 0; j < m; j++) {
      if (!i)
        ans[j][i] = 0;
      else {
        if (!c[i - 1])
          ans[j][i] = ans[j][i - 1];
        else {
          for (int k = 0; k <= j; k++) {
            chkmax(ans[j][i], ans[k][i - 1] + dist[k][j][i - 1]);
          }
        }
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &T);
  nT = T, l = 0;
  while (nT) {
    c[l++] = nT & 1;
    nT /= 2;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    vis[a[i]] = 1;
  }
  for (int i = 1; i <= 300; i++) {
    if (vis[i]) b[m++] = i;
  }
  for (int i = 1; i <= n; i++) {
    flag = 0;
    for (int j = 0; j < m && !flag; j++) {
      if (a[i] == b[j]) id[i] = j, flag = 1;
    }
  }
  calc_w();
  calc_dist();
  calc_ans();
  printf("%d", ans[m - 1][l]);
}
