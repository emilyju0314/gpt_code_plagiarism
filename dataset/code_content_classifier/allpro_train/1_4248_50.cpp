#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e5 + 10;
const long long int mod = 1e9 + 7;
const long long int infi = LLONG_MAX;
long long int ans, k, n, x, y, m, mymax = LLONG_MIN, mymin = LLONG_MAX, b, c, z,
                                  sum;
vector<long long int> v[M];
long long int a[M];
queue<long long int> pos;
long long int dp[M][6], flag[M];
void back_track(long long int index, long long int finger = 0) {
  long long int j = 0;
  if (finger == 0) {
    for (j = 1; j < 6; j++) {
      if (dp[index][j] != -1) {
        finger = j;
        break;
      }
    }
  }
  if (index == 1) {
    printf("%lld ", finger);
    return;
  }
  if (a[index] > a[index - 1]) {
    for (j = 1; j < finger; j++) {
      if (dp[index - 1][j] != -1) break;
    }
  } else if (a[index] == a[index - 1]) {
    for (j = 1; j < 6; j++)
      if (j != finger && dp[index - 1][j] != -1) break;
  } else
    for (j = 5; j > finger; j--)
      if (dp[index - 1][j] != -1) break;
  back_track(index - 1, j);
  printf("%lld ", finger);
}
int main() {
  long long int i, j;
  scanf("%lld", &n);
  for (i = 1; i < n + 1; i++) {
    scanf("%lld", &a[i]);
  }
  for (i = 2; i < n + 1; i++) {
    for (j = 1; j < 6; j++) {
      dp[i][j] = -1;
      if (a[i] > a[i - 1]) {
        for (k = j - 1; k > 0; k--) dp[i][j] = max(dp[i - 1][k], dp[i][j]);
      } else if (a[i] == a[i - 1]) {
        for (k = 1; k < 6; k++) {
          if (j != k) dp[i][j] = max(dp[i - 1][k], dp[i][j]);
        }
      } else {
        for (k = j + 1; k < 6; k++) dp[i][j] = max(dp[i - 1][k], dp[i][j]);
      }
    }
  }
  bool is_possible = false;
  for (j = 1; j < 6; j++)
    if (dp[n][j] != -1) is_possible = true;
  if (!is_possible) {
    printf("%s", "-1\n");
    return 0;
  }
  back_track(n);
  return 0;
}
