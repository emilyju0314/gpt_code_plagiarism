#include <bits/stdc++.h>
using namespace std;
int n, Q, ans;
struct Zt {
  int l, r;
  bool num;
  bool operator<(const Zt &u) const {
    if (l != u.l) return l < u.l;
    return r < u.r;
  }
};
set<Zt> second;
set<Zt>::iterator it;
vector<set<Zt>::iterator> cle;
inline void cut(int u) {
  it = second.upper_bound((Zt){u, 0x3f3f3f3f, 0});
  it--;
  Zt tmp = (*it);
  second.erase(it);
  second.insert((Zt){tmp.l, u, tmp.num});
  if (u < tmp.r) second.insert((Zt){u + 1, tmp.r, tmp.num});
}
int main() {
  int i, j, p, q, o;
  cin >> n >> Q;
  ans = n;
  second.insert((Zt){1, n, 0});
  for (i = 1; i <= Q; i++) {
    scanf("%d%d%d", &p, &q, &o);
    if (p > 1) cut(p - 1);
    cut(q);
    it = second.upper_bound((Zt){p, 0x3f3f3f3f, 0});
    it--;
    cle.clear();
    for (; it != second.end() && (*it).r <= q; it++) {
      cle.push_back(it);
      Zt tmp = (*it);
      if (o == 1 && !tmp.num) ans -= tmp.r - tmp.l + 1;
      if (o == 2 && tmp.num) ans += tmp.r - tmp.l + 1;
    }
    for (j = 0; j < cle.size(); j++) second.erase(cle[j]);
    second.insert((Zt){p, q, o == 1});
    printf("%d\n", ans);
  }
}
