#include <bits/stdc++.h>
int main() {
  int n, k;
  int d[300][300];
  int a, b, c;
  long long r[300] = {};
  std::ios::sync_with_stdio(false);
  std::scanf("%d", &n);
  for (int i(0); i < n; ++i) {
    for (int j(0); j < n; ++j) std::scanf("%d", &d[i][j]);
  }
  std::scanf("%d", &k);
  for (int h(0); h < k; ++h) {
    std::scanf("%d%d%d", &a, &b, &c);
    --a, --b;
    if (h == 0 || c < d[a][b]) {
      d[a][b] = d[b][a] = std::min(d[a][b], c);
      for (int i(0); i < n; ++i) {
        for (int j(i + 1); j < n; ++j) {
          d[i][j] = d[j][i] = std::min({d[i][j], d[i][a] + d[a][b] + d[b][j],
                                        d[i][b] + d[b][a] + d[a][j]});
          r[h] += d[i][j];
        }
      }
    } else {
      r[h] = r[h - 1];
    }
  }
  for (int i(0); i < k; ++i) {
    if (0 < i) std::cout << ' ';
    std::cout << r[i];
  }
  std::cout << std::endl;
  return 0;
}
