#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 200 + 10;
int in[MAXN], out[MAXN], all[MAXN], n, m, dir[MAXN];
vector<int> ng[MAXN], w[MAXN], ans[MAXN], id[MAXN];
bool mark[MAXN];
void dfs(int x) {
  if (x == n) return;
  mark[x] = true;
  for (int i = 0; i < ng[x].size(); i++) {
    int u = ng[x][i];
    if (!dir[id[x][i]]) {
      dir[id[x][i]] = ans[x][i];
      in[u] += w[x][i];
    }
    if (in[u] == all[u] / 2 && !mark[u]) dfs(u);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    ng[a].push_back(b);
    ng[b].push_back(a);
    w[a].push_back(c);
    w[b].push_back(c);
    ans[a].push_back(1);
    ans[b].push_back(2);
    id[a].push_back(i);
    id[b].push_back(i);
    all[a] += c;
    all[b] += c;
  }
  dfs(1);
  for (int i = 0; i < m; i++) cout << dir[i] - 1 << endl;
  return 0;
}
