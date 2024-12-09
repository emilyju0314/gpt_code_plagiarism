#include <bits/stdc++.h>
using namespace std;
int n, k1, k2, x, y, cas;
vector<int> v[1005];
set<int> s1, s2;
void preg(int t, int id) {
  if (t == 1) printf("A %d\n", id);
  if (t == 2) printf("B %d\n", id);
  if (t == 3) printf("C %d\n", id);
  if (t == 4) printf("-1\n");
  fflush(stdout);
}
int dfs(int nd, int ant = -1) {
  if (s1.find(nd) != s1.end()) return nd;
  int s = -1;
  for (int u : v[nd])
    if (u != ant) s = max(s, dfs(u, nd));
  return s;
}
int main() {
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
      scanf("%d%d", &x, &y);
      v[x].push_back(y);
      v[y].push_back(x);
    }
    scanf("%d", &k1);
    for (int i = 1; i <= k1; ++i) {
      scanf("%d", &x);
      s1.insert(x);
    }
    scanf("%d", &k2);
    for (int i = 1; i <= k2; ++i) {
      scanf("%d", &x);
      s2.insert(x);
    }
    preg(2, *s2.begin());
    scanf("%d", &x);
    x = dfs(x);
    preg(1, x);
    scanf("%d", &y);
    if (s2.find(y) == s2.end())
      preg(3, -1);
    else
      preg(3, x);
    for (int i = 1; i <= n; ++i) v[i].clear();
    s1.clear(), s2.clear();
  }
  return 0;
}
