#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
void solve();
signed main() {
  srand('V' + 'a' + 'n' + 'k' + 'a' + 'T' + 'a' + 'g' + 'a' + 'n' + 'a' + 'i');
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
struct Ev {
  short int x, y, t;
  Ev() {}
  Ev(int a, int b, int c) : x(a), y(b), t(c) {}
};
void solve() {
  int n, m;
  cin >> n >> m;
  map<char, char> mp = {{'+', '+'}, {'-', '|'}, {'|', '-'}, {'^', '>'},
                        {'>', 'v'}, {'v', '<'}, {'<', '^'}, {'L', 'U'},
                        {'U', 'R'}, {'R', 'D'}, {'D', 'L'}, {'*', '*'}};
  vector<pair<short int, short int>> st = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<vector<char>> v(n, vector<char>(m, '.'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  pair<int, int> s, f;
  cin >> s.first >> s.second >> f.first >> f.second;
  vector<vector<vector<char>>> p(4,
                                 vector<vector<char>>(n, vector<char>(m, '.')));
  for (int i = 0; i < 4; i++) {
    p[i] = v;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        v[j][k] = mp[v[j][k]];
      }
    }
  }
  v.clear();
  vector<vector<vector<int>>> used(
      4, vector<vector<int>>(n, vector<int>(m, 1e9 + 7)));
  used[0][s.first - 1][s.second - 1] = 0;
  queue<Ev> q;
  q.emplace(s.first - 1, s.second - 1, 0);
  while (q.size() > 0) {
    Ev e = q.front();
    q.pop();
    int j = e.x, k = e.y, t = e.t;
    for (int i = 0; i < 4; i++) {
      int x = e.x + st[i].first, y = e.y + st[i].second;
      if (x >= 0 && x < n && y >= 0 && y < m) {
        if (i == 0) {
          if ((p[t][j][k] == '+' || p[t][j][k] == '|' || p[t][j][k] == 'v' ||
               p[t][j][k] == 'L' || p[t][j][k] == 'R' || p[t][j][k] == 'U') &&
              (p[t][x][y] == '+' || p[t][x][y] == '|' || p[t][x][y] == '^' ||
               p[t][x][y] == 'L' || p[t][x][y] == 'R' || p[t][x][y] == 'D') &&
              used[t][x][y] > used[t][j][k] + 1) {
            used[t][x][y] = used[t][j][k] + 1;
            q.emplace(x, y, t);
          }
        }
        if (i == 1) {
          if ((p[t][x][y] == '+' || p[t][x][y] == '|' || p[t][x][y] == 'v' ||
               p[t][x][y] == 'L' || p[t][x][y] == 'R' || p[t][x][y] == 'U') &&
              (p[t][j][k] == '+' || p[t][j][k] == '|' || p[t][j][k] == '^' ||
               p[t][j][k] == 'L' || p[t][j][k] == 'R' || p[t][j][k] == 'D') &&
              used[t][x][y] > used[t][j][k] + 1) {
            used[t][x][y] = used[t][j][k] + 1;
            q.emplace(x, y, t);
          }
        }
        if (i == 2) {
          if ((p[t][j][k] == '+' || p[t][j][k] == '-' || p[t][j][k] == '>' ||
               p[t][j][k] == 'L' || p[t][j][k] == 'D' || p[t][j][k] == 'U') &&
              (p[t][x][y] == '+' || p[t][x][y] == '-' || p[t][x][y] == '<' ||
               p[t][x][y] == 'D' || p[t][x][y] == 'R' || p[t][x][y] == 'U') &&
              used[t][x][y] > used[t][j][k] + 1) {
            used[t][x][y] = used[t][j][k] + 1;
            q.emplace(x, y, t);
          }
        }
        if (i == 3) {
          if ((p[t][x][y] == '+' || p[t][x][y] == '-' || p[t][x][y] == '>' ||
               p[t][x][y] == 'L' || p[t][x][y] == 'D' || p[t][x][y] == 'U') &&
              (p[t][j][k] == '+' || p[t][j][k] == '-' || p[t][j][k] == '<' ||
               p[t][j][k] == 'D' || p[t][j][k] == 'R' || p[t][j][k] == 'U') &&
              used[t][x][y] > used[t][j][k] + 1) {
            used[t][x][y] = used[t][j][k] + 1;
            q.emplace(x, y, t);
          }
        }
      }
    }
    if (used[(e.t + 1) % 4][e.x][e.y] > used[e.t][e.x][e.y] + 1) {
      used[(e.t + 1) % 4][e.x][e.y] = used[e.t][e.x][e.y] + 1;
      q.emplace(e.x, e.y, (e.t + 1) % 4);
    }
  }
  int ans = 1e9;
  for (int i = 0; i < 4; i++) {
    ans = min(ans, used[i][f.first - 1][f.second - 1]);
  }
  if (ans == 1e9) {
    cout << -1;
    return;
  }
  cout << ans;
  return;
}
