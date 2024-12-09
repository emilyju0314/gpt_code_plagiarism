#include <bits/stdc++.h>
using namespace std;
int n;
struct Node {
  int x, y;
} p[5000];
vector<int> v[5];
map<double, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
  for (int i = 2; i <= n; i++) p[i].x -= p[1].x, p[i].y -= p[1].y;
  p[1].x = 0, p[1].y = 0;
  int flag = 1;
  while (flag) {
    for (int i = 1; i <= n; i++)
      if (p[i].x & 1 || p[i].y & 1) {
        flag = 0;
        break;
      }
    if (!flag) break;
    for (int i = 1; i <= n; i++) p[i].x /= 2, p[i].y /= 2;
  }
  for (int i = 1; i <= 4; i++) v[i].clear();
  for (int i = 1; i <= n; i++) {
    if (p[i].x & 1 && p[i].y & 1)
      v[1].push_back(i);
    else if (p[i].x & 1 && !(p[i].y & 1))
      v[2].push_back(i);
    else if (!(p[i].x & 1) && p[i].y & 1)
      v[3].push_back(i);
    else
      v[4].push_back(i);
  }
  if ((v[1].size() || v[4].size()) && (v[2].size() || v[3].size())) {
    printf("%d\n", v[1].size() + v[4].size());
    for (int i = 0; i < v[1].size(); i++) printf("%d ", v[1][i]);
    for (int i = 0; i < v[4].size(); i++) printf("%d ", v[4][i]);
  } else if ((v[1].size() && v[4].size()) && !(v[2].size() || v[3].size())) {
    printf("%d\n", v[1].size());
    for (int i = 0; i < v[1].size(); i++) printf("%d ", v[1][i]);
  } else if (!(v[1].size() || v[4].size()) && (v[2].size() && v[3].size())) {
    printf("%d\n", v[2].size());
    for (int i = 0; i < v[2].size(); i++) printf("%d ", v[2][i]);
  }
  return 0;
}
