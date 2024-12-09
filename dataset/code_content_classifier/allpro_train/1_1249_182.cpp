#include <bits/stdc++.h>
using namespace std;
const int INF = 8;
void debug(const vector<vector<int> >& A) {
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < A[i].size(); ++j) cerr << A[i][j];
    cerr << endl;
  }
  cerr << endl;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > A(n, vector<int>(n, INF));
  for (int i = 0; i < n; ++i) A[i][i] = 0;
  for (int i = 0; i < m; ++i) {
    int u, v, ok;
    cin >> u >> v >> ok;
    --u, --v;
    A[v][u] = A[u][v] = 1 ^ ok;
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (A[i][k] != INF && A[k][j] != INF) {
          if (A[i][j] == INF) A[i][j] = A[i][k] ^ A[k][j];
          if (A[i][j] != (A[i][k] ^ A[k][j])) {
            cout << "Impossible\n";
            return 0;
          }
        }
  vector<int> color(n, -1);
  for (int i = 0; i < n; ++i)
    if (color[i] == -1) {
      color[i] = 2 * i;
      for (int j = 0; j < n; ++j)
        if (A[i][j] != INF) color[j] = color[i] ^ A[i][j];
    }
  vector<bool> flip(n);
  for (int i = 0; i < n; ++i) {
    int c1 = 2 * i, c2 = 2 * i + 1;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
      if (color[i] == c1) ++cnt1;
      if (color[i] == c2) ++cnt2;
    }
    int flip_me = (cnt1 < cnt2) ? c1 : c2;
    for (int i = 0; i < n; ++i)
      if (color[i] == flip_me) flip[i] = true;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    if (flip[i]) ++cnt;
  cout << cnt << endl;
  for (int i = 0; i < n; ++i)
    if (flip[i]) cout << i + 1 << " ";
  return 0;
}
