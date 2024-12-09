#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
long long k;
int n, vis[5555][5555], cnt[5555], tot;
queue<pair<int, int> > q;
bool a[5555][5555];
bool ok(int x, int y) { return x >= 1 && x < 5555 && y >= 1 && y < 5555; }
int main() {
  cin >> k >> n;
  k++;
  for (int i = (1); i <= (n); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x += 2 * 200, y += 2 * 200;
    a[x][y] = 1;
  }
  queue<pair<int, int> > q;
  q.push(pair<int, int>(2 * 200, 2 * 200));
  vis[2 * 200][2 * 200] = 1;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    tot++;
    cnt[vis[x][y]]++;
    if (vis[x][y] == k || vis[x][y] == 200) continue;
    for (int i = (0); i <= (7); i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (!ok(nx, ny)) continue;
      if (!vis[nx][ny] && !a[nx][ny]) {
        vis[nx][ny] = vis[x][y] + 1;
        q.push(pair<int, int>(nx, ny));
      }
    }
  }
  if (k > 200 && cnt[200] > 0) {
    int tmp = (k - 200) % 1000000007;
    tot = (tot + (long long)tmp * cnt[200] % 1000000007) % 1000000007;
    tot = (tot + 14ll * tmp % 1000000007 * (tmp + 1) % 1000000007) % 1000000007;
  }
  cout << tot << '\n';
  return 0;
}
