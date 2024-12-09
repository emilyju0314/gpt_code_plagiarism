#include <bits/stdc++.h>
using namespace std;
int n, m;
string pw[51];
const string sp = "#*&";
int dp[51][8];
inline int min(int a, int b) { return a < b ? a : b; }
int main(void) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> pw[i];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 8; j++) dp[i][j] = 1987654321;
  for (int i = 0; i < n; i++) {
    int idx[3] = {-1, -1, -1};
    for (int j = 0; j <= m - j; j++) {
      if (j == 0 && pw[i][j] >= '0' && pw[i][j] <= '9') {
        idx[0] = j;
        break;
      } else if (pw[i][j] >= '0' && pw[i][j] <= '9' ||
                 pw[i][m - j] >= '0' && pw[i][m - j] <= '9') {
        idx[0] = j;
        break;
      }
    }
    for (int j = 0; j <= m - j; j++) {
      if (j == 0 && pw[i][j] >= 'a' && pw[i][j] <= 'z') {
        idx[1] = j;
        break;
      } else if (pw[i][j] >= 'a' && pw[i][j] <= 'z' ||
                 pw[i][m - j] >= 'a' && pw[i][m - j] <= 'z') {
        idx[1] = j;
        break;
      }
    }
    for (int j = 0; j <= m - j; j++) {
      if (j == 0 && sp.find(pw[i][j]) != string::npos) {
        idx[2] = j;
        break;
      } else if (sp.find(pw[i][j]) != string::npos ||
                 sp.find(pw[i][m - j]) != string::npos) {
        idx[2] = j;
        break;
      }
    }
    for (int j = 0; j < 7; j++) dp[i + 1][j] = dp[i][j];
    if (idx[0] != -1) {
      dp[i + 1][1] = idx[0];
      dp[i + 1][3] = min(dp[i + 1][3], dp[i][2] + idx[0]);
      dp[i + 1][5] = min(dp[i + 1][5], dp[i][4] + idx[0]);
      dp[i + 1][7] = min(dp[i + 1][7], dp[i][6] + idx[0]);
    }
    if (idx[1] != -1) {
      dp[i + 1][2] = idx[1];
      dp[i + 1][3] = min(dp[i + 1][3], dp[i][1] + idx[1]);
      dp[i + 1][6] = min(dp[i + 1][6], dp[i][4] + idx[1]);
      dp[i + 1][7] = min(dp[i + 1][7], dp[i][5] + idx[1]);
    }
    if (idx[2] != -1) {
      dp[i + 1][4] = idx[2];
      dp[i + 1][5] = min(dp[i + 1][5], dp[i][1] + idx[2]);
      dp[i + 1][6] = min(dp[i + 1][6], dp[i][2] + idx[2]);
      dp[i + 1][7] = min(dp[i + 1][7], dp[i][3] + idx[2]);
    }
  }
  cout << dp[n][7] << endl;
  return 0;
}
