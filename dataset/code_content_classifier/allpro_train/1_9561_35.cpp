#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
const int knightDir[8][2] = {{-2, -1}, {-2, 1}, {-1, 2},  {1, 2},
                             {2, -1},  {2, 1},  {-1, -2}, {1, -2}};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const long long MOD = 1000000000 + 7;
int graph[105][105];
int has[105], vis[105];
void dfs(int pre, int now) {
  vis[now] = true;
  for (int i = 1; i <= 100; i++) {
    if (graph[now][i] == i && pre == i)
      continue;
    else if (graph[now][i] && !vis[i])
      dfs(now, i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int c = 0;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      if (k == 0) c++;
      vector<int> v;
      for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        has[x] = 1;
      }
      for (int i = 1; i < k; i++) {
        graph[v[i - 1]][v[i]] = 1;
        graph[v[i]][v[i - 1]] = 1;
      }
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
      if (has[i] && !vis[i]) {
        dfs(-1, i);
        cnt++;
      }
    }
    if (cnt == 0) cnt++;
    cout << cnt + c - 1 << endl;
  }
}
