#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int p[300005], a[300005], vis[300005];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  cout << 1 << ' ';
  int cnt = 0, ed = n, cnted = 0;
  for (int i = 1; i <= n; i++) {
    a[p[i]] = 1;
    for (int j = ed; j > 0; j--) {
      if (a[j] == 1) {
        if (vis[j] == 0) cnted++;
        vis[j] = 1;
        ed = j;
      } else
        break;
    }
    cnt++;
    cout << cnt - cnted + 1 << ' ';
  }
  return 0;
}
