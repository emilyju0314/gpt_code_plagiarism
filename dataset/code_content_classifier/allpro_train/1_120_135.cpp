#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[500], b[1000];
  for (int i = 0; i < n; i++) cin >> a[i];
  int c = 0;
  vector<pair<int, int> > f(n, make_pair(1000, 0));
  for (int i = 0; i < n; i++) f[i].second = i;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i]--;
    if (f[b[i]].first == 1000) {
      f[b[i]].first = ++c;
    }
  }
  int w = 0, x;
  for (int i = 0; i < m; i++) {
    sort(f.begin(), f.end());
    for (int j = 0; j < n; j++) {
      if (f[j].second == b[i]) {
        x = j;
        break;
      }
    }
    for (int j = 0; j < x; j++) {
      w += a[f[j].second];
      f[j].first++;
    }
    f[x].first = 1;
  }
  cout << w;
  return 0;
}
