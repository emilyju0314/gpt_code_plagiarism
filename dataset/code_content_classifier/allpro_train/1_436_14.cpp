#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, M = 20, INF = 1e9;
int n, m, a[N], lst[M], go[M][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < M; j++) {
    lst[j] = n + 1;
  }
  memset(go, 63, sizeof(go));
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < M; j++) {
      if ((a[i] >> j) & 1) {
        for (int k = 0; k < M; k++) {
          go[k][i] = min(go[k][i], go[k][lst[j]]);
        }
        lst[j] = i;
        go[j][i] = i;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    bool p = false;
    for (int j = 0; j < M; j++) {
      p |= (((a[y] >> j) & 1) && go[j][x] <= y);
    }
    cout << (p ? "Shi" : "Fou") << "\n";
  }
}
