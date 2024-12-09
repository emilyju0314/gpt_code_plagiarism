#include <bits/stdc++.h>
using namespace std;
class DKilaniAndTheGame {
 public:
  static void solve(istream& in, ostream& out) {
    int n, m;
    in >> n >> m;
    int p;
    in >> p;
    vector<int> s(p + 1);
    for (int i = 1; i <= p; ++i) {
      in >> s[i];
    }
    queue<pair<int, int>> q[p + 1];
    vector<vector<int>> field(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        in >> c;
        if (c == '#')
          field[i][j] = -1;
        else if (c == '.')
          field[i][j] = 0;
        else {
          field[i][j] = c - '0';
          q[c - '0'].push({i, j});
        }
      }
    }
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    while (true) {
      bool flag = false;
      for (int i = 1; i <= p; ++i) {
        for (int step = 0; step < s[i]; ++step) {
          if (q[i].empty()) break;
          queue<pair<int, int>> nq;
          while (!q[i].empty()) {
            auto t = q[i].front();
            q[i].pop();
            for (int j = 0; j < 4; ++j) {
              int nx = t.first + dx[j];
              int ny = t.second + dy[j];
              if (nx >= 0 && nx < n && ny >= 0 && ny < m && !field[nx][ny]) {
                flag = true;
                field[nx][ny] = i;
                nq.push({nx, ny});
              }
            }
          }
          swap(q[i], nq);
        }
      }
      if (!flag) break;
    }
    vector<int> ans(p + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (field[i][j] == -1) continue;
        ++ans[field[i][j]];
      }
    }
    for (int i = 1; i <= p; ++i) {
      if (i > 1) out << " ";
      out << ans[i];
    }
    out << '\n';
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  DKilaniAndTheGame::solve(in, out);
  return 0;
}
