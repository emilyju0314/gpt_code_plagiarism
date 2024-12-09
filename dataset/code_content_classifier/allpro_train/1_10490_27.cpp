#include <bits/stdc++.h>
using namespace std;
int dd[3000], a[20][3000], nw[30000], n, m, w[30000], dp[30000];
bool cmp(int x, int y) { return dd[x] > dd[y]; }
void sol() {
  cin >> n >> m;
  memset(dd, 0, sizeof(dd));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      dd[j] = max(dd[j], a[i][j]);
      w[j] = j;
    }
  }
  sort(w, w + m, cmp);
  memset(nw, 0, sizeof(nw));
  for (int x = 0; x < min(m, 12); x++) {
    int y = w[x];
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        if (!(mask >> i & 1)) {
          nw[mask | (1 << i)] = max(nw[mask | (1 << i)], nw[mask] + a[i][y]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        int nmask = (mask >> 1) | ((mask & 1) << (n - 1));
        nw[nmask] = max(nw[mask], nw[nmask]);
      }
    }
  }
  cout << nw[(1 << n) - 1] << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) sol();
  return 0;
}
