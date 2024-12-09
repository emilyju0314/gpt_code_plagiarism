#include <bits/stdc++.h>
using namespace std;
int n, m, t, c;
string A[1000000];
int X1, X2, Y1, Y2;
set<pair<int, int> > B;
int dx[] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
bool ok(int x, int y) { return (x >= 0 && y >= 0 && x < n && y < m); }
void dfs(int x, int y) {
  B.insert(make_pair(x, y));
  c++;
  X1 = min(X1, x);
  Y1 = min(Y1, y);
  X2 = max(X2, x);
  Y2 = max(Y2, y);
  for (int i = 0; i < 8; i++) {
    int tx = x + dx[i], ty = y + dy[i];
    if (!ok(tx, ty)) continue;
    if (A[tx][ty] != '1') continue;
    if (B.find(make_pair(tx, ty)) == B.end()) dfs(tx, ty);
  }
}
bool F1() {
  if (!(X2 - X1 == Y2 - Y1)) return false;
  int l = X2 - X1;
  if (l < 1) return false;
  if (c != l * 4) return false;
  for (int i = X1; i < X1 + l + 1; i++)
    if (A[i][Y1] == '0') return false;
  for (int i = X1; i < X1 + l + 1; i++)
    if (A[i][Y2] == '0') return false;
  for (int i = Y1; i < Y1 + l + 1; i++)
    if (A[X1][i] == '0') return false;
  for (int i = Y1; i < Y1 + l + 1; i++)
    if (A[X2][i] == '0') return false;
  return true;
}
bool F2() {
  if ((X2 - X1) % 2 != 0) return false;
  if (!(X2 - X1 == Y2 - Y1)) return false;
  int l = (X2 - X1) / 2;
  if (l < 1) return false;
  if (c != l * 4) return false;
  int y = (Y1 + Y2) / 2, x = X1;
  for (int i = 0; i < l + 1; i++) {
    if (!ok(x, y)) return false;
    if (A[x][y] == '0') return false;
    x++;
    y++;
  }
  y = (Y1 + Y2) / 2, x = X1;
  for (int i = 0; i < l + 1; i++) {
    if (!ok(x, y)) return false;
    if (A[x][y] == '0') return false;
    x++;
    y--;
  }
  y = (Y1 + Y2) / 2, x = X2;
  for (int i = 0; i < l + 1; i++) {
    if (!ok(x, y)) return false;
    if (A[x][y] == '0') return false;
    x--;
    y--;
  }
  y = (Y1 + Y2) / 2, x = X2;
  for (int i = 0; i < l + 1; i++) {
    if (!ok(x, y)) return false;
    if (A[x][y] == '0') return false;
    x--;
    y++;
  }
  return true;
}
int main() {
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) cin >> A[i];
    B.clear();
    int res = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (A[i][j] == '1' && B.find(make_pair(i, j)) == B.end()) {
          c = 0;
          X1 = 1000001000, Y1 = 1000001000, X2 = 0, Y2 = 0;
          dfs(i, j);
          if (F1() || F2()) res++;
        }
    printf("%d\n", res);
  }
  return 0;
}
