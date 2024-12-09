#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > gg[1100];
int p[1100000];
int x[3], y[3];
inline int SQ(int x) { return x * x; }
bool check() {
  if (x[1] * x[2] + y[1] * y[2] != 0) return false;
  if (x[0] == x[1] || x[0] == x[2] || x[1] == x[2]) return false;
  if (y[0] == y[1] || y[0] == y[2] || y[1] == y[2]) return false;
  if (x[1] * x[1] + y[1] * y[1] + x[2] * x[2] + y[2] * y[2] !=
      SQ(x[2] - x[1]) + SQ(y[2] - y[1]))
    return false;
  return true;
}
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};
int main() {
  for (int i = 0; i * i < 1100000; ++i) p[i * i] = i;
  for (int k = 1; k <= 1000; ++k) {
    for (int i = 1; i < k; ++i) {
      int j = k * k - i * i;
      if (p[j] == 0) continue;
      for (int _ = 0; _ < 4; ++_) {
        gg[k].push_back(make_pair(i * dx[_], p[j] * dy[_]));
      }
    }
  }
  for (int A, B; cin >> A >> B;) {
    bool ok = false;
    x[0] = 0, y[0] = 0;
    for (int i = 0; !ok && i < gg[A].size(); ++i)
      for (int j = 0; !ok && j < gg[B].size(); ++j) {
        x[1] = gg[A][i].first, y[1] = gg[A][i].second;
        x[2] = gg[B][j].first, y[2] = gg[B][j].second;
        if (check()) ok = true;
      }
    if (!ok) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 0; i < 3; ++i) cout << x[i] << " " << y[i] << endl;
  }
  return 0;
}
