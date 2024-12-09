#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
vector<int> g[N];
long long s[N];
long long a[N];
long long ans = 0;
long long sz[N];
long long sum[N];
long long ret[N];
void dfs(int v, int p) {
  if (s[v] == -1)
    sum[v] = sum[p];
  else
    sum[v] = s[v];
  a[v] = LLONG_MAX;
  for (auto &it : g[v]) {
    if (it != p) {
      dfs(it, v);
      a[v] = min(a[it], a[v]);
      ret[v] += ret[it];
    }
  }
  if (a[v] == LLONG_MAX) a[v] = 0;
  if (s[v] == -1) {
    ret[v] -= (g[v].size()) * a[v];
  } else {
    a[v] = sum[v] - sum[p];
    if (a[v] < 0) {
      cout << -1;
      exit(0);
    }
  }
  ret[v] += a[v];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    g[p].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  dfs(0, 0);
  cout << ret[0] + s[0];
  return 0;
}
