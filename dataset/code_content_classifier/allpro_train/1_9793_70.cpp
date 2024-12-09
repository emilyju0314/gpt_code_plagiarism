#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100, inF = N;
int n, m, k, dis[N];
string s;
vector<string> ans;
queue<int> Q;
vector<int> vec[N];
vector<pair<int, int> > nei[N];
void input() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    nei[--u].push_back(pair<int, int>(--v, i));
    nei[v].push_back(pair<int, int>(u, i));
  }
}
void act(int v) {
  for (pair<int, int> e : nei[v]) {
    int u = e.first;
    if (dis[u] == inF || dis[u] == dis[v] + 1) {
      if (dis[u] == inF) Q.push(u);
      dis[u] = dis[v] + 1;
      vec[u].push_back(e.second);
    }
  }
}
void solve() {
  fill(dis + 1, dis + n, inF);
  Q.push(0);
  while (Q.size()) {
    act(Q.front());
    Q.pop();
  }
}
void output() {
  cout << ans.size() << '\n';
  for (string s : ans) cout << s << '\n';
  exit(0);
}
void bk(int v = 1) {
  if (v == n) {
    ans.push_back(s);
    if (--k == 0) output();
    return;
  }
  for (int x : vec[v]) {
    s[x]++;
    bk(v + 1);
    s[x]--;
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  input();
  solve();
  for (int i = 0; i < m; i++) s.push_back('0');
  bk();
  output();
  return 0;
}
