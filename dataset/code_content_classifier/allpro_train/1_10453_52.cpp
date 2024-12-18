#include <bits/stdc++.h>
using namespace std;
const int size = 1e2 + 5;
int n, k, arr[4][size];
vector<pair<int, pair<int, int> > > res;
void print_grid() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << "=========================\n";
}
void try_now() {
  for (int i = 0; i < n; i++) {
    if (arr[0][i] == arr[1][i] and arr[0][i] != 0) {
      res.push_back({arr[0][i], {1, i + 1}});
      arr[1][i] = 0;
    }
    if (arr[2][i] == arr[3][i] and arr[2][i] != 0) {
      res.push_back({arr[3][i], {4, i + 1}});
      arr[2][i] = 0;
    }
  }
}
void move_row1() {
  for (int i = n - 2; i >= 0; i--) {
    if (arr[1][i] != 0 and arr[1][i + 1] == 0) {
      arr[1][i + 1] = arr[1][i];
      res.push_back({arr[1][i + 1], {2, i + 2}});
      arr[1][i] = 0;
    }
  }
  if (arr[2][0] != 0 and arr[1][0] == 0) {
    arr[1][0] = arr[2][0];
    res.push_back({arr[1][0], {2, 1}});
    arr[2][0] = 0;
  }
}
void move_row2() {
  for (int i = 1; i < n; i++) {
    if (arr[2][i] != 0 and arr[2][i - 1] == 0) {
      arr[2][i - 1] = arr[2][i];
      res.push_back({arr[2][i - 1], {3, i}});
      arr[2][i] = 0;
    }
  }
  if (arr[1][n - 1] != 0 and arr[2][n - 1] == 0) {
    arr[2][n - 1] = arr[1][n - 1];
    res.push_back({arr[2][n - 1], {3, n}});
    arr[1][n - 1] = 0;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
  try_now();
  for (int i = 0; i < 2 * n; i++) {
    move_row1();
    try_now();
    move_row2();
    try_now();
  }
  if (res.size() == 0) {
    cout << -1;
    return 0;
  }
  cout << res.size() << '\n';
  for (auto it : res)
    cout << it.first << ' ' << it.second.first << ' ' << it.second.second
         << '\n';
}
