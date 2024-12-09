#include <bits/stdc++.h>
using namespace std;
int i, i0, n, m, ans[5005];
vector<int> mp[5005];
struct pair_hash {
  inline size_t operator()(const pair<int, int>& p) const {
    return p.first * 1007 + p.second;
  }
};
unordered_map<pair<int, int>, int, pair_hash> dic;
struct node {
  int x, y, z;
} a[5005];
bool cmp(node a, node b) { return a.z < b.z; }
bool dfs(int x, int root, int y, int z) {
  if (y == x) return 1;
  for (int nex : mp[x]) {
    if (nex == root) continue;
    if (dfs(nex, x, y, z)) {
      ans[dic[{min(nex, x), max(nex, x)}]] = z;
      return 1;
    }
  }
  return 0;
}
int dfs0(int x, int root, int y, int z) {
  if (y == x) return INT_MAX - 1;
  for (int nex : mp[x]) {
    if (nex == root) continue;
    int vv = dfs0(nex, x, y, z);
    if (vv != INT_MAX) {
      return min(vv, ans[dic[{min(nex, x), max(nex, x)}]]);
    }
  }
  return INT_MAX;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > y) swap(x, y);
    dic[{x, y}] = i - 1;
    mp[x].push_back(y);
    mp[y].push_back(x);
    ans[i - 1] = 1;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
  }
  sort(a + 1, a + 1 + m, cmp);
  for (int i = 1; i <= m; i++) {
    dfs(a[i].x, -1, a[i].y, a[i].z);
  }
  for (int i = 1; i <= m; i++) {
    if (dfs0(a[i].x, -1, a[i].y, a[i].z) != a[i].z) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 1; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
