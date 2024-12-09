#include <bits/stdc++.h>
using namespace std;
char a[55][55];
bool visited[55][55];
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y, int px = -1, int py = -1) {
  visited[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int new_x = x + dx[i], new_y = y + dy[i];
    if ((new_x == px) && (new_y == py)) continue;
    if (new_x == 0 || new_y == 0 || new_x > n || new_y > m) continue;
    if (a[new_x][new_y] != a[x][y]) continue;
    if (visited[new_x][new_y]) {
      cout << "Yes" << endl;
      exit(0);
    }
    dfs(new_x, new_y, x, y);
  }
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) visited[i][j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!visited[i][j]) dfs(i, j);
    }
  }
  printf("No\n");
  return 0;
}
