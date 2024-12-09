#include <bits/stdc++.h>
using namespace std;
int n, m;
struct point {
  int x, y;
  void read() { scanf("%d%d", &x, &y); }
} p[504];
int dis_t(point A, point B) { return abs(A.x - B.x) + abs(A.y - B.y); }
int lc[504], olc[504];
int len[504], ans[504];
int in_(int x) { return (x + n) % n; }
bool work(int bg) {
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < m; i++) olc[i] = len[i];
  for (int i = bg; i < n; i += 2) {
    bool flag = 1;
    for (int j = 0; j < m; j++) {
      if (lc[i] == olc[j]) {
        olc[j] = -1;
        ans[i] = j + 1;
        flag = 0;
        break;
      }
    }
    if (flag) return 0;
  }
  puts("YES");
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  puts("");
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) p[i].read();
  for (int i = 0; i < m; i++) scanf("%d", &len[i]);
  for (int i = 0; i < n; i++) {
    lc[i] = dis_t(p[in_(i - 1)], p[i]) + dis_t(p[in_(i + 1)], p[i]);
  }
  if (work(0)) return 0;
  if (work(1)) return 0;
  puts("NO");
  return 0;
}
