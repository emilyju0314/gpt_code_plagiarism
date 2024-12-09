#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1000 * 100 + 10;
const double EPS = 1e-9;
const long long MOD = 1000 * 1000 * 1000 + 7;
int si, sj, ti, tj;
int n, m;
int D[1001][1001][4][3];
vector<string> ss;
bool poss(int x, int y) {
  if (x < 0 || x >= n) return false;
  if (y < 0 || y >= m) return false;
  return (ss[x][y] != '*');
}
int rec(int x, int y, int dir, int count) {
  if (D[x][y][dir][count] != -1) return D[x][y][dir][count];
  if (count > 2) return 0;
  if (ss[x][y] == 'T') return 1;
  bool result = false;
  if (dir == 0) {
    if (poss(x, y + 1)) {
      result |= rec(x, y + 1, dir, count);
    }
  }
  if (dir == 1) {
    if (poss(x + 1, y)) {
      result |= rec(x + 1, y, dir, count);
    }
  }
  if (dir == 2) {
    if (poss(x, y - 1)) {
      result |= rec(x, y - 1, dir, count);
    }
  }
  if (dir == 3) {
    if (poss(x - 1, y)) {
      result |= rec(x - 1, y, dir, count);
    }
  }
  if (dir != 0) result |= rec(x, y, 0, count + 1);
  if (dir != 1) result |= rec(x, y, 1, count + 1);
  if (dir != 2) result |= rec(x, y, 2, count + 1);
  if (dir != 3) result |= rec(x, y, 3, count + 1);
  return D[x][y][dir][count] = result;
}
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  memset(D, -1, sizeof(D));
  scanf("%d %d\n", &n, &m);
  ss.resize(n);
  for (int i = 0; i < n; ++i) {
    char buf[1001];
    scanf("%s\n", &buf);
    ss[i] = buf;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (ss[i][j] == 'S') {
        si = i;
        sj = j;
      }
      if (ss[i][j] == 'T') {
        ti = i;
        tj = j;
      }
    }
  }
  bool result = false;
  result |= rec(si, sj, 0, 0);
  result |= rec(si, sj, 1, 0);
  result |= rec(si, sj, 2, 0);
  result |= rec(si, sj, 3, 0);
  if (result) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
