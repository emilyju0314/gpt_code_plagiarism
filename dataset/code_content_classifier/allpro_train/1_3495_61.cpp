#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
bool possible = true;
int n, x, y, mn[maxn], mx[maxn];
vector<int> vs[maxn], tour;
bool comp(int a, int b) { return mn[a] < mn[b]; }
void pre(int v, int p) {
  for (int e : vs[v])
    if (e != p) {
      pre(e, v);
      mn[v] = min(mn[v], mn[e]);
      mx[v] = max(mx[v], mx[e]);
    }
  vector<pair<int, int>> valid;
  for (int e : vs[v])
    if (e != p) valid.push_back(make_pair(mn[e], mx[e]));
  if (valid.size() <= 1) return;
  sort(valid.begin(), valid.end());
  for (int i = 0; i < int(valid.size()) - 1; i++)
    if (valid[i].second >= valid[i + 1].first) possible = false;
}
void dfs(int v, int p) {
  tour.push_back(v);
  sort(vs[v].begin(), vs[v].end(), comp);
  for (int e : vs[v])
    if (e != p) {
      dfs(e, v);
      tour.push_back(v);
    }
}
int main() {
  for (int i = 0; i < maxn; i++) mn[i] = 1e9, mx[i] = -1;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &x, &y);
    vs[--x].push_back(--y);
    vs[y].push_back(x);
  }
  int o = 0, leaves = 0;
  for (int i = 1; i < n; i++)
    if (vs[i].size() == 1) leaves++;
  for (int i = 0; i < leaves; i++) {
    scanf("%d", &x);
    --x;
    mn[x] = mx[x] = i;
  }
  pre(0, -1);
  if (not possible) {
    puts("-1");
    return 0;
  }
  dfs(0, -1);
  for (int v : tour) printf("%d ", v + 1);
  puts("");
  return 0;
}
