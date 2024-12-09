#include <bits/stdc++.h>
using namespace std;
static const int maxs = 1042;
char maze[maxs][maxs];
int n, m, k, s_i, s_j;
int dist[maxs][maxs] = {};
bool used[maxs][maxs] = {};
queue<pair<int, int> > q;
string res;
void add_neighbour(int fi, int fj, int ti, int tj) {
  if (maze[ti][tj] == '.' && !used[ti][tj]) {
    q.push({ti, tj});
    used[ti][tj] = true;
    dist[ti][tj] = dist[fi][fj] + 1;
  }
}
void bfs() {
  q.push({s_i, s_j});
  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    add_neighbour(curr.first, curr.second, curr.first + 1, curr.second);
    add_neighbour(curr.first, curr.second, curr.first, curr.second + 1);
    add_neighbour(curr.first, curr.second, curr.first - 1, curr.second);
    add_neighbour(curr.first, curr.second, curr.first, curr.second - 1);
  }
}
void greedy() {
  int steps_left = k;
  int c_i = s_i, c_j = s_j;
  while (steps_left > dist[c_i][c_j]) {
    steps_left--;
    if (maze[c_i + 1][c_j] != '*') {
      res.append("D");
      c_i = c_i + 1;
    } else if (maze[c_i][c_j - 1] != '*') {
      res.append("L");
      c_j = c_j - 1;
    } else if (maze[c_i][c_j + 1] != '*') {
      res.append("R");
      c_j = c_j + 1;
    } else if (maze[c_i - 1][c_j] != '*') {
      res.append("U");
      c_i = c_i - 1;
    } else {
      cout << "IMPOSSIBLE";
      exit(0);
    }
  }
  while (c_i != s_i || c_j != s_j) {
    if (!steps_left) {
      cout << "IMPOSSIBLE";
      exit(0);
    }
    if (maze[c_i + 1][c_j] != '*' && dist[c_i][c_j] == dist[c_i + 1][c_j] + 1) {
      res.append("D");
      c_i = c_i + 1;
    } else if (maze[c_i][c_j - 1] != '*' &&
               dist[c_i][c_j] == dist[c_i][c_j - 1] + 1) {
      res.append("L");
      c_j = c_j - 1;
    } else if (maze[c_i][c_j + 1] != '*' &&
               dist[c_i][c_j] == dist[c_i][c_j + 1] + 1) {
      res.append("R");
      c_j = c_j + 1;
    } else if (maze[c_i - 1][c_j] != '*' &&
               dist[c_i][c_j] == dist[c_i - 1][c_j] + 1) {
      res.append("U");
      c_i = c_i - 1;
    } else {
      cout << "IMPOSSIBLE";
      exit(0);
    }
    steps_left--;
  }
}
int main() {
  cin >> n >> m >> k;
  char c;
  for (int i = 0; i <= n + 1; i++) {
    maze[i][m + 1] = '*';
    maze[i][0] = '*';
  }
  for (int i = 0; i <= m + 1; i++) {
    maze[0][i] = '*';
    maze[n + 1][i] = '*';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> maze[i][j];
      if (maze[i][j] == 'X') {
        s_i = i;
        s_j = j;
      }
    }
  }
  bfs();
  greedy();
  cout << res;
  return 0;
}
