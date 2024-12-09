#include <bits/stdc++.h>
const int MAX = 2e5 + 7;
using namespace std;
long long x[] = {-1, 1, 0, 0};
long long y[] = {0, 0, 1, -1};
long long arr[2005][2005], distl[2005][2005], distr[2005][2005],
    vis[2005][2005];
long long ml, mr, ans = 0, n, m;
struct location {
  int row, col, left, right;
  location(int _row, int _col, int _l, int _r) {
    row = _row;
    col = _col;
    left = _l;
    right = _r;
  }
  bool operator<(location x) const { return x.left + x.right < left + right; }
};
bool valid(long long r, long long c) {
  if (r >= 1 && r <= n && c >= 1 && c <= m && arr[r][c] != 1)
    return true;
  else
    return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ;
  cin >> n >> m;
  long long sr, sc;
  cin >> sr >> sc;
  cin >> ml >> mr;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      cin >> ch;
      if (ch == '.')
        arr[i][j] = 0;
      else
        arr[i][j] = 1;
      distl[i][j] = 1e9;
      distr[i][j] = 1e9;
    }
  }
  priority_queue<location> pq;
  pq.push(location(sr, sc, 0, 0));
  while (!pq.empty()) {
    location loc = pq.top();
    pq.pop();
    if (loc.left > ml || loc.right > mr || vis[loc.row][loc.col]) continue;
    ans++;
    vis[loc.row][loc.col] = 1;
    for (int i = 0; i < 4; i++) {
      int nr = loc.row + x[i];
      int nc = loc.col + y[i];
      if (valid(nr, nc) && vis[nr][nc] == 0) {
        int le = 0, ri = 0;
        if (nc < loc.col)
          le++;
        else if (nc > loc.col)
          ri++;
        if (distl[nr][nc] > loc.left + le) {
          distl[nr][nc] = loc.left + le;
          pq.push(location(nr, nc, loc.left + le, loc.right + ri));
        }
        if (distr[nr][nc] > loc.right + ri) {
          distr[nr][nc] = loc.right + ri;
          pq.push(location(nr, nc, loc.left + le, loc.right + ri));
        }
      }
    }
  }
  cout << ans << '\n';
}
