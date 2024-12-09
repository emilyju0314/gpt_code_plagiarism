#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, c, f;
} Now, Next, s;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int vis[55][55];
char mp[55][55];
int n, m;
int check(int tx, int ty) {
  if (tx >= 0 && tx < n && ty >= 0 && ty < m && mp[tx][ty] == 'B') return 1;
  return 0;
}
int bfs(int x, int y) {
  memset(vis, 0, sizeof(vis));
  int ret = 1, k;
  s = (node){x, y, 0, -1};
  vis[x][y] = 1;
  queue<node> q;
  q.push(s);
  while (!q.empty()) {
    Now = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      Next.x = Now.x + dir[i][0];
      Next.y = Now.y + dir[i][1];
      Next.c = Now.c;
      if (Now.f == -1)
        Next.f = i;
      else if (Next.f != i)
        Next.f = i, Next.c = Now.c + 1;
      else
        Next.f = Now.f;
      while (check(Next.x, Next.y) && Next.c < 2) {
        if (!vis[Next.x][Next.y]) {
          vis[Next.x][Next.y] = 1;
          ret++;
          q.push(Next);
        }
        Next.x += dir[i][0];
        Next.y += dir[i][1];
      }
    }
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", mp[i]);
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mp[i][j] == 'B') cnt++;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == 'B') {
        if (bfs(i, j) != cnt) return puts("NO"), 0;
      }
    }
  }
  puts("YES");
}
