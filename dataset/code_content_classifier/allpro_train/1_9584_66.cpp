#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int d[5555][5555][2];
int n, b;
vector<int> g[5555];
int c[5555];
int k[5555];
int sz[5555];
const int inf = int(1e9) + 31;
void go(int v) {
  sz[v] = 1;
  for (int i : g[v]) {
    go(i);
    sz[v] += sz[i];
  }
  auto& cd = d[v];
  cd[0][0] = 0;
  cd[1][0] = c[v];
  cd[1][1] = k[v];
  int cr = 1;
  for (int i : g[v]) {
    for (int j = cr + sz[i]; j > 0; j--) {
      for (int k = max(1, j - cr); k <= j && k <= sz[i]; k++) {
        cd[j][0] = min(cd[j][0], cd[j - k][0] + d[i][k][0]);
        cd[j][1] = min(cd[j][1], cd[j - k][1] + d[i][k][1]);
        cd[j][1] = min(cd[j][1], cd[j - k][1] + d[i][k][0]);
      }
    }
    cr += sz[i];
  }
}
void solve(istream& cin, ostream& cout) {
  fill((int*)d, (int*)d + 5555 * 5555 * 2, inf);
  cin >> n >> b;
  for (int i = (0); i < int(n); ++i) {
    cin >> c[i] >> k[i];
    k[i] = c[i] - k[i];
    if (i) {
      int p;
      cin >> p;
      --p;
      g[p].push_back(i);
    }
  }
  go(0);
  for (int i = n; i >= 0; i--) {
    if (min(d[0][i][0], d[0][i][1]) <= b) {
      cout << i;
      return;
    }
  }
  assert(false);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve(cin, cout);
  return 0;
}
