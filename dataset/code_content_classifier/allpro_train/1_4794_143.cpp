#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
void MaxMercury() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  int t, sx, sy, ex, ey;
  cin >> t >> sx >> sy >> ex >> ey;
  bool doplyvu = false;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'E') {
      if (sx >= ex) continue;
      ;
      sx++;
    }
    if (s[i] == 'W') {
      if (sx <= ex) continue;
      ;
      sx--;
    }
    if (s[i] == 'S') {
      if (sy <= ey) continue;
      ;
      sy--;
    }
    if (s[i] == 'N') {
      if (sy >= ey) continue;
      ;
      sy++;
    }
    if (sx == ex && sy == ey) {
      cout << i + 1 << endl;
      doplyvu = true;
      return;
    }
  }
  cout << -1;
}
int main() {
  MaxMercury();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
