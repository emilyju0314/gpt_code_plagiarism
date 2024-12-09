#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const long long MINF = 1e18 + 7;
const int EPS = 1e-6;
const int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
const int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
const double pi = acos(-1.0);
long long a[MAXN], b[MAXN];
vector<int> g[MAXN], v;
bool used[MAXN];
long long n, m, k, cnt = 0, sum = 0, ans = 0, mx = 0, mn = INF;
bool y = 0;
void dfs(int v, int stol) {
  b[v] = stol;
  used[v] = 1;
  mx = max(b[v], mx);
  for (int i = 0; i < g[v].size(); i++) {
    if (!used[g[v][i]]) {
      dfs(g[v][i], stol + 1);
    }
  }
}
void freopen() {
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != -1) {
      g[a[i]].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) {
      dfs(i, 1);
    }
  }
  cout << mx;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
