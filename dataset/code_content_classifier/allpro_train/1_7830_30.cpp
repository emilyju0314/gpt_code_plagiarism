#include <bits/stdc++.h>
using namespace std;
struct cell {
  bool is_locked;
  int last_cycle, last_core;
};
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> is_locked(n, 0);
  cell temp;
  temp.is_locked = false;
  temp.last_cycle = -1;
  temp.last_core = -1;
  vector<cell> cell_arr(k, temp);
  int A[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (is_locked[i] < 0) continue;
      is_locked[i]++;
      if (A[i][j] == 0) continue;
      if (cell_arr[A[i][j] - 1].is_locked) {
        is_locked[i] *= -1;
      } else if (cell_arr[A[i][j] - 1].last_cycle == j) {
        cell_arr[A[i][j] - 1].is_locked = true;
        is_locked[i] *= -1;
        is_locked[cell_arr[A[i][j] - 1].last_core] *= -1;
      } else {
        cell_arr[A[i][j] - 1].last_cycle = j;
        cell_arr[A[i][j] - 1].last_core = i;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (is_locked[i] == m)
      printf("0\n");
    else
      printf("%d\n", is_locked[i] * -1);
  }
  return 0;
}
