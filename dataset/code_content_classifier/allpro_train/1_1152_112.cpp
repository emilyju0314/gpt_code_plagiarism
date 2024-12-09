#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 501000;
const int INF = 0x3f3f3f3f;
vector<int> v[MAX_N], w[MAX_N];
struct skt {
  int x, y;
};
int dis[MAX_N][2];
int tox[MAX_N][2], toy[MAX_N][2];
int n;
int b[MAX_N];
void bfs() {
  int i;
  queue<int> q;
  skt t;
  memset(dis, INF, sizeof(dis));
  q.push(n);
  dis[n][0] = 0;
  dis[n][1] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (i = 0; i < v[x].size(); i++) {
      int y = v[x][i];
      int k = w[x][i];
      if (dis[y][k] > max(dis[x][0], dis[x][1]) + 1) {
        dis[y][k] = max(dis[x][0], dis[x][1]) + 1;
        q.push(y);
      }
    }
  }
}
int main(void) {
  int m, i, x, y, t;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &t);
    if (x == y) continue;
    v[y].push_back(x);
    w[y].push_back(t);
  }
  bfs();
  if (dis[1][0] == INF || dis[1][1] == INF)
    printf("-1\n");
  else
    printf("%d\n", max(dis[1][0], dis[1][1]));
  for (i = 1; i <= n; i++) {
    if (dis[i][0] > dis[i][1])
      b[i] = 0;
    else
      b[i] = 1;
    printf("%d", b[i]);
  }
  return 0;
}
