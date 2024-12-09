#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 2e5 + 10;
int n, m, q, r[N], id[N], pos[N];
long long a[N];
unsigned long long ans[N];
vector<pair<int, int> > e[N];
pair<int, int> Q[N];
const long long inf = 1e15;
bool vis[N];
long long dis[N];
inline void dij() {
  for (int i = (1); i <= (n); i++) dis[i] = inf;
  priority_queue<pair<long long, long long> > q;
  q.push(make_pair(0, 1)), dis[1] = 0;
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto [v, w] : e[u])
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w, q.push(make_pair(-dis[v], v));
      }
  }
}
int pre[N];
bool flag[N];
long long mn_mn[N << 2], mn_mx[N << 2], mn2_mn[N << 2], mn2_mx[N << 2],
    tagmn2[N << 2], tagmn[N << 2];
unsigned long long v[N << 2], smn2[N << 2];
int mnpos[N << 2];
bool samemn[N << 2];
unordered_map<int, int> cnt2[N << 2];
int cnt[N << 2];
inline void Build(int u, int l, int r) {
  mn_mn[u] = mn_mx[u] = mn2_mn[u] = mn2_mx[u] = inf;
  samemn[u] = 1;
  for (int i = (l); i <= (r); i++)
    if (!flag[i]) ++cnt[u], ++cnt2[u][pre[i]];
  if (l == r) return;
  int mid = l + r >> 1;
  Build(u << 1, l, mid), Build(u << 1 ^ 1, mid + 1, r);
}
inline unsigned long long recalc(int u) {
  int t = cnt2[u][mnpos[u]];
  unsigned long long ret = (unsigned long long)mn_mn[u] * (cnt[u] - t);
  if (mn2_mn[u] != inf || mnpos[u] == 1)
    ret += (unsigned long long)(mnpos[u] != 1 ? mn2_mn[u] : mn_mn[u]) * t;
  return ret;
}
inline void updmn(int u, long long x, int y) {
  if (y == mnpos[u]) {
    mn_mn[u] = mn_mx[u] = tagmn[u] = x;
    if (mnpos[u] == 1) smn2[u] = (unsigned long long)cnt2[u][mnpos[u]] * x;
    v[u] = (unsigned long long)x * (cnt[u] - cnt2[u][mnpos[u]]) + smn2[u];
    return;
  }
  mn2_mn[u] = mn2_mx[u] = mn_mn[u], tagmn2[u] = mn_mn[u];
  samemn[u] = 1, mn_mn[u] = mn_mx[u] = x;
  tagmn[u] = x, mnpos[u] = y, v[u] = recalc(u);
  if (mn2_mn[u] != inf || mnpos[u] == 1)
    smn2[u] =
        (unsigned long long)(mnpos[u] != 1 ? mn2_mn[u] : mn_mn[u]) * cnt2[u][y];
  else
    smn2[u] = 0;
}
inline void updmn2(int u, long long x) {
  mn2_mn[u] = mn2_mx[u] = x, tagmn2[u] = x;
  if (mn2_mn[u] != inf || mnpos[u] == 1)
    smn2[u] = (unsigned long long)(mnpos[u] != 1 ? mn2_mn[u] : mn_mn[u]) *
              cnt2[u][mnpos[u]];
  else
    smn2[u] = 0;
  v[u] = recalc(u);
}
inline void push_down(int u) {
  if (tagmn[u])
    updmn(u << 1, tagmn[u], mnpos[u]), updmn(u << 1 ^ 1, tagmn[u], mnpos[u]),
        tagmn[u] = 0;
  if (tagmn2[u])
    updmn2(u << 1, tagmn2[u]), updmn2(u << 1 ^ 1, tagmn2[u]), tagmn2[u] = 0;
}
inline void push_up(int u) {
  v[u] = v[u << 1] + v[u << 1 ^ 1];
  mn_mn[u] = min(mn_mn[u << 1], mn_mn[u << 1 ^ 1]);
  mn_mx[u] = max(mn_mx[u << 1], mn_mx[u << 1 ^ 1]);
  mn2_mn[u] = min(mn2_mn[u << 1], mn2_mn[u << 1 ^ 1]);
  mn2_mx[u] = max(mn2_mx[u << 1], mn2_mx[u << 1 ^ 1]);
  samemn[u] = samemn[u << 1] & samemn[u << 1 ^ 1] &
              (mn_mn[u << 1] == mn_mn[u << 1 ^ 1] &&
               mnpos[u << 1] == mnpos[u << 1 ^ 1]);
  if (samemn[u])
    mnpos[u] = mnpos[u << 1], smn2[u] = smn2[u << 1] + smn2[u << 1 ^ 1];
  else
    smn2[u] = 0;
}
inline void update(int u, int l, int r, int ql, int qr, long long x, int y) {
  if (mn2_mx[u] <= x) return;
  if (l >= ql && r <= qr) {
    if (samemn[u]) {
      if (x < mn_mn[u] || (x == mn_mn[u] && y < mnpos[u])) {
        updmn(u, x, y);
        return;
      } else if (mn2_mn[u] > x) {
        updmn2(u, x);
        return;
      }
    }
  }
  int mid = l + r >> 1;
  push_down(u);
  if (ql <= mid) update(u << 1, l, mid, ql, qr, x, y);
  if (qr > mid) update(u << 1 ^ 1, mid + 1, r, ql, qr, x, y);
  push_up(u);
}
inline long long Query(int u, int l, int r, int ql) {
  if (l == r) return mn2_mn[u];
  int mid = l + r >> 1;
  push_down(u);
  if (ql <= mid)
    return Query(u << 1, l, mid, ql);
  else
    return Query(u << 1 ^ 1, mid + 1, r, ql);
}
inline void update(int x, long long y) {
  if (r[x] < n) update(1, 1, n, r[x] + 1, n, y, x);
}
int main() {
  n = read(), m = read(), q = read();
  for (int i = (1); i <= (n); i++) a[i] = read();
  for (int i = (1); i <= (m); i++) {
    int x = read(), y = read(), z = read();
    e[x].emplace_back(y, z), e[y].emplace_back(x, z);
  }
  dij();
  for (int i = (1); i <= (n); i++) id[i] = i;
  sort(id + 1, id + 1 + n, [=](int a, int b) { return dis[a] < dis[b]; });
  for (int i = (1); i <= (n); i++) pos[id[i]] = i;
  flag[1] = 1;
  for (int i = (2); i <= (n); i++) {
    for (auto [v, w] : e[id[i]])
      if (dis[v] + w == dis[id[i]]) {
        if (!pre[i])
          pre[i] = pos[v];
        else
          flag[i] = 1;
      }
  }
  r[n] = n;
  for (int i = (n - 1); i >= (1); i--)
    r[i] = dis[id[i]] == dis[id[i + 1]] ? r[i + 1] : i;
  Build(1, 1, n);
  for (int i = (1); i <= (q); i++) {
    Q[i].first = read(), Q[i].second = read();
    a[Q[i].first] += Q[i].second;
  }
  for (int i = (1); i <= (n); i++) update(i, a[id[i]]);
  for (int i = (q); i >= (1); i--) {
    ans[i] = v[1];
    a[Q[i].first] -= Q[i].second;
    update(pos[Q[i].first], a[Q[i].first]);
  }
  ans[0] = v[1];
  for (int i = (0); i <= (q); i++) printf("%llu\n", ans[i]);
}
