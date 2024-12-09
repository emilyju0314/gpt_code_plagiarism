#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, MOD = 1e9 + 7, inf = 1e9 + 10;
bool mark[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, pos = 1, x, u, v;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) cin >> x, mark[x] = true;
  if (mark[1]) return cout << 1, 0;
  for (int i = 0; i < k; i++) {
    cin >> u >> v;
    if (v == pos) swap(u, v);
    if (u == pos) pos = v;
    if (mark[pos]) {
      cout << pos;
      return 0;
    }
  }
  cout << pos;
  return 0;
}
