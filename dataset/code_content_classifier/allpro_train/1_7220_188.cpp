#include <bits/stdc++.h>
using namespace std;
long long int MOD(long long int a, long long int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
int max3(int a, int b, int c) { return max(c, max(a, b)); }
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int logg(long long int a) {
  long long int x = 0;
  while (a > 1) {
    x++;
    a /= 2;
  }
  return x;
}
vector<int> adj[50005], vis, par;
void dfs(int x) {
  vis[x] = 1;
  for (int i = 0; i < adj[x].size(); i++) {
    if (!vis[adj[x][i]]) {
      par[adj[x][i]] = x;
      dfs(adj[x][i]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, r1, r2;
  cin >> n >> r1 >> r2;
  vis.resize(n + 2, 0);
  par.resize(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    if (i != r1) {
      int a;
      cin >> a;
      adj[a].push_back(i);
      adj[i].push_back(a);
    }
  }
  par[r2] = -1;
  dfs(r2);
  for (int i = 1; i <= n; i++) {
    if (par[i] != -1) cout << par[i] << ' ';
  }
}
