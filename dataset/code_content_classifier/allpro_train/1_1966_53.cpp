#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
bool ckmin(T &a, U b) {
  return b < a ? a = b, true : false;
}
template <typename T, typename U>
bool ckmax(T &a, U b) {
  return b > a ? a = b, true : false;
}
int n, m, add;
bool vis[1 << 23];
vector<int> v;
void dfs(int v) {
  vis[v] = true;
  if (v < add) {
    if (!vis[v + add]) dfs(v + add);
    for (int j = 0; j < n; ++j) {
      if ((v >> j) & 1) {
        int cur = v ^ (1 << j);
        if (!vis[cur]) dfs(cur);
      }
    }
  } else {
    if (!vis[(add - 1) ^ (v - add)]) dfs((add - 1) ^ (v - add));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < (1 << 23); ++i) vis[i] = 1;
  v.assign(m, 0);
  add = (1 << n);
  for (int i = 0; i < m; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < add; ++i) vis[i] = false;
  for (auto i : v) vis[i + add] = false;
  int res = 0;
  for (int i = add; i < (1 << 23); ++i) {
    if (!vis[i]) {
      res++;
      dfs(i);
    }
  }
  cout << res;
  return 0;
}
