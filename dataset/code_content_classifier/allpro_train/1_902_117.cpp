#include <bits/stdc++.h>
using namespace std;
int grid[2000][2000];
int q[100000];
int qtable[9][9];
int x_min[9];
int x_max[9];
int y_min[9];
int y_max[9];
int solve_problem() {
  int n, m, k, s;
  if (scanf("%d %d %d %d", &n, &m, &k, &s) != 4) return 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (scanf("%d", &grid[i][j]) != 1) return 1;
      --grid[i][j];
    }
  fill(x_min, x_min + k, numeric_limits<int>::max());
  fill(x_max, x_max + k, numeric_limits<int>::min());
  fill(y_min, y_min + k, numeric_limits<int>::max());
  fill(y_max, y_max + k, numeric_limits<int>::min());
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x = i + j;
      int y = i - j;
      int t = grid[i][j];
      if (x < x_min[t]) x_min[t] = x;
      if (x > x_max[t]) x_max[t] = x;
      if (y < y_min[t]) y_min[t] = y;
      if (y > y_max[t]) y_max[t] = y;
    }
  for (int i = 0; i < s; i++) {
    if (scanf("%d", &q[i]) != 1) return 1;
    --q[i];
  }
  for (int i = 1; i < s; i++) {
    int prev = q[i - 1];
    int next = q[i];
    qtable[min(prev, next)][max(prev, next)] = 1;
  }
  int result = 0;
  for (int i = 0; i < k; i++)
    for (int j = i; j < k; j++)
      if (qtable[i][j]) {
        int cand = abs(x_min[i] - x_min[j]);
        if (cand > result) result = cand;
        cand = abs(x_min[i] - x_max[j]);
        if (cand > result) result = cand;
        cand = abs(x_max[i] - x_min[j]);
        if (cand > result) result = cand;
        cand = abs(x_max[i] - x_max[j]);
        if (cand > result) result = cand;
        cand = abs(y_min[i] - y_min[j]);
        if (cand > result) result = cand;
        cand = abs(y_min[i] - y_max[j]);
        if (cand > result) result = cand;
        cand = abs(y_max[i] - y_min[j]);
        if (cand > result) result = cand;
        cand = abs(y_max[i] - y_max[j]);
        if (cand > result) result = cand;
      }
  printf("%d\n", result);
  return 0;
}
int main() {
  solve_problem();
  return 0;
}
