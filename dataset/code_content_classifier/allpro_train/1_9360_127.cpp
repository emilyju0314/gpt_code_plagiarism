#include <bits/stdc++.h>
using namespace std;
const int maxn = 101111;
int n, m, deg[maxn];
int main() {
  cin >> n >> m;
  m *= 2;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    deg[u]++;
    deg[v]++;
  }
  int num = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 1) {
      num++;
    }
  }
  cout << fixed << setprecision(18) << 1.0 * m / num << endl;
  return 0;
}
