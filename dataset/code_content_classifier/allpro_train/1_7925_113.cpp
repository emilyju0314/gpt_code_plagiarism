#include <bits/stdc++.h>
using namespace std;
const int N_DIRS = 6;
const int DX[] = {1, -1, 0, 0, 0, 0};
const int DY[] = {0, 0, 1, -1, 0, 0};
const int DZ[] = {0, 0, 0, 0, 1, -1};
const int MAX_N = 10;
string a[MAX_N][MAX_N];
bool was[MAX_N][MAX_N][MAX_N];
int main() {
  int k, n, m;
  cin >> k >> n >> m;
  for (int i = 0; i < k; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  int y, z;
  cin >> y >> z;
  y--, z--;
  int ans = 0;
  queue<int> que;
  que.push(100 * 0 + 10 * y + z);
  was[0][y][z] = true;
  while (!que.empty()) {
    int el = que.front();
    que.pop();
    ans++;
    int x = el / 100, y = (el / 10) % 10, z = el % 10;
    for (int dir = 0; dir < N_DIRS; dir++) {
      int cx = x + DX[dir], cy = y + DY[dir], cz = z + DZ[dir];
      if (0 <= cx && cx < k && 0 <= cy && cy < n && 0 <= cz && cz < m &&
          a[cx][cy][cz] == '.' && !was[cx][cy][cz]) {
        que.push(100 * cx + 10 * cy + cz);
        was[cx][cy][cz] = true;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
