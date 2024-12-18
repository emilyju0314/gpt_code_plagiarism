#include <bits/stdc++.h>
using namespace std;
string Monitor[2010];
int Pixels;
int N, M;
int check(int i, int j) { return i >= 0 && j >= 0 && j < M && i < N; }
bool Check(int dx, int dy, int Sz) {
  if (!check(dx, dy) || !(check(dx + Sz - 1, dy + Sz - 1))) return false;
  int sum = 0;
  for (int i = dx; i < dx + Sz; i++) {
    for (int j = dy; j < dy + Sz; j++) {
      if (!check(i, j)) continue;
      if (i == dx || j == dy || i == dx + Sz - 1 || j == dy + Sz - 1) {
        sum += (Monitor[i][j] == 'w');
      }
    }
  }
  if (sum < Pixels) return false;
  for (int i = dx; i < dx + Sz; i++) {
    for (int j = dy; j < dy + Sz; j++) {
      if (!check(i, j)) continue;
      if (i == dx || j == dy || i == dx + Sz - 1 || j == dy + Sz - 1) {
        if (Monitor[i][j] == '.') Monitor[i][j] = '+';
      }
    }
  }
  for (int i = 0; i < N; i++) cout << Monitor[i] << endl;
  return true;
}
int main() {
  cin >> N >> M;
  int up = INT_MAX, down = 0, left = INT_MAX, right = 0;
  for (int i = 0; i < N; i++) {
    cin >> Monitor[i];
    for (int j = 0; j < M; j++) {
      if (Monitor[i][j] == 'w') {
        Pixels += 1;
        up = min(up, i);
        down = max(down, i);
        left = min(left, j);
        right = max(right, j);
      }
    }
  }
  int Sz = max(down - up + 1, right - left + 1);
  int dx[] = {0, up, down - Sz + 1};
  int dy[] = {0, left, right - Sz + 1};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (Check(dx[i], dy[j], Sz)) return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
