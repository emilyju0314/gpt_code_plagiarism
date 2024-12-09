#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
struct Query {
  int l, r, num;
  long long k;
  Query() {}
  Query(int l, int r, int num, long long k) : l(l), r(r), num(num), k(k) {}
  bool operator<(const Query &other) const { return k < other.k; }
};
int n, tcur, a[N], t[N], ans[N], lt[N], rt[N];
long long d[N], da[N];
vector<pair<int, int> > g[N];
pair<long long, int> p[N];
Query q[N];
vector<int> s[N];
void dfs(int v, int p, int w) {
  if (p == -1)
    d[v] = 0;
  else
    d[v] = d[p] + w;
  tcur++;
  lt[v] = tcur;
  rt[v] = tcur;
  da[lt[v]] = d[v] - a[v];
  for (int i = 0; i < g[v].size(); i++) {
    dfs(g[v][i].first, v, g[v][i].second);
    rt[v] = rt[g[v][i].first];
  }
}
void update(int pos) {
  while (pos <= 2 * n) {
    t[pos]++;
    pos |= pos + 1;
  }
}
int get(int r) {
  int res = 0;
  while (r > 0) {
    res += t[r];
    r &= r + 1;
    r--;
  }
  return res;
}
int sum(int l, int r) { return get(r) - get(l - 1); }
void compress(int n, long long *a, long long *b) {
  for (int i = 1; i <= n; i++) p[i] = make_pair(a[i], i);
  for (int i = 1; i <= n; i++) p[i + n] = make_pair(b[i], i + n);
  sort(p + 1, p + 2 * n + 1);
  int val = 1;
  for (int i = 1; i <= 2 * n; i++) {
    if (i > 1 && p[i].first != p[i - 1].first) val++;
    if (p[i].second <= n)
      a[p[i].second] = val;
    else
      b[p[i].second - n] = val;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) {
    int p, w;
    scanf("%d%d", &p, &w);
    g[p].push_back(make_pair(i, w));
  }
  tcur = 0;
  dfs(1, -1, 0);
  compress(n, d, da);
  for (int i = 1; i <= n; i++) q[i] = Query(lt[i] + 1, rt[i], i, d[i]);
  for (int i = 1; i <= n; i++) s[da[i]].push_back(i);
  sort(q + 1, q + n + 1);
  q[0] = Query(0, 0, 0, 0);
  for (int i = 1; i <= n; i++) {
    if (i == 1 || q[i].k != q[i - 1].k) {
      for (int j = q[i - 1].k + 1; j <= q[i].k; j++) {
        for (int k = 0; k < s[j].size(); k++) update(s[j][k]);
      }
    }
    ans[q[i].num] = sum(q[i].l, q[i].r);
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
