#include <bits/stdc++.h>
using namespace std;
bool mark[1005] = {0};
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    mark[u] = mark[v] = 1;
  }
  int s = 0;
  for (int i = 1; i <= n; i++)
    if (mark[i] == 0) {
      s = i;
      break;
    }
  cout << n - 1 << endl;
  for (int i = 1; i <= n; i++)
    if (s != i) cout << s << " " << i << endl;
}
