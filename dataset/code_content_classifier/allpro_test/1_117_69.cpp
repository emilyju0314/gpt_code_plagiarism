#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long INF = 1e9;
const double eps = 1e-9;
int dirl[4] = {0, 0, -1, 1};
int dirc[4] = {-1, 1, 0, 0};
int t, n, m;
vector<vector<char> > mat;
vector<vector<bool> > ___viz____;
int neighbour2(int i, int j) {
  int cnt = 0;
  for (int k = 0; k < 4; k++) {
    int i1 = i + dirl[k];
    int j1 = j + dirc[k];
    if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m)
      if (!___viz____[i1][j1] && mat[i1][j1] != '#') cnt++;
  }
  return cnt;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    mat.resize(n + 2);
    for (int i = 0; i < n + 2; i++) mat[i].resize(m + 2);
    ___viz____.resize(n + 2);
    for (int i = 0; i < n + 2; i++) ___viz____[i].resize(m + 2);
    int x1, y1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        cin >> mat[i][j];
        ___viz____[i][j] = 0;
        if (mat[i][j] == 'L') {
          x1 = i;
          y1 = j;
        }
      }
    queue<pair<int, int> > queue;
    queue.push({x1, y1});
    ___viz____[x1][y1] = 1;
    while (queue.size()) {
      auto iterator = queue.front();
      queue.pop();
      for (int k = 0; k < 4; k++) {
        int i = iterator.first + dirl[k];
        int j = iterator.second + dirc[k];
        if (i < 1 || j < 1 || i > n || j > m) continue;
        if (!___viz____[i][j] && mat[i][j] != '#' && neighbour2(i, j) <= 1) {
          queue.push({i, j});
          ___viz____[i][j] = 1;
        }
      }
    }
    for (int i = 1; i <= n; i++, cout << "\n")
      for (int j = 1; j <= m; j++)
        if (mat[i][j] == 'L' || mat[i][j] == '#')
          cout << mat[i][j];
        else {
          if (___viz____[i][j])
            cout << "+";
          else
            cout << ".";
        }
  }
  return 0;
}
