#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 15;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int n, m, c, c0;
map<long long, long long> ma;
long long tot;
long long ans = 0;
bool f;
void ins(long long liter, long long val) {
  long long emp = c - tot;
  long long aa = min(emp, liter);
  ma[val] += aa;
  tot += aa;
  liter -= aa;
  if (liter == 0) return;
  while (liter) {
    auto p = ma.rbegin();
    long long cntval = p->first;
    long long cntliter = p->second;
    if (cntval <= val) return;
    ma.erase(--ma.end());
    long long bb = min(cntliter, liter);
    cntliter -= bb;
    liter -= bb;
    ma[val] += bb;
    if (cntliter) ma[cntval] += cntliter;
  }
}
void consume(long long liter) {
  if (tot < liter) {
    f = 0;
    return;
  }
  tot -= liter;
  while (liter) {
    auto p = ma.begin();
    long long rig = p->second;
    long long val = p->first;
    long long need = min(rig, liter);
    liter -= need;
    ans += need * val;
    ma.erase(ma.begin());
    rig -= need;
    if (rig) ma[val] += rig;
  }
  return;
}
struct node {
  int t, a, b;
} p[maxn];
bool cmp(node a, node b) { return a.t < b.t; }
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &n, &m, &c, &c0);
    ma.clear();
    tot = 0;
    ans = 0;
    f = 1;
    ins(c0, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &p[i].t, &p[i].a, &p[i].b);
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1, t, a, b; i <= n; i++) {
      t = p[i].t;
      a = p[i].a;
      b = p[i].b;
      int ttt = t - cnt;
      consume(ttt);
      ins(a, b);
      cnt = t;
    }
    int ttt = m - cnt;
    consume(ttt);
    if (f == 0)
      puts("-1");
    else
      printf("%lld\n", ans);
  }
  return 0;
}
