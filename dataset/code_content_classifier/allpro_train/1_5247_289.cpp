#include <bits/stdc++.h>
using namespace std;
const int N = 7e3 + 5;
int n;
int f[N][2];
int deg[N][2];
vector<int> steps[2];
inline void init() {
  scanf("%d", &n);
  scanf("%d", deg[0]);
  for (int i = 1, x; i <= deg[0][0]; i++)
    scanf("%d", &x), steps[0].push_back(x);
  scanf("%d", deg[0] + 1);
  for (int i = 1, x; i <= deg[0][1]; i++)
    scanf("%d", &x), steps[1].push_back(x);
}
queue<pair<int, int> > que;
void bfs() {
  memset(f, -1, sizeof(f));
  f[0][0] = f[0][1] = 0;
  que.push(pair<int, int>(0, 1)), que.push(pair<int, int>(0, 0));
  while (!que.empty()) {
    pair<int, int> e = que.front();
    que.pop();
    int p = e.second ^ 1;
    if (f[e.first][e.second] == 0)
      for (int i = 0; i < steps[p].size(); i++) {
        pair<int, int> eu((e.first - steps[p][i] + n) % n, p);
        if (f[eu.first][eu.second] == -1)
          f[eu.first][eu.second] = 1, que.push(eu);
      }
    else
      for (int i = 0; i < steps[p].size(); i++) {
        pair<int, int> eu((e.first - steps[p][i] + n) % n, p);
        --deg[eu.first][eu.second];
        if (f[eu.first][eu.second] == -1 && !deg[eu.first][eu.second])
          f[eu.first][eu.second] = 0, que.push(eu);
      }
  }
}
inline void solve() {
  for (int i = 1; i < n; i++) deg[i][0] = deg[i - 1][0];
  for (int i = 1; i < n; i++) deg[i][1] = deg[i - 1][1];
  bfs();
  for (int i = 1; i < n; i++)
    printf("%s ",
           (f[i][0] == 1) ? ("Win") : ((!f[i][0]) ? ("Lose") : ("Loop")));
  puts("");
  for (int i = 1; i < n; i++)
    printf("%s ",
           (f[i][1] == 1) ? ("Win") : ((!f[i][1]) ? ("Lose") : ("Loop")));
}
int main() {
  init();
  solve();
  return 0;
}
