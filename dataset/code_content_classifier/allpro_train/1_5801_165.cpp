#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int n, m;
string s[110];
int L[110][110];
int R[110][110];
int U[110][110];
int D[110][110];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    L[i][0] = s[i][0] == '*';
    for (int j = 1; j < m; j++) {
      if (s[i][j] == '.')
        L[i][j] = 0;
      else
        L[i][j] = L[i][j - 1] + 1;
    }
    R[i][m - 1] = s[i][m - 1] == '*';
    for (int j = m - 2; j >= 0; j--) {
      if (s[i][j] == '.')
        R[i][j] = 0;
      else
        R[i][j] += R[i][j + 1] + 1;
    }
  }
  for (int j = 0; j < m; j++) {
    U[0][j] = s[0][j] == '*';
    for (int i = 1; i < n; i++) {
      if (s[i][j] == '.')
        U[i][j] = 0;
      else
        U[i][j] = U[i - 1][j] + 1;
    }
    D[n - 1][j] = s[n - 1][j] == '*';
    for (int i = n - 2; i >= 0; i--) {
      if (s[i][j] == '.')
        D[i][j] = 0;
      else
        D[i][j] += D[i + 1][j] + 1;
    }
  }
  using P = tuple<int, int, int>;
  vector<P> vs;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int mx = min({U[i][j], R[i][j], D[i][j], L[i][j]});
      if (mx > 1) vs.emplace_back(i, j, mx - 1);
    }
  }
  int used[110][110] = {};
  for (auto v : vs) {
    int y, x, p;
    tie(y, x, p) = v;
    used[y][x] = 1;
    for (int d = 0; d < 4; d++) {
      int ny = y, nx = x;
      for (int i = 0; i < p; i++) {
        ny += dy[d];
        nx += dx[d];
        used[ny][nx] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*' && !used[i][j]) {
        cout << "-1" << endl;
        return 0;
      }
    }
  }
  cout << vs.size() << endl;
  for (auto v : vs) {
    int y, x, p;
    tie(y, x, p) = v;
    cout << y + 1 << " " << x + 1 << " " << p << endl;
  }
  return 0;
}
