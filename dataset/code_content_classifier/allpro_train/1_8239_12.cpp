#include <bits/stdc++.h>
using namespace std;
const int maxn = 100006;
struct Node {
  int x, y, z, id;
  bool operator<(const Node& a) const {
    return z < a.z || (z == a.z && y < a.y) ||
           (z == a.z && y == a.y && x < a.x);
  }
} node[maxn];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].z);
    node[i].id = i;
  }
  sort(node + 1, node + n + 1);
  int p = 0;
  int l = 1, r = 1;
  while (r <= n) {
    while (r <= n && node[r].z == node[l].z && node[r].y == node[l].y) r++;
    if (r - l > 1) {
      if ((r - l) & 1) node[++p] = node[l], l++;
      for (int i = l; i < r; i += 2)
        printf("%d %d\n", node[i].id, node[i + 1].id);
    } else
      node[++p] = node[l];
    l = r;
  }
  n = p;
  p = 0;
  l = 1, r = 1;
  while (r <= n) {
    while (r <= n && node[r].z == node[l].z) r++;
    if (r - l > 1) {
      if ((r - l) & 1) node[++p] = node[l], l++;
      for (int i = l; i < r; i += 2)
        printf("%d %d\n", node[i].id, node[i + 1].id);
    } else
      node[++p] = node[l];
    l = r;
  }
  n = p;
  for (int i = 1; i <= n; i += 2) printf("%d %d\n", node[i].id, node[i + 1].id);
  return 0;
}
