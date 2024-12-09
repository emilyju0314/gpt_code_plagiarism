#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> E[202020];
int P[202020][20];
int D[202020];
void dfs(int cur, int pre, int d) {
  P[cur][0] = pre;
  D[cur] = d;
  for (auto& e : E[cur])
    if (e != pre) dfs(e, cur, d + 1);
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> M;
  for (i = 0; i < (N - 1); i++) {
    cin >> x >> y;
    E[x - 1].push_back(y - 1);
    E[y - 1].push_back(x - 1);
  }
  dfs(0, 0, 0);
  for (i = 0; i < (18); i++)
    for (j = 0; j < (N); j++) P[j][i + 1] = P[P[j][i]][i];
  while (M--) {
    vector<pair<int, int>> V;
    cin >> x;
    while (x--) {
      cin >> y;
      y--;
      if (y) y = P[y][0];
      V.push_back({D[y], y});
    }
    sort((V.begin()), (V.end()));
    int ok = 1;
    for (i = 0; i < ((int)V.size() - 1); i++) {
      x = V[i].second;
      y = V[i + 1].second;
      for (j = 18; j >= 0; j--)
        if (D[y] - D[x] >= 1 << j) y = P[y][j];
      if (x != y) ok = 0;
    }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
