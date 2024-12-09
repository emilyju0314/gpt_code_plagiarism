#include <bits/stdc++.h>
using namespace std;
const int MAX = 110;
pair<int, int> a[MAX], b[MAX];
int now[MAX][MAX], chk[MAX][MAX], fin[MAX][MAX], prow, n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, rec[MAX];
vector<pair<int, int> > mv1, mv2;
queue<pair<int, int> > bfs;
int clear_chk() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) chk[i][j] = 0;
}
int mvrec(int x1, int y1, int x2, int y2) {
  if (!((now[x1][y1] == 0) ^ (now[x2][y2] == 0))) {
    return 0;
  }
  mv1.push_back(make_pair(x1, y1)), mv2.push_back(make_pair(x2, y2));
  swap(now[x1][y1], now[x2][y2]);
  return 1;
}
int print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d", fin[i][j]);
    printf("\n");
  }
  printf("\n");
}
void swt(int first, int second) {
  if (first == second) return;
  if (first > second) swap(first, second);
  if (second - first == 1) {
    mvrec(1, first, 2, first);
    mvrec(1, second, 1, first);
    mvrec(2, first, 2, second);
    mvrec(2, second, 1, second);
  } else {
    mvrec(1, first, 2, first);
    mvrec(1, second, 2, second);
    mvrec(2, second, 3, second);
    for (int i = first; i < second; i++) mvrec(2, i, 2, i + 1);
    for (int i = second; i > first; i--) mvrec(3, i, 3, i - 1);
    mvrec(3, first, 2, first), mvrec(2, first, 1, first);
    mvrec(2, second, 1, second);
  }
}
int build_bfs(pair<int, int> u) {
  clear_chk();
  bfs.push(u);
  for (int i = 1; !bfs.empty(); i++) {
    int t = bfs.size();
    for (int j = 0; j < t; j++) {
      pair<int, int> tmp = bfs.front();
      bfs.pop();
      if (chk[tmp.first][tmp.second] == 0) {
        chk[tmp.first][tmp.second] = i;
        if (now[tmp.first][tmp.second] == 0) {
          for (int k = 0; k < 4; k++) {
            int tx = tmp.first + dx[k], ty = tmp.second + dy[k];
            if (1 <= tx && tx <= n && 1 <= ty && ty <= n)
              bfs.push(make_pair(tx, ty));
          }
        }
      }
    }
  }
}
void track(pair<int, int> src, pair<int, int> dst) {
  if (src == dst) return;
  for (int k = 0; k < 4; k++) {
    int tx = dst.first + dx[k], ty = dst.second + dy[k];
    if (1 <= tx && tx <= n && 1 <= ty && ty <= n)
      if (chk[dst.first][dst.second] == chk[tx][ty] + 1 && now[tx][ty] == 0) {
        mvrec(dst.first, dst.second, tx, ty);
        track(src, make_pair(tx, ty));
        return;
      }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &a[i].first, &a[i].second);
  for (int i = 1; i <= m; i++) scanf("%d%d", &b[i].first, &b[i].second);
  for (int i = 1; i <= m; i++)
    now[a[i].first][a[i].second] = i, fin[b[i].first][b[i].second] = i;
  for (int j = 1; j <= m; j++)
    if (now[1][j] == 0) {
      int mv = 0;
      build_bfs(make_pair(1, j));
      for (int first = 1; first <= n; first++)
        for (int second = 1; second <= n; second++)
          if ((first != 1 || first >= j) && chk[first][second] != 0 &&
              now[first][second] != 0 && mv == 0) {
            mv = 1;
            track(make_pair(1, j), make_pair(first, second));
          }
    }
  for (int j = 1; j <= m; j++) rec[j] = b[now[1][j]].second;
  for (int u = 1, cnt = 1; u <= n; u++) {
    for (int j = 1; j <= m; j++)
      if (rec[j] == u) swt(cnt, j), swap(rec[j], rec[cnt++]);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++)
      if (b[now[i][j]].first != i && b[now[i][j]].first != 0)
        mvrec(i, j, i + 1, j);
  }
  for (int i = 1; i <= n; i++) {
    for (;;) {
      int con = 0, add = 1;
      for (int j = 1; j <= n; j++)
        if (now[i][j] != 0) {
          if (j != b[now[i][j]].second) {
            con = 1;
            if (j > b[now[i][j]].second)
              add = -1;
            else
              add = 1;
            for (int k = j; k != b[now[i][k]].second; k += add) {
              if (!mvrec(i, k, i, k + add)) break;
            }
          }
        }
      if (!con) break;
    }
  }
  if (mv1.size() > 10800)
    while (1) {
      mv1.push_back(make_pair(1, 1));
    }
  printf("%d\n", mv1.size());
  for (int i = 0; i < mv1.size(); i++) {
    printf("%d %d %d %d\n", mv1[i].first, mv1[i].second, mv2[i].first,
           mv2[i].second);
  }
}
