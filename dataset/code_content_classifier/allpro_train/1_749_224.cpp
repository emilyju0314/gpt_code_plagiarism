#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > p, q;
void solve(int st, int ed) {
  if (st >= ed) return;
  if (ed - st == 1) {
    q.push_back(p[st]);
    return;
  }
  int md = (st + ed) / 2;
  solve(st, md);
  solve(md, ed);
  for (int i = st; i < ed; i++) {
    q.push_back(make_pair(p[md].first, p[i].second));
  }
}
int main() {
  scanf("%d", &n);
  p.resize(n);
  for (int i = 0; i < n; i++) scanf("%d%d", &p[i].first, &p[i].second);
  sort(p.begin(), p.end());
  q.clear();
  solve(0, n);
  sort(q.begin(), q.end());
  vector<pair<int, int> > ans;
  ans.push_back(q.front());
  for (int i = 1; i < (int)q.size(); i++)
    if (ans.back() != q[i]) ans.push_back(q[i]);
  int m = ans.size();
  printf("%d\n", m);
  for (int i = 0; i < m; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
