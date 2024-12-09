#include <bits/stdc++.h>
using namespace std;
int p[100005];
int vis[1000005];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) vis[p[i]] = i;
    int last = n, f = 1;
    p[0] = 1e8;
    for (int i = 1; i <= n; i++) {
      while (p[last] < i) last--;
      if (vis[i] == last) {
        last--;
        continue;
      } else {
        if (vis[i + 1] == vis[i] + 1) {
          continue;
        } else {
          f = 0;
          break;
        }
      }
    }
    if (f)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
