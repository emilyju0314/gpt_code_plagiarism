#include <bits/stdc++.h>
using namespace std;
int n, m, T, size;
int dp[5001][5001], last[5001][5001], ans[5001];
bool vis[5001][5001];
struct point {
  int to, val;
  point() {}
  point(int a, int b) { to = a, val = b; }
};
vector<point> v[5001];
queue<point> q;
void spfa() {
  memset(dp, 63, sizeof(dp)), dp[1][1] = 0;
  q.push(point(1, 1));
  while (!q.empty()) {
    point po = q.front();
    q.pop();
    int x = po.to, y = po.val;
    for (unsigned int i = 0; i < v[x].size(); i++) {
      int deg = v[x][i].to, va = v[x][i].val;
      if (dp[x][y] + va > T) continue;
      if (dp[deg][y + 1] > dp[x][y] + va) {
        dp[deg][y + 1] = dp[x][y] + va, last[deg][y + 1] = x;
        if (!vis[deg][y + 1]) vis[deg][y + 1] = 1, q.push(point(deg, y + 1));
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &T);
  for (int i = 1, a, b, c; i <= m; i++)
    scanf("%d%d%d", &a, &b, &c), v[a].push_back(point(b, c));
  spfa();
  int tmp = 0;
  for (int i = n; i; i--)
    if (dp[n][i] <= T) {
      printf("%d\n", tmp = i);
      break;
    }
  for (; n; n = last[n][tmp--]) ans[++size] = n;
  for (int i = size; i; i--) printf("%d ", ans[i]);
  return 0;
}
