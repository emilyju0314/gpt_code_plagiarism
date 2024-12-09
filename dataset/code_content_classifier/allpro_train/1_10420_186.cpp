#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 123, M = 3e3 + 123, inf = 1e9 + 123, mod = 1e9 + 7;
const long long INF = 1e18;
pair<int, int> dir[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int cnt, n, m;
bool used[52][52];
char a[M][M];
bool check(int x, int y) { return (x >= 1 && x <= n && y >= 1 && y <= m); }
void dfs(int x, int y) {
  used[x][y] = 1;
  cnt++;
  for (int i = 0; i < 4; i++) {
    int tox = x + dir[i].first, toy = y + dir[i].second;
    if (check(tox, toy) && !used[tox][toy] && a[tox][toy] == '#') {
      dfs(tox, toy);
    }
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(NULL);
  cin >> n >> m;
  set<pair<int, int> > st;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#') {
        st.insert({i, j});
      }
    }
  }
  if (st.size() <= 2) {
    cout << -1;
    return 0;
  }
  for (auto it : st) {
    a[it.first][it.second] = '.';
    for (int i = 1; i <= n; i++) {
      bool ok = 0;
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '#') {
          memset(used, 0, sizeof(used));
          cnt = 0;
          dfs(i, j);
          if (cnt != st.size() - 1) {
            cout << 1;
            return 0;
          } else {
            ok = 1;
            break;
          }
        }
      }
      if (ok) {
        break;
      }
    }
    a[it.first][it.second] = '#';
  }
  cout << 2;
  return 0;
}
