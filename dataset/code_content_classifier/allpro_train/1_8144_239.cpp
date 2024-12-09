#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int visited[N][N];
int a[N][N];
map<int, long long> mp;
class cmp {
 public:
  bool operator()(const pair<pair<int, int>, pair<int, int>> &s1,
                  const pair<pair<int, int>, pair<int, int>> &s2) {
    return ((s1.second.first + s1.second.second) <
            (s2.second.first + s2.second.second));
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, ox, oy, x, y;
  char ch;
  cin >> n >> m >> ox >> oy >> x >> y;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; j++) {
      cin >> ch;
      if (ch == '.') a[i][j] = 1;
    }
  }
  priority_queue<pair<pair<int, int>, pair<int, int>>,
                 vector<pair<pair<int, int>, pair<int, int>>>, cmp>
      f;
  f.push({{ox, oy}, {x, y}});
  pair<int, int> at, p;
  int bad = 0;
  set<pair<int, int>> s;
  int k = 0, u;
  visited[ox][oy] = 1;
  while (!f.empty()) {
    k++;
    at = f.top().first;
    p = f.top().second;
    f.pop();
    if (p.second < 0 || p.first < 0) continue;
    pair<int, int> aux;
    u = visited[at.first + 1][at.second];
    if ((u == bad) && a[at.first + 1][at.second]) {
      visited[at.first + 1][at.second] = 1;
      f.push({{at.first + 1, at.second}, p});
    }
    u = visited[at.first - 1][at.second];
    if ((u == bad) && a[at.first - 1][at.second]) {
      visited[at.first - 1][at.second] = 1;
      f.push({{at.first - 1, at.second}, p});
    }
    u = visited[at.first][at.second + 1];
    p.second--;
    if ((u == bad) && p.second >= 0 && a[at.first][at.second + 1]) {
      visited[at.first][at.second + 1] = 1;
      f.push({{at.first, at.second + 1}, p});
    }
    p.second++, p.first--;
    u = visited[at.first][at.second - 1];
    if ((u == bad) && p.first >= 0 && a[at.first][at.second - 1]) {
      visited[at.first][at.second - 1] = 1;
      f.push({{at.first, at.second - 1}, p});
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; j++) {
      if (visited[i][j]) ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
