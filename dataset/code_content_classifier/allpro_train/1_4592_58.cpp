#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int N = 100005;
int i, n, k, x, y, lvl[N];
vector<int> g[N];
queue<int> q;
int main() {
  ios_base::sync_with_stdio(0);
  memset(lvl, -1, sizeof(lvl));
  cin >> n >> k;
  for (i = 1; i < n; ++i) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i = 1; i <= n; ++i)
    if (g[i].size() == 1) q.push(i), lvl[i] = 0;
  for (; !q.empty(); q.pop()) {
    x = q.front();
    if (lvl[x] == k) continue;
    vector<int> now;
    for (int to : g[x])
      if (lvl[to] == -1 || lvl[to] == lvl[x] + 1) now.push_back(to);
    if (now.size() > 1) return cout << "No\n", 0;
    if (!now.size()) return cout << "No\n", 0;
    if (g[now[0]].size() < 4 - (lvl[x] + 1 == k)) return cout << "No\n", 0;
    if (lvl[now[0]] == -1) lvl[now[0]] = lvl[x] + 1, q.push(now[0]);
  }
  int cnt = 0;
  for (i = 1; i <= n; ++i) {
    if (lvl[i] > k) return cout << "No\n", 0;
    if (lvl[i] == k) ++cnt;
    if (cnt > 1) return cout << "No\n", 0;
  }
  cout << (!cnt ? "No" : "Yes") << '\n';
  return 0;
}
