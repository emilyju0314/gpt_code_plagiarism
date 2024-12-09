#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, q, rb, ff, ans;
bool vis[N];
vector<int> note[N];
int main() {
  scanf("%d%d", &n, &q);
  rb = ff = ans = 0;
  int type, c;
  while (q--) {
    scanf("%d%d", &type, &c);
    if (type == 1) {
      note[c].push_back(++ff);
      ans++;
    } else if (type == 2) {
      for (int i = 0; i < note[c].size(); i++) {
        if (vis[note[c][i]]) continue;
        vis[note[c][i]] = 1;
        ans--;
      }
      note[c].clear();
    } else {
      while (rb < c) {
        rb++;
        if (!vis[rb]) {
          vis[rb] = 1;
          ans--;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
