#include <bits/stdc++.h>
using namespace std;
int xm[4] = {-1, 1, 0, 0};
int ym[4] = {0, 0, -1, 1};
const int MOD = 1e9 + 7;
const int K = 2520;
const int MAXN = 1000 + 5;
const long long POW = 9973;
int dp[1005][K + 5];
vector<int> adj[MAXN];
int ar[MAXN];
int vis[1005][K];
void form(int &b) { b = ((b % K) + K) % K; }
void dfs(int x, int k) {
  vector<pair<int, int>> v;
  int ans = 0;
  int flg = 0;
  form(k);
  v.push_back(make_pair(x, k));
  pair<int, int> end;
  int nx, nk, m;
  while (true) {
    vis[x][k] = 1;
    m = adj[x].size();
    nx = adj[x][k % m];
    nk = k + ar[nx];
    form(nk);
    v.push_back(make_pair(nx, nk));
    if (dp[nx][nk]) {
      ans = dp[nx][nk];
      break;
    }
    if (vis[nx][nk]) {
      break;
    }
    x = nx;
    k = nk;
  }
  set<int> distinct;
  if (!ans) {
    for (pair<int, int> p : v) {
      if (p == make_pair(nx, nk)) flg = 1;
      if (flg) distinct.insert(p.first);
    }
    ans = distinct.size();
  }
  for (pair<int, int> p : v) {
    dp[p.first][p.second] = ans;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> ar[i];
  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      adj[i].push_back(x);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < K; j++) {
      if (dp[i][j]) continue;
      dfs(i, j);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    b += ar[a];
    form(b);
    cout << dp[a][b] << "\n";
  }
}
