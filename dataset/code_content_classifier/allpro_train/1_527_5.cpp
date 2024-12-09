#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, 1, -1, -1, 1, -1};
int dy[] = {1, -1, 1, -1, 1, -1, 0, 0};
long long int x[200005], y[200005];
long long dist(long long a, long long b, long long c, long long d) {
  return abs(a - c) + abs(b - d);
}
int main() {
  long long int n, sx, sy, nx, ny, cnt = 0, mx = -1, ansx, ansy;
  cin >> n >> sx >> sy;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < 8; i++) {
    nx = sx + dx[i];
    ny = sy + dy[i];
    if (nx >= 0 && nx <= 1e9 && ny >= 0 && ny <= 1e9) {
      for (int i = 0; i < n; i++) {
        if (dist(sx, sy, nx, ny) + dist(nx, ny, x[i], y[i]) ==
            dist(sx, sy, x[i], y[i]))
          cnt++;
      }
    }
    if (mx < cnt) {
      mx = cnt;
      ansx = nx;
      ansy = ny;
    }
    cnt = 0;
  }
  cout << mx << endl;
  cout << ansx << " " << ansy << endl;
}
