#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300000 + 20, MAXM = 2 * 100000 + 10,
          MOD = 1000 * 1000 * 1000 + 7, INF = 1000 * 1000 * 1000;
pair<long long, int> p[3];
void solve() {
  for (long long i = 0, x; i < 3; i++) {
    cin >> x;
    p[i] = make_pair(x, i + 1);
  }
  sort(p, p + 3);
  cout << "First" << endl;
  cout << 2 * (p[2].first) - p[1].first - p[0].first << endl;
  int y;
  cin >> y;
  if (y == p[2].second) {
    p[2].first += 2 * (p[2].first) - p[1].first - p[0].first;
    cout << 2 * (p[2].first) - p[1].first - p[0].first << endl;
    cin >> y;
    if (y == 0) return;
    if (y == p[1].second) {
      cout << p[2].first - p[0].first << endl;
      cin >> y;
      return;
    } else {
      cout << p[2].first - p[1].first << endl;
      cin >> y;
      return;
    }
  } else {
    if (y == p[1].second) {
      cout << p[2].first - p[0].first << endl;
      cin >> y;
      return;
    } else {
      cout << p[2].first - p[1].first << endl;
      cin >> y;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
