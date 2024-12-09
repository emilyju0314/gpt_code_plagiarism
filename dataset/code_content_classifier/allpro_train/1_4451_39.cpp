#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int m, b[N], Q, vis[N], pre[N], anc[N];
vector<pair<int, int> > q[N];
int ans[N], cnt = 0;
struct fenwick {
  int t[N];
  void add(int x, int v) {
    x++;
    for (int i = x; i <= m + 1; i += i & (-i)) t[i] += v;
    return;
  }
  int cal(int x) {
    x++;
    int res = 0;
    for (int i = x; i > 0; i -= i & (-i)) res += t[i];
    return res;
  }
} s, t;
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  scanf("%d", &Q);
  int l, r;
  for (int amo = 1; amo <= Q; amo++) {
    scanf("%d%d", &l, &r);
    q[r].push_back(make_pair(l, amo));
  }
  for (int i = 1; i <= m; i++) {
    if (vis[b[i]]) s.add(vis[b[i]], -1);
    pre[i] = vis[b[i]];
    if (pre[i]) t.add(anc[pre[i]] + 1, -1), t.add(pre[i] + 1, 1);
    anc[i] = anc[pre[i]];
    vis[b[i]] = i;
    if (pre[pre[i]] && i - pre[i] != pre[i] - pre[pre[i]]) anc[i] = pre[pre[i]];
    s.add(i, 1);
    t.add(anc[i] + 1, 1), t.add(i + 1, -1);
    for (int j = 0; j < (int)q[i].size(); j++) {
      int l = q[i][j].first, id = q[i][j].second;
      ans[id] += s.cal(i) - s.cal(l - 1) + 1;
      if (t.cal(l) > 0) ans[id]--;
    }
  }
  for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
  return 0;
}
