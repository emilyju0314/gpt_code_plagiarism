#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20 | 5;
int n, a[N], b[N];
int fa[N], p[N];
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
bool check(int v) {
  int m = (1 << v) - 1;
  for (int i = (int)(0); i <= (int)(m); i++) fa[i] = i, p[i] = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    int p1 = a[i] & m, p2 = b[i] & m;
    fa[get(p1)] = get(p2);
    ++p[p1];
    ++p[p2];
  }
  for (int i = (int)(0); i <= (int)(m); i++)
    if (p[i] & 1) return 0;
  int p = get(a[1] & m);
  for (int i = (int)(1); i <= (int)(n); i++) {
    if (get(a[i] & m) != p) return 0;
    if (get(a[i] & m) != p) return 0;
  }
  return 1;
}
vector<pair<int, int> > e[N];
int ans[N], top, vis[N];
void dfs(int x) {
  for (; e[x].size();) {
    pair<int, int> tmp = e[x].back();
    e[x].pop_back();
    if (!vis[tmp.second >> 1]) {
      vis[tmp.second >> 1] = 1;
      dfs(tmp.first);
      ans[++top] = tmp.second ^ 1;
      ans[++top] = tmp.second;
    }
  }
}
void construct(int v) {
  cout << v << endl;
  int m = (1 << v) - 1;
  for (int i = (int)(1); i <= (int)(n); i++) {
    a[i] &= m;
    b[i] &= m;
    e[a[i]].push_back(pair<int, int>(b[i], i * 2 - 2));
    e[b[i]].push_back(pair<int, int>(a[i], i * 2 - 1));
  }
  dfs(a[1] & m);
  for (int i = (int)(1); i <= (int)(top); i++) cout << ans[i] + 1 << ' ';
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d%d", &a[i], &b[i]);
  int l = 1, r = 20, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  construct(ans);
}
