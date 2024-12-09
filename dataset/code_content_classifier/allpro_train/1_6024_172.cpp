#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > > adj(300001);
int T[300001][26], c[300001], indexNo[300001];
int s[300001];
void DFS(int i, int d) {
  queue<int> q;
  int nextIndex = 0;
  s[d + 1] -= adj[i].size();
  for (auto p : adj[i]) {
    DFS(p.second, d + 1);
    q.push(p.second);
  }
  while (!q.empty()) {
    i = q.front();
    q.pop();
    if (c[indexNo[i]] == 1) continue;
    for (auto p : adj[i]) {
      int j, k;
      tie(j, k) = p;
      if (T[indexNo[i]][j] == 0) T[indexNo[i]][j] = ++nextIndex;
      indexNo[k] = T[indexNo[i]][j];
      q.push(k);
      c[indexNo[k]]++;
    }
    indexNo[i] = 0;
  }
  for (i = 0; i <= nextIndex; i++) {
    s[d + 1] -= max(0, c[i] - 1);
    c[i] = 0;
    for (int j = 0; j < 26; j++) T[i][j] = 0;
  }
}
int main() {
  int n;
  pair<int, int> ans;
  scanf("%d", &n);
  for (int x = 1; x < n; x++) {
    int u, v;
    string sx;
    scanf("%d%d", &u, &v);
    cin >> sx;
    adj[u].push_back(make_pair(sx[0] - 'a', v));
  }
  for (int i = 0; i <= n; i++) s[i] = n;
  DFS(1, 0);
  ans = make_pair(n, 0);
  for (int i = 1; i <= n; i++) ans = min(ans, make_pair(s[i], i));
  printf("%d\n%d\n", ans.first, ans.second);
  return 0;
}
