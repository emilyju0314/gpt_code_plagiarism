#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
};
vector<node> G, ans;
int check(int x1, int y1, int x2, int y2) {
  ans.clear();
  for (int i = 0; i < G.size(); ++i) {
    int xx = G[i].x, yy = G[i].y;
    if (xx == x1) {
      if (y1 <= yy && yy <= y2)
        continue;
      else {
        ans.push_back({xx, yy});
      }
    } else if (xx == x2) {
      if (y1 <= yy && yy <= y2)
        continue;
      else {
        ans.push_back({xx, yy});
      }
    } else if (yy == y1) {
      if (x1 <= xx && xx <= x2)
        continue;
      else {
        ans.push_back({xx, yy});
      }
    } else if (yy == y2) {
      if (x1 <= xx && xx <= x2)
        continue;
      else {
        ans.push_back({xx, yy});
      }
    } else
      ans.push_back({xx, yy});
  }
  if (ans.size() == 1) return 1;
  return 0;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 4 * n + 1; i++) {
    int u, v;
    cin >> u >> v;
    G.push_back({u, v});
  }
  for (int i = 0; i <= 50; ++i) {
    for (int j = 0; j <= 50; ++j) {
      for (int k = 1; k <= 50; k++) {
        int x = i + k;
        int y = j + k;
        if (x > 50 || y > 50) continue;
        if (check(i, j, x, y)) {
          printf("%d %d\n", ans[0].x, ans[0].y);
          return 0;
        }
      }
    }
  }
  return 0;
}
