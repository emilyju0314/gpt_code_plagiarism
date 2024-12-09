#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
long long a[N], b[N];
bool vis[N];
vector<int> g[N];
long long ans;
vector<int> pos, neg;
void dfs(int u) {
  vis[u] = 1;
  for (int v : g[u]) {
    if (!vis[v]) dfs(v);
  }
  ans += a[u];
  if (a[u] > 0 && b[u] != -1) a[b[u]] += a[u];
  if (a[u] > 0)
    pos.emplace_back(u);
  else
    neg.emplace_back(u);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n; ++i) {
    cin >> b[i];
    if (b[i] != -1) g[b[i]].emplace_back(i);
  }
  for (long long i = 1; i <= n; ++i) {
    if (!vis[i]) dfs(i);
  }
  cout << ans << endl;
  for (int i : pos) cout << i << " ";
  reverse(neg.begin(), neg.end());
  for (int i : neg) cout << i << " ";
  return 0;
}
