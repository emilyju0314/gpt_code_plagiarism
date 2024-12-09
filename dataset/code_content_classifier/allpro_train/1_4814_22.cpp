#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
int n, k;
vector<int> edges[200005];
bool v[200005];
int c[200005];
int p[200005][5];
long long int res;
void dfs(int cur, int depth) {
  v[cur] = 1;
  int nxt, tmp;
  p[cur][depth % k] = 1;
  c[cur] = 1;
  for (int i = 0; i < edges[cur].size(); ++i) {
    nxt = edges[cur][i];
    if (!v[nxt]) {
      dfs(nxt, depth + 1);
      for (int a = 0; a < k; ++a) {
        for (int b = 0; b < k; ++b) {
          tmp = ((k << 1) + a + b - ((depth % k) << 1)) % k;
          tmp = ((k << 1) - tmp) % k;
          res += (long long int)tmp * p[cur][a] * p[nxt][b];
        }
      }
      for (int j = 0; j < k; ++j) p[cur][j] += p[nxt][j];
      c[cur] += c[nxt];
    }
  }
  res += (long long int)c[cur] * (n - c[cur]);
}
int main() {
  ios_base::sync_with_stdio(0);
  int a, b;
  while (cin >> n >> k) {
    for (int i = 0; i < n - 1; ++i) {
      cin >> a >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    res = 0;
    memset(v, 0, sizeof(v));
    memset(p, 0, sizeof(p));
    dfs(1, 1);
    cout << res / k << "\n";
    for (int i = 1; i <= n; ++i) edges[i].clear();
  }
  return 0;
}
