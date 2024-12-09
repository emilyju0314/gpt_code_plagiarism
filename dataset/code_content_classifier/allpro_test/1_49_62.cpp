#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 5;
struct node {
  int l, k, id;
};
int t, n, q, x, cnt[MX], frq[MX], a[MX], ans[MX], o[MX];
vector<node> op[MX];
vector<int> v[MX], order;
void clean() {
  order.clear();
  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
    frq[i] = n;
    v[i].clear();
    op[i].clear();
    order.push_back(i);
    o[i] = i - 1;
  }
  frq[0] = n;
}
void dfs(int d, int p) {
  frq[cnt[a[d]]]--;
  int i = o[a[d]];
  int j = frq[cnt[a[d]]];
  swap(order[i], order[j]);
  o[order[i]] = i;
  o[order[j]] = j;
  cnt[a[d]]++;
  for (auto z : op[d]) {
    int kk = frq[z.l - 1];
    if (kk + z.k > order.size())
      ans[z.id] = -1;
    else
      ans[z.id] = order[kk + z.k - 1];
  }
  for (auto z : v[d])
    if (z != p) dfs(z, d);
  cnt[a[d]]--;
  i = o[a[d]];
  j = frq[cnt[a[d]]];
  swap(order[i], order[j]);
  o[order[i]] = i;
  o[order[j]] = j;
  frq[cnt[a[d]]]++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &q);
    clean();
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 2; i <= n; i++) {
      scanf("%d", &x);
      v[x].push_back(i);
      v[i].push_back(x);
    }
    for (int i = 1; i <= q; i++) {
      int l, k;
      scanf("%d%d%d", &x, &l, &k);
      op[x].push_back({l, k, i});
    }
    dfs(1, 0);
    for (int i = 1; i <= q; i++) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
