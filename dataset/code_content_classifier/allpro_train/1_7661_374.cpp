#include <bits/stdc++.h>
using namespace std;
long long int n, m, q, f = 0;
bitset<102> d[102][102];
long long int e;
int main() {
  cin >> n >> m;
  for (long long int i = 0; i < m; i++) {
    long long int a, b, c;
    cin >> a >> b >> c;
    d[a][b].set(c);
    d[b][a].set(c);
  }
  for (long long int h = 1; h <= n; h++) {
    for (long long int i = 1; i <= n; i++) {
      for (long long int j = 1; j <= n; j++) d[i][j] |= (d[i][h] & d[h][j]);
    }
  }
  cin >> q;
  while (q--) {
    long long int u, v;
    cin >> u >> v;
    cout << d[u][v].count() << endl;
  }
}
