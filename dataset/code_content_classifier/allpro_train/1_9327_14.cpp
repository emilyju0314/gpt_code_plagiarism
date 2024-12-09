#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[60];
int c[60], d[60], e[60];
int main() {
  int i, j, k, m, n;
  double w;
  while (scanf("%d%lf%d", &n, &w, &m) != EOF) {
    for (i = 0; i < n; i++) d[i] = m;
    memset(c, 0, sizeof(c));
    k = 0;
    int f = 0;
    for (i = 0; i < m; i++) a[i].clear();
    for (i = 0; i < n; i++) {
      int cnt = 0;
      while (d[i] > 0) {
        if (d[i] >= n - c[k]) {
          a[k].push_back(make_pair(i, n - c[k]));
          d[i] -= n - c[k];
          c[k] = n;
          k++;
        } else {
          a[k].push_back(make_pair(i, d[i]));
          c[k] += d[i];
          d[i] = 0;
        }
        cnt++;
      }
      if (cnt > 2) f = 1;
    }
    if (f) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (i = 0; i < m; i++) {
      for (j = 0; j < a[i].size(); j++) {
        printf("%d %.10lf%c", a[i][j].first + 1, a[i][j].second * w / m,
               j < a[i].size() - 1 ? ' ' : '\n');
      }
    }
  }
}
