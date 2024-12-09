#include <bits/stdc++.h>
using namespace std;
char g[21][21];
int n, m, id[21][21], cv, cb, var[(1 << 8)],
    dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1}, d[21][21][(1 << 8)];
bool inq[21][21][(1 << 8)];
struct node {
  int r, c, msk;
};
queue<node> q;
vector<node> b;
void input() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n); i++) scanf("%s", g[i]);
  memset(id, -1, sizeof(id));
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++)
      if (isdigit(g[i][j])) id[i][j] = g[i][j] - '1', cv++;
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++)
      if (g[i][j] == 'B') id[i][j] = cv + (cb++);
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++) {
      if (g[i][j] == 'B') b.push_back((node){i, j, (1 << id[i][j] >> cv)});
      if (isdigit(g[i][j])) b.push_back((node){i, j, (1 << id[i][j] << cb)});
    }
  for (int i = 0; i < (cv); i++) scanf("%d", &var[1 << i]);
}
int lowbit(int x) { return x & (-x); }
void pretreat() {
  for (int i = 0; i < ((1 << 8)); i++)
    if (i) var[i] = var[i - lowbit(i)] + var[lowbit(i)];
}
bool invalid(node cur) {
  if (cur.r < 0 || cur.r >= n || cur.c < 0 || cur.c >= m) return true;
  if (id[cur.r][cur.c] != -1) return true;
  if (g[cur.r][cur.c] == '#') return true;
  return false;
}
void updata(node nxt, int x) {
  if (d[nxt.r][nxt.c][nxt.msk] == -1 || d[nxt.r][nxt.c][nxt.msk] > x) {
    d[nxt.r][nxt.c][nxt.msk] = x;
    if (!inq[nxt.r][nxt.c][nxt.msk]) {
      inq[nxt.r][nxt.c][nxt.msk] = 1;
      q.push(nxt);
    }
  }
}
int bfs() {
  memset(d, -1, sizeof(d));
  memset(inq, 0, sizeof(inq));
  node cur, nxt;
  int ans = 0;
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++)
      if (g[i][j] == 'S') {
        q.push((node){i, j, 0});
        d[i][j][0] = 0;
        inq[i][j][0] = 1;
        break;
      }
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    inq[cur.r][cur.c][cur.msk] = 0;
    if (g[cur.r][cur.c] == 'S' && ((cur.msk & ((1 << cb) - 1)) == 0))
      ans = max(ans, var[cur.msk >> cb] - d[cur.r][cur.c][cur.msk]);
    for (int i = 0; i < (4); i++) {
      nxt.r = cur.r + dr[i];
      nxt.c = cur.c + dc[i];
      if (invalid(nxt)) continue;
      if (i & 1) {
        nxt.msk = cur.msk;
        for (int j = 0; j < ((int)b.size()); j++) {
          if (i == 1) {
            if (b[j].r > nxt.r && b[j].c == nxt.c) nxt.msk ^= b[j].msk;
          } else {
            if (b[j].r > cur.r && b[j].c == cur.c) nxt.msk ^= b[j].msk;
          }
        }
      } else
        nxt.msk = cur.msk;
      updata(nxt, d[cur.r][cur.c][cur.msk] + 1);
    }
  }
  return ans;
}
int main() {
  input();
  pretreat();
  printf("%d\n", bfs());
  return 0;
}
