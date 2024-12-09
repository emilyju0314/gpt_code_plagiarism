#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  point() {}
  point(int x, int y) : x(x), y(y) {}
  point operator-(const point& p) const { return point(x - p.x, y - p.y); }
  point operator+(const point& p) const { return point(x + p.x, y + p.y); }
  void scan() { scanf("%d%d", &x, &y); }
  int operator<(const point& p) const { return atan2(y, x) < atan2(p.y, p.x); }
} p[300], P[300];
vector<int> adj[300], rev[300];
queue<int> q[300];
int n, K;
long long f[300][300][60], mx[60];
long long cross(point A, point B) { return 1ll * A.x * B.y - 1ll * A.y * B.x; }
bool onleft(point A, point B, point C) { return cross(B - A, C - B) > 0; }
void add(int x, int y) {
  while (q[x].size() && onleft(p[q[x].front()], p[x], p[y]))
    add(q[x].front(), y), q[x].pop();
  adj[y].push_back(x);
  rev[x].push_back(y);
  q[y].push(x);
}
long long solve(int n) {
  for (int i = 1; i <= n; ++i) {
    adj[i].clear(), rev[i].clear();
    while (q[i].size()) q[i].pop();
  }
  for (int i = 1; i < n; ++i) add(i, i + 1);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k <= K; ++k) f[i][j][k] = 0;
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j <= K; ++j) mx[j] = 0;
    int cur = rev[i].size() - 1;
    for (int j = adj[i].size() - 1; j >= 0; --j) {
      int x = adj[i][j];
      f[x][i][1] = cross(p[x], p[i]);
      for (int k = 1; k <= K; ++k)
        if (mx[k]) f[x][i][k + 1] = mx[k] + cross(p[x], p[i]);
      for (; cur >= 0 && onleft(p[x], p[i], p[rev[i][cur]]); --cur) {
        for (int k = 1; k <= K; ++k)
          if (mx[k] < f[i][rev[i][cur]][k])
            mx[k] = f[i][rev[i][cur]][k],
            f[x][i][k + 1] = mx[k] + cross(p[x], p[i]);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < rev[i].size(); ++j)
      ans = max(ans, f[i][rev[i][j]][K - 2]);
  return ans;
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; ++i) P[i].scan();
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int tp = 0;
    for (int j = 1; j <= n; ++j)
      if (i != j && (P[j].x > P[i].x || (P[j].x == P[i].x && P[j].y > P[i].y)))
        p[++tp] = P[j] - P[i];
    sort(p + 1, p + tp + 1);
    ans = max(ans, solve(tp));
  }
  printf("%lld%s\n", ans / 2, (ans & 1 ? ".50" : ".00"));
}
