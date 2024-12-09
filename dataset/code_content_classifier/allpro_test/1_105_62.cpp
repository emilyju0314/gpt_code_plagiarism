#include <bits/stdc++.h>
using namespace std;
const long long M = 2100000;
const long long N = 210000;
struct node {
  long long inx;
  long long a, b;
  long long m;
  long long lt, rt;
};
vector<node> odd_nodes[M];
vector<node> even_nodes[M];
bool cmp(node a, node b) {
  if (a.lt == b.lt)
    return a.rt > b.rt;
  else
    return a.lt < b.lt;
}
long long lt_ans[N], rt_ans[N];
set<long long> op;
int main() {
  ios::sync_with_stdio(false);
  long long tt;
  cin >> tt;
  while (tt--) {
    op.clear();
    long long m, n;
    cin >> n;
    long long a, b;
    for (long long i = 0; i < n; i++) {
      cin >> a >> b >> m;
      long long mn = max(0ll, a - m);
      long long tb = b - (m - (a - mn));
      long long mx = max(0ll, b - m);
      long long ta = a - (m - (b - mx));
      long long v = a + b - m;
      op.insert(v);
      odd_nodes[v].push_back({i, a, b, m, mn - tb, ta - mx});
    }
    long long ans = 0;
    for (auto &u : op) {
      auto &p = odd_nodes[u];
      if (p.empty()) continue;
      sort(p.begin(), p.end(), cmp);
      long long st = 0, ed = 1e9;
      for (long long i = 0; i < p.size(); i++) {
        if (p[i].lt > ed) {
          for (long long j = st; j < i; j++) {
            long long t = (p[j].a - p[j].b + p[j].m - ed) / 2;
            lt_ans[p[j].inx] = t;
            rt_ans[p[j].inx] = p[j].m - t;
          }
          ans++;
          ed = p[i].rt;
          st = i;
        } else {
          ed = min(ed, p[i].rt);
        }
      }
      ans++;
      for (long long j = st; j < p.size(); j++) {
        long long t = (p[j].a - p[j].b + p[j].m - ed) / 2;
        lt_ans[p[j].inx] = t;
        rt_ans[p[j].inx] = p[j].m - t;
      }
      p.clear();
    }
    cout << ans << endl;
    for (long long i = 0; i < n; i++)
      cout << lt_ans[i] << ' ' << rt_ans[i] << endl;
  }
  return 0;
}
