#include <bits/stdc++.h>
using namespace std;
char Map[105][105];
int vis[105][105][105];
bool judge(int i, int k, int j) {
  for (int a = 0; a < j; a++) {
    if (vis[i][k][a]) return true;
  }
  return false;
}
int n, m;
void Clear(int j) {
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      vis[i][k][j] = 0;
    }
  }
}
int main() {
  while (cin >> n >> m) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> Map[i][j];
      }
    }
    int ans = 0;
    for (int j = 0; j < m; j++) {
      int flag = 0;
      for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
          if (Map[i][j] == Map[k][j]) {
            if (j == m - 1) vis[i][k][j] = 1;
            continue;
          }
          if (Map[i][j] > Map[k][j] && !judge(i, k, j)) {
            Clear(j);
            flag = 1;
            break;
          } else if (Map[i][j] < Map[k][j]) {
            vis[i][k][j] = 1;
          }
        }
        if (flag) break;
      }
      ans += flag;
    }
    cout << ans << endl;
  }
  return 0;
}
