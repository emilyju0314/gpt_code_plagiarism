#include <bits/stdc++.h>
using namespace std;
const int MAX = 300005;
int a[MAX], par[MAX];
map<pair<int, int>, int> cnt;
set<int> adj[MAX];
int main() {
  ios::sync_with_stdio(false);
  long long n, p;
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u]++;
    a[v]++;
    if (u < v) swap(u, v);
    cnt[make_pair(u, v)]++;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for (int i = 1; i <= n; i++) par[a[i]]++;
  for (int i = n; i >= 0; i--) par[i] += par[i + 1];
  long long ans = 0, res = 0;
  for (int v = 1; v <= n; v++) {
    long long k = a[v];
    k = p - k;
    if (k <= 0) {
      ans += n - 1 - adj[v].size();
      continue;
    }
    long long t = par[k];
    for (set<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++) {
      int u = *it;
      if (a[u] >= k) t--;
    }
    if (a[v] >= k) t--;
    ans += t;
  }
  ans /= 2;
  for (map<pair<int, int>, int>::iterator it = cnt.begin(); it != cnt.end();
       it++) {
    int u = it->first.first;
    int v = it->first.second;
    int tm = it->second;
    if (a[u] + a[v] - tm >= p) ans++;
  }
  cout << ans << endl;
  return 0;
}
