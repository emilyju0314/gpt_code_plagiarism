#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
long long nax;
int n;
vector<int> a, vis;
vector<pair<int, int>> m;
void bfs(int i) {
  queue<pair<long long, int>> q;
  q.push(make_pair(a[i], 0));
  m[a[i]].first++;
  vis[a[i]] = i;
  while (!q.empty()) {
    long long u = q.front().first;
    int steps = q.front().second;
    q.pop();
    if (u * 2 <= nax && vis[2 * u] != i) {
      q.push(make_pair(2 * u, steps + 1));
      vis[2 * u] = i;
      m[2 * u].first++;
      m[2 * u].second += steps + 1;
    }
    if (u / 2 > 0 && vis[u / 2] != i) {
      q.push(make_pair(u / 2, steps + 1));
      vis[u / 2] = i;
      m[u / 2].first++;
      m[u / 2].second += steps + 1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  a.resize(n);
  int ans = INF;
  for (int &i : a) cin >> i;
  for (int i = 0; i < n; i++) nax = max(nax, (long long)a[i]);
  m.resize(nax + 1, make_pair(0, 0));
  vis.resize(nax + 1, -1);
  for (int i = 0; i < n; i++) {
    bfs(i);
  }
  for (int i = 0; i <= nax; i++) {
    if (m[i].first == n) ans = min(ans, m[i].second);
  }
  cout << ans << "\n";
}
