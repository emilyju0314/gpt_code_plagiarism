#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500;
bool used[MAXN][MAXN];
int comp[MAXN][MAXN];
char s[MAXN][MAXN];
int n;
int pref[MAXN + 1][MAXN + 1];
int sz[MAXN * MAXN];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};
void dfs(int x, int y, int cc) {
  used[x][y] = true;
  comp[x][y] = cc;
  sz[cc]++;
  for (int d = 0; d < 4; d++) {
    int xx = x + dx[d];
    int yy = y + dy[d];
    if (0 <= xx && xx < n && 0 <= yy && yy < n && !used[xx][yy] &&
        s[xx][yy] == '.') {
      dfs(xx, yy, cc);
    }
  }
}
int main() {
  int k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string ss;
    cin >> ss;
    for (int j = 0; j < n; j++) {
      s[i][j] = ss[j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      comp[i][j] = -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
      if (s[i - 1][j - 1] == 'X') {
        pref[i][j]++;
      }
    }
  }
  int cc = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!used[i][j] && s[i][j] == '.') {
        dfs(i, j, cc++);
      }
    }
  }
  int best = 0;
  for (int i = 0; i + k <= n; i++) {
    vector<int> cnt(cc);
    int nn = 0;
    for (int ii = 0; ii < k; ii++) {
      for (int jj = 0; jj < k; jj++) {
        int cur = comp[i + ii][jj];
        if (cur != -1) {
          if (cnt[cur] == 0) {
            nn += sz[cur];
          }
          cnt[cur]++;
        }
      }
    }
    for (int ii = i; ii < i + k; ii++) {
      if (k < n) {
        int cur = comp[ii][k];
        if (cur != -1) {
          if (cnt[cur] == 0) {
            nn += sz[cur];
          }
          cnt[cur]++;
        }
      }
    }
    for (int jj = 0; jj < k; jj++) {
      if (i - 1 >= 0) {
        int cur = comp[i - 1][jj];
        if (cur != -1) {
          if (cnt[cur] == 0) {
            nn += sz[cur];
          }
          cnt[cur]++;
        }
      }
      if (i + k < n) {
        int cur = comp[i + k][jj];
        if (cur != -1) {
          if (cnt[cur] == 0) {
            nn += sz[cur];
          }
          cnt[cur]++;
        }
      }
    }
    for (int j = 0; j + k <= n; j++) {
      best = max(best, pref[i + k][j + k] - pref[i + k][j] - pref[i][j + k] +
                           pref[i][j] + nn);
      if (j - 1 >= 0) {
        for (int ii = i; ii < i + k; ii++) {
          int cur = comp[ii][j - 1];
          if (cur != -1) {
            if (cnt[cur] == 1) {
              nn -= sz[cur];
            }
            cnt[cur]--;
          }
        }
      }
      if (j + k + 1 < n) {
        for (int ii = i; ii < i + k; ii++) {
          int cur = comp[ii][j + k + 1];
          if (cur != -1) {
            if (cnt[cur] == 0) {
              nn += sz[cur];
            }
            cnt[cur]++;
          }
        }
      }
      if (i - 1 >= 0 && j + k < n) {
        int cur = comp[i - 1][j + k];
        if (cur != -1) {
          if (cnt[cur] == 0) {
            nn += sz[cur];
          }
          cnt[cur]++;
        }
      }
      if (i + k < n && j + k < n) {
        int cur = comp[i + k][j + k];
        if (cur != -1) {
          if (cnt[cur] == 0) {
            nn += sz[cur];
          }
          cnt[cur]++;
        }
      }
      if (i - 1 >= 0) {
        int cur = comp[i - 1][j];
        if (cur != -1) {
          if (cnt[cur] == 1) {
            nn -= sz[cur];
          }
          cnt[cur]--;
        }
      }
      if (i + k < n) {
        int cur = comp[i + k][j];
        if (cur != -1) {
          if (cnt[cur] == 1) {
            nn -= sz[cur];
          }
          cnt[cur]--;
        }
      }
    }
  }
  cout << best << endl;
  return 0;
}
