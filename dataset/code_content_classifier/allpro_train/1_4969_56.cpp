#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  int a, b, c;
  int p, q, r;
  int res = 0;
  cin >> n >> m;
  vector<vector<int> > v(n, vector<int>(3)), h(m, vector<int>(3));
  for (int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];
  for (int i = 0; i < m; i++) cin >> h[i][0] >> h[i][1] >> h[i][2];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      p = v[i][0], q = v[i][1], r = v[i][2];
      a = h[j][0], b = h[j][1], c = h[j][2];
      if (a < p and a + c > p and q < b and q + r > b) {
        res = max(res, min(p - a, min(a + c - p, min(b - q, q + r - b))));
      }
    }
  cout << res;
}
