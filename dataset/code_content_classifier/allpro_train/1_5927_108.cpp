#include <bits/stdc++.h>
using namespace std;
int mov[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
char G[2100][2100];
int used[2100][2100] = {0};
int d[4000100];
int n, m;
void input() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[i * m + j] = 0;
      scanf(" %c", &G[i][j]);
      if (G[i][j] == '.') {
        if (i != 0 && G[i - 1][j] == '.') {
          d[i * m + j]++;
          d[(i - 1) * m + j]++;
        }
        if (j != 0 && G[i][j - 1] == '.') {
          d[i * m + j]++;
          d[(i)*m + j - 1]++;
        }
      } else {
        d[i * m + j] = 1000;
      }
    }
  }
}
queue<int> q;
bool solve() {
  int mi = 2000;
  for (int i = 0; i < n * m; i++) {
    mi = min(mi, d[i]);
    if (d[i] == 1) q.push(i);
  }
  if (mi == 0) return false;
  if (mi == 1000) return true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (d[u] == 0) continue;
    d[u]--;
    int y = u / m, x;
    x = u % m;
    for (int i = 0; i < 4; i++) {
      int x2, y2;
      x2 = x + mov[i][1];
      y2 = y + mov[i][0];
      if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && G[y2][x2] == '.' &&
          d[y2 * m + x2] != 0) {
        if (i == 0) {
          G[y2][x2] = 'v';
          G[y][x] = '^';
        } else if (i == 1) {
          G[y2][x2] = '<', G[y][x] = '>';
        } else if (i == 2) {
          G[y2][x2] = '^', G[y][x] = 'v';
        } else if (i == 3) {
          G[y2][x2] = '>', G[y][x] = '<';
        }
        d[y2 * m + x2] = 0;
        used[y][x] = 1;
        used[y2][x2] = 1;
        for (int j = 0; j < 4; j++) {
          int x3, y3;
          x3 = x2 + mov[j][0];
          y3 = y2 + mov[j][1];
          if (x3 >= 0 && x3 < m && y3 >= 0 && y3 < n && G[y3][x3] == '.' &&
              d[y3 * m + x3] != 0) {
            d[y3 * m + x3]--;
            if (d[y3 * m + x3] == 1) q.push(y3 * m + x3);
          }
        }
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (used[i][j] == 0 && G[i][j] == '.') return false;
    }
  }
  return true;
}
void output() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", G[i][j]);
    }
    printf("\n");
  }
}
int main() {
  cin >> n >> m;
  input();
  bool t = solve();
  if (t)
    output();
  else
    cout << "Not unique" << endl;
  return 0;
}
