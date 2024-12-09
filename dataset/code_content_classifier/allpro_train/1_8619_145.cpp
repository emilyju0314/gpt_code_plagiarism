#include <bits/stdc++.h>
using namespace std;
const int MAX = 505;
string table[MAX];
int comp[MAX][MAX], sum[MAX * MAX], n, k, nc = 1, sumBlock[MAX][MAX],
                                          visit[MAX * MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool ok(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < n && table[x][y] == '.' &&
      comp[x][y] == 0)
    return true;
  return false;
}
int sumOfBlock(int x1, int y1, int x2, int y2) {
  if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) return 0;
  int ans = sumBlock[x2][y2];
  if (y1 - 1 >= 0) ans -= sumBlock[x2][y1 - 1];
  if (x1 - 1 >= 0) ans -= sumBlock[x1 - 1][y2];
  if (x1 - 1 >= 0 && y1 - 1 >= 0) ans += sumBlock[x1 - 1][y1 - 1];
  return ans;
}
int sum_blocks(int x, int y) {
  int ans = 0;
  if (x > 0) ans += sumBlock[x - 1][y];
  if (y > 0) ans += sumBlock[x][y - 1];
  if (x > 0 && y > 0) ans -= sumBlock[x - 1][y - 1];
  return ans;
}
void fill(int x, int y, int val) {
  queue<int> q;
  q.push(x);
  q.push(y);
  comp[x][y] = val;
  int ans = 1;
  while (!q.empty()) {
    x = q.front();
    q.pop();
    y = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newx = dx[i] + x;
      int newy = dy[i] + y;
      if (ok(newx, newy)) {
        comp[newx][newy] = val;
        q.push(newx);
        q.push(newy);
        ans++;
      }
    }
  }
  sum[val] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> table[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sumBlock[i][j] = sum_blocks(i, j);
      if (table[i][j] == 'X') sumBlock[i][j]++;
      if (table[i][j] == '.' && comp[i][j] == 0) {
        fill(i, j, nc);
        nc++;
      }
    }
  }
  int ans = 0;
  vector<int> nei;
  for (int i = 0; i <= n - k; i++) {
    int cont = 0;
    for (int j = 0; j < nei.size(); j++) visit[nei[j]] = 0;
    nei.clear();
    for (int l = i - 1; l <= i + k && l < n; l++) {
      if (l < 0) l++;
      for (int m = 0; m <= k && m < n; m++) {
        if (m == k && (l == i - 1 || l == i + k)) continue;
        int c = comp[l][m];
        if (visit[c] == 0) {
          cont += sum[c];
          nei.push_back(c);
        }
        visit[c]++;
      }
    }
    int r = sumOfBlock(i, 0, i + k - 1, k - 1);
    ans = max(ans, cont + r);
    for (int j = 0; j < n - k; j++) {
      if (j + k + 1 < n) {
        for (int l = i; l < i + k && l < n; l++) {
          int c = comp[l][j + k + 1];
          if (visit[c] == 0) {
            cont += sum[c];
            nei.push_back(c);
          }
          visit[c]++;
        }
      }
      if (j - 1 >= 0) {
        for (int l = i; l < i + k && l < n; l++) {
          int c = comp[l][j - 1];
          visit[c]--;
          if (visit[c] == 0) {
            cont -= sum[c];
          }
        }
      }
      int c = 0;
      if (i - 1 >= 0) {
        c = comp[i - 1][j];
        visit[c]--;
      }
      if (visit[c] == 0) {
        cont -= sum[c];
      }
      c = comp[i + k][j];
      visit[c]--;
      if (visit[c] == 0) {
        cont -= sum[c];
      }
      c = 0;
      if (i - 1 >= 0) {
        c = comp[i - 1][j + k];
        if (visit[c] == 0) {
          cont += sum[c];
          nei.push_back(c);
        }
        visit[c]++;
      }
      c = comp[i + k][j + k];
      if (visit[c] == 0) {
        cont += sum[c];
        nei.push_back(c);
      }
      visit[c]++;
      r = sumOfBlock(i, j + 1, i + k - 1, j + k);
      ans = max(ans, cont + r);
    }
  }
  printf("%d", ans);
  return 0;
}
