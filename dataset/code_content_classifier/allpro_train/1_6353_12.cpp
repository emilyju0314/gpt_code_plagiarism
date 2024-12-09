#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
bool mark[N][N];
int t[N][N][4];
int n, a[N][N], xs, ys;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char s[] = {'D', 'U', 'R', 'L'};
string ans;
void dfs(int x, int y) {
  mark[x][y] = true;
  if (a[x][y] == 0) {
    a[x][y] = 1;
    ans.push_back('1');
    for (int k = 0; k < x; k++) t[k][y][0]++;
    for (int k = x + 1; k < n; k++) t[k][y][1]++;
    for (int k = 0; k < y; k++) t[x][k][2]++;
    for (int k = y + 1; k < n; k++) t[x][k][3]++;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || ny < 0 || nx >= n || ny >= n || mark[nx][ny] || !t[x][y][i])
      continue;
    ans.push_back(s[i]);
    dfs(nx, ny);
    if (i == 0) ans.push_back(s[1]);
    if (i == 1) ans.push_back(s[0]);
    if (i == 2) ans.push_back(s[3]);
    if (i == 3) ans.push_back(s[2]);
  }
  ans.push_back('2');
  for (int k = 0; k < x; k++) t[k][y][0]--;
  for (int k = x + 1; k < n; k++) t[k][y][1]--;
  for (int k = 0; k < y; k++) t[x][k][2]--;
  for (int k = y + 1; k < n; k++) t[x][k][3]--;
}
int main() {
  cin >> n;
  cin >> xs >> ys;
  xs--, ys--;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 1) {
        for (int k = 0; k < i; k++) t[k][j][0]++;
        for (int k = i + 1; k < n; k++) t[k][j][1]++;
        for (int k = 0; k < j; k++) t[i][k][2]++;
        for (int k = j + 1; k < n; k++) t[i][k][3]++;
      }
    }
  }
  dfs(xs, ys);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (a[i][j] && !mark[i][j]) return cout << "NO\n", 0;
    }
  cout << "YES\n";
  cout << ans << "\n";
}
