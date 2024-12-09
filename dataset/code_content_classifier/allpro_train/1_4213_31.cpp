#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
void solve(bool);
void precalc();
clock_t start;
int main() {
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  precalc();
  cout.precision(10);
  cout << fixed;
  int testNum = 1;
  while (t--) {
    solve(true);
  }
  cout.flush();
  return 0;
}
void precalc() {}
template <typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}
const int INF = (int)1e9;
vector<vector<int>> g;
vector<int> mt;
vector<char> used;
int n, m, t, k;
bool dfs(int v) {
  if (used[v]) {
    return false;
  }
  used[v] = true;
  for (int i = 0; i < n; ++i) {
    if (!g[v][i]) {
      continue;
    }
    int to = i;
    if (mt[to] == -1) {
      mt[to] = v;
      return true;
    }
    if (dfs(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}
int get_matching() {
  mt.assign(n, -1);
  int res = 0;
  for (int i = 0; i < t; ++i) {
    used.assign(n, false);
    if (dfs(i)) {
      ++res;
    }
    if (res >= k) {
      return res;
    }
  }
  return res;
}
void solve(bool read) {
  cin >> n >> m >> t >> k;
  vector<int> start(t);
  for (int i = 0; i < t; ++i) {
    cin >> start[i];
    --start[i];
  }
  vector<vector<int>> matrix(n, vector<int>(n, INF));
  for (int i = 0; i < n; ++i) {
    matrix[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int a, b, wei;
    cin >> a >> b >> wei;
    --a;
    --b;
    relax_min(matrix[a][b], wei);
    relax_min(matrix[b][a], wei);
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        relax_min(matrix[i][j], matrix[i][k] + matrix[k][j]);
      }
    }
  }
  g.assign(t, vector<int>(n, 0));
  int L = -1, R = INF;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    for (int i = 0; i < t; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[start[i]][j] <= M) {
          g[i][j] = 1;
        } else {
          g[i][j] = 0;
        }
      }
    }
    int match = get_matching();
    if (match >= k) {
      R = M;
    } else {
      L = M;
    }
  }
  int ans = R;
  if (R == INF) {
    ans = -1;
  }
  cout << ans << endl;
}
