#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w, m;
  cin >> n >> w >> m;
  double req = ((double)n * w) / m;
  double tot[n];
  for (int i = 0; i < n; i++) tot[i] = w;
  int used[n];
  memset(used, 0, sizeof(used));
  bool poss = true;
  vector<vector<pair<int, double> > > v(m);
  for (int j = 0; j < m; j++) {
    double p = 0;
    for (int i = 0; i < n; i++) {
      if (used[i] == 2) continue;
      if (tot[i] == 0) continue;
      if (p + tot[i] > req || (fabs(p + tot[i] - req) <= 1e-9)) {
        tot[i] -= (req - p);
        used[i]++;
        pair<int, double> rr(i + 1, req - p);
        p = req;
        v[j].push_back(rr);
        break;
      } else {
        used[i]++;
        p += tot[i];
        pair<int, double> rr(i + 1, tot[i]);
        tot[i] = 0;
        v[j].push_back(rr);
      }
    }
    if (p < req) {
      poss = false;
      break;
    }
  }
  if (poss) {
    cout << "YES" << endl;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < v[i].size() - 1; j++)
        printf("%d %.6f ", v[i][j].first, v[i][j].second);
      printf("%d %.6f\n", v[i][v[i].size() - 1].first,
             v[i][v[i].size() - 1].second);
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
