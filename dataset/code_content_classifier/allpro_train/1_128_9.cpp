#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int b[MAXN];
vector<int> a[MAXN], d, c;
bool mark[MAXN];
void dfs(int v) {
  mark[v] = true;
  c.push_back(v);
  d.push_back(b[v]);
  for (int i = 0; i < a[v].size(); i++)
    if (mark[a[v][i]] == false) dfs(a[v][i]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> b[i];
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for (int i = 0; i < n; i++) {
    c.clear();
    d.clear();
    if (mark[i] == false) dfs(i);
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    for (int j = 0; j < c.size(); j++) b[c[j]] = d[j];
  }
  for (int i = 0; i < n; i++) cout << b[i] << ' ';
  cout << endl;
  return 0;
}
