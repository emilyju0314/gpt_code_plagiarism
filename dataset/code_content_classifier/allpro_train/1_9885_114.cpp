#include <bits/stdc++.h>
using namespace std;
const unsigned long long N = 300005;
int n, q, m;
set<pair<int, int> > s;
pair<int, int> v[N];
bool ok(int x, int y) {
  for (int i = 1; i < m; ++i) {
    int x1, y1;
    tie(x1, y1) = v[i];
    if (x1 != x && y1 != x && x1 != y && y1 != y) {
      return false;
    }
  }
  return true;
}
void solve() {
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    v[i] = {x, y};
  }
  for (auto x : {v[0].first, v[0].second}) {
    if (ok(x, -1)) {
      cout << "YES\n";
      return;
    }
    for (int i = 1; i < m; ++i) {
      int x1, y1;
      tie(x1, y1) = v[i];
      if (x != x1 && x != y1) {
        if (ok(x, x1) || ok(x, y1)) {
          cout << "YES\n";
          return;
        }
        break;
      }
    }
  }
  cout << "NO\n";
}
int main(int argc, char* argv[]) {
  solve();
  return 0;
}
