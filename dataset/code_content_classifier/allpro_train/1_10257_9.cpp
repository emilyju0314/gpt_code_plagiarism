#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
char G[27][27];
int hve[27][27], add[27][27];
int val[27];
int dist[27][27][1 << 8];
int n, m, cnt = 0;
int ans = 0;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int main() {
  int sx, sy;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", G + i);
    for (int j = 0; j < m; j++) {
      if (G[i][j] == 'B')
        hve[i][j] = 1 << (cnt++);
      else if (G[i][j] == 'S') {
        sx = i;
        sy = j;
        G[i][j] = '.';
      }
    }
  }
  for (int i = 0; i < cnt; i++) val[i] = -2007;
  int ncnt = cnt;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (G[i][j] >= '1' && G[i][j] <= '8') {
        hve[i][j] = 1 << (cnt + G[i][j] - '1');
        ncnt = max(ncnt, cnt + G[i][j] - '0');
      }
    }
  }
  for (int i = cnt; i < ncnt; i++) scanf("%d", val + i);
  cnt = ncnt;
  for (int i = 0; i < n; i++) {
    add[i][0] = hve[i][0];
    for (int j = 1; j < m; j++) {
      add[i][j] = add[i][j - 1] | hve[i][j];
    }
  }
  queue<pair<pair<int, int>, int> > q;
  memset(dist, -1, sizeof(dist));
  q.push(make_pair(make_pair(sx, sy), 0));
  dist[sx][sy][0] = 0;
  while (!q.empty()) {
    int x = q.front().first.first, y = q.front().first.second,
        msk = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x1 = x + dx[i], y1 = y + dy[i], msk1 = msk;
      if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || G[x1][y1] != '.') continue;
      if (i == 0) msk1 ^= add[x1][y1];
      if (i == 3) msk1 ^= add[x][y];
      if (dist[x1][y1][msk1] == -1) {
        dist[x1][y1][msk1] = dist[x][y][msk] + 1;
        q.push(make_pair(make_pair(x1, y1), msk1));
      }
    }
  }
  for (int i = 0; i < (1 << 8); i++) {
    if (dist[sx][sy][i] != -1) {
      int sum = 0;
      for (int j = 0; j < 8; j++)
        if ((i >> j) & 1) sum += val[j];
      ans = max(ans, sum - dist[sx][sy][i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
