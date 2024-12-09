#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5;
int tot, k, m, n, a[55][55], vis[55][55], p[MaxN + 5];
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};
char s[55][55];
struct op {
  int c, num;
} sum[MaxN + 5];
bool cmp(op x, op y) { return x.c < y.c; }
int Check(int x, int y) {
  if (vis[x][y] == 1) return 0;
  if (s[x][y] != '.') return 0;
  if (a[x][y] == -1) return 0;
  return 1;
}
void Pan(int x, int y) {
  for (int i = 1; i <= 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (s[xx][yy] == '.' && vis[xx][yy] != 1) {
      vis[xx][yy] = 1;
      a[xx][yy] = -1;
      Pan(xx, yy);
    }
  }
}
void yu() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1 || i == n || j == 1 || j == m) {
        if (s[i][j] == '.' && vis[i][j] != 1) {
          vis[i][j] = 1;
          a[i][j] = -1;
          Pan(i, j);
        }
      }
    }
  }
}
void Bfs(int x, int y, int num) {
  for (int i = 1; i <= 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (Check(xx, yy) == 1) {
      vis[xx][yy] = 1;
      tot++;
      a[xx][yy] = num;
      Bfs(xx, yy, num);
    }
  }
}
void pdo() {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (Check(i, j) == 1) {
        vis[i][j] = 1;
        a[i][j] = cnt + 1;
        tot = 1;
        Bfs(i, j, cnt + 1);
        sum[++cnt].c = tot;
        sum[cnt].num = cnt;
      }
    }
  }
  int ans = 0;
  sort(sum + 1, sum + cnt + 1, cmp);
  for (int i = 1; i <= cnt - k; i++) {
    ans += sum[i].c;
    p[sum[i].num] = 1;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (p[a[i][j]] == 1)
        printf("*");
      else
        printf("%c", s[i][j]);
    }
    printf("\n");
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  yu();
  memset(vis, 0, sizeof(vis));
  pdo();
}
