#include <bits/stdc++.h>
using namespace std;
int n, m;
int r1, c1, r2, c2;
char s[505][505];
bool dfs(int i, int j) {
  if (r2 == i && c2 == j && s[r2][c2] != '.') return 1;
  if (s[i][j] != '.') return 0;
  s[i][j] = 'X';
  return dfs(i + 1, j) || dfs(i - 1, j) || dfs(i, j + 1) || dfs(i, j - 1);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> s[i][j];
  cin >> r1 >> c1 >> r2 >> c2;
  s[r1][c1] = '.';
  if (dfs(r1, c1))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
