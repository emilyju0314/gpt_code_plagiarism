#include <bits/stdc++.h>
using namespace std;
const int maxn = 501;
vector<int> g[maxn];
char ans[maxn];
int was[maxn];
void dfs(int v, int c) {
  was[v] = c;
  for (int x : g[v])
    if (!was[x]) dfs(x, c);
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> b;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == n - 1) {
      b.push_back(i);
      was[i] = 1;
      ans[i] = 'b';
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!was[i]) {
      dfs(i, 2);
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!was[i]) {
      dfs(i, 3);
      break;
    }
  }
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    if (was[i] == 2) a.push_back(i);
  }
  for (int x : a) {
    if (g[x].size() != (int)a.size() + (int)b.size() - 1) {
      cout << "No" << endl;
      return 0;
    }
    ans[x] = 'a';
  }
  vector<int> c;
  for (int i = 1; i <= n; i++) {
    if (was[i] == 3) c.push_back(i);
  }
  for (int x : c) {
    if (g[x].size() != (int)c.size() + (int)b.size() - 1) {
      cout << "No" << endl;
      return 0;
    }
    ans[x] = 'c';
  }
  for (int i = 1; i <= n; i++) {
    if (!was[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++) cout << ans[i];
  return 0;
}
