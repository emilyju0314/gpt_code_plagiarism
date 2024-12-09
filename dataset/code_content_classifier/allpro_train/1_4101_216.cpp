#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, t, p;
  scanf("%d %d %d", &n, &s, &t);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> p;
    mp[i + 1] = p;
  }
  bool vis[100005];
  memset(vis, false, sizeof(vis));
  int cnt = 0;
  for (int i = 0; i < 100000; i++) {
    if (s == t) break;
    s = mp[s];
    if (vis[s]) {
      cnt = -1;
      break;
    }
    vis[s] = true;
    cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
