#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e5 + 50;
int n;
int ans[N];
vector<int> G[N];
int q[N];
int dep[N];
vector<pair<int, int> > hist[N];
void upd(int u, int val) { q[u] = max(q[u], val); }
void calc(int v, int p) {
  dep[v] = 0;
  for (int nxt : G[v]) {
    if (nxt == p) continue;
    calc(nxt, v);
    dep[v] = max(dep[nxt] + 1, dep[v]);
  }
}
void merge(vector<pair<int, int> > h1, vector<pair<int, int> > h2) {
  int r = 0;
  if (r < h2.size() && h2[r].second == 1) r++;
  for (int i = 0; i < h1.size(); i++) {
    if (h1[i].second == 1) continue;
    while (r < h2.size() && (h2[r].first >= h1[i].first)) {
      r++;
    }
    if (r - 1 >= 0 && h2[r - 1].second > 1)
      upd(2 * h1[i].first, h2[r - 1].second + h1[i].second - 2);
  }
}
void dfs(int v, int p = -1, int up_dep = -1) {
  vector<int> deps;
  if (up_dep != -1) deps.push_back(up_dep + 1);
  for (int nxt : G[v]) {
    if (nxt != p) deps.push_back(dep[nxt] + 1);
  }
  sort(deps.begin(), deps.end(),
       [](const int a, const int b) { return a > b; });
  for (int i = 0; i < deps.size(); i++) {
    upd(2 * deps[i], i + 1);
    upd(2 * deps[i] - 1, i + 1);
    if (i > 0 && deps[i - 1] > deps[i]) upd(2 * deps[i] + 1, i + 1);
  }
  for (int i = 0; i < deps.size(); i++) {
    if (hist[v].empty() || hist[v].back().first != deps[i])
      hist[v].push_back({deps[i], 1});
    else
      hist[v].back().second++;
  }
  for (int i = 1; i < hist[v].size(); i++)
    hist[v][i].second += hist[v][i - 1].second;
  for (int nxt : G[v]) {
    if (nxt == p) continue;
    dfs(nxt, v,
        (deps.size() == 1 ? 0 : (deps[0] == dep[nxt] + 1 ? deps[1] : deps[0])));
    merge(hist[nxt], hist[v]);
    merge(hist[v], hist[nxt]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    ans[1] = max(ans[1], (int)G[i].size() + 1);
  }
  calc(0, -1);
  dfs(0);
  int rmax = 0;
  for (int i = (n - 1) / 2 * 2 + 1; i >= 2; i -= 2) {
    rmax = max(rmax, q[i]);
    ans[i] = rmax;
  }
  rmax = 0;
  for (int i = n / 2 * 2; i >= 2; i -= 2) {
    rmax = max(rmax, q[i]);
    ans[i] = rmax;
  }
  for (int i = 1; i <= n; i++) cout << max(ans[i], 1) << " ";
}
