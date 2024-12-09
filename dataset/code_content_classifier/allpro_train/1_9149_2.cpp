#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct cht {
  vector<long long> m, b;
  vector<int> id;
  int ptr = 0;
  bool bad(int l1, int l2, int l3) {
    return 1.0 * (b[l3] - b[l1]) * (m[l1] - m[l2]) <=
           1.0 * (b[l2] - b[l1]) * (m[l1] - m[l3]);
  }
  void add(long long _m, long long _b, int idx) {
    m.push_back(_m);
    b.push_back(_b);
    id.push_back(idx);
    int s = m.size();
    while (s >= 3 && bad(s - 3, s - 2, s - 1)) {
      m.erase(m.end() - 2);
      b.erase(b.end() - 2);
      id.erase(id.end() - 2);
      s--;
    }
  }
  long long f(int i, long long x) { return m[i] * x + b[i]; }
  pair<long long, int> query(long long x) {
    if (ptr >= m.size()) ptr = m.size() - 1;
    while (ptr < m.size() - 1 && f(ptr + 1, x) > f(ptr, x)) ptr++;
    return {f(ptr, x), id[ptr]};
  }
};
pair<long long, long long> line[maxn];
cht t[maxn << 2];
void build(int node, int l, int r) {
  vector<pair<pair<long long, long long>, int> > v;
  for (int i = l; i <= r; i++) v.emplace_back(line[i], i);
  sort(v.begin(), v.end());
  for (auto x : v) t[node].add(x.first.first, x.first.second, x.second);
  if (l == r) return;
  int m = l + r >> 1;
  build(node << 1, l, m);
  build(node << 1 | 1, m + 1, r);
}
pair<long long, int> merge(pair<long long, int> a, pair<long long, int> b) {
  if (a.first >= b.first)
    return a;
  else
    return b;
}
pair<long long, int> query(int node, int l, int r, int i, int j, long long x) {
  if (r < i || l > j) return {-1, -1};
  if (i <= l && r <= j) return t[node].query(x);
  int m = l + r >> 1;
  return merge(query(node << 1, l, m, i, j, x),
               query(node << 1 | 1, m + 1, r, i, j, x));
}
struct query {
  int l, r, t, id;
  bool operator<(const query &q) const { return t < q.t; }
} Q[maxn];
long long ans[maxn];
int main(int argc, char const *argv[]) {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld %lld", &line[i].second, &line[i].first);
  }
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    scanf("%d %d %d", &Q[i].l, &Q[i].r, &Q[i].t);
    Q[i].id = i;
  }
  sort(Q + 1, Q + q + 1);
  for (int i = 1; i <= q; i++) {
    ans[Q[i].id] = query(1, 1, n, Q[i].l, Q[i].r, Q[i].t).second;
  }
  for (int i = 1; i <= q; i++) {
    printf("%lld\n", ans[i]);
  }
}
