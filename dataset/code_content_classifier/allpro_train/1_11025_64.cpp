#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 5e3 + 10;
vector<int> v[N];
int main() {
  int n;
  scanf("%d", &n);
  set<pair<int, int>> sp;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    int sz;
    int a, x, y, m;
    scanf("%d%d%d%d%d", &sz, &a, &x, &y, &m);
    auto& vp = v[i];
    vp.push_back(a);
    tot += sz;
    while (vp.size() < sz) {
      a = (1LL * a * x + y) % m;
      vp.push_back(a);
    }
    reverse(vp.begin(), vp.end());
    sp.emplace(vp.back(), i);
  }
  int pre = -1;
  int res = 0;
  vector<pair<int, int>> ans;
  while (!sp.empty()) {
    auto iter = sp.lower_bound(make_pair(pre, -1));
    if (iter == sp.end()) iter = sp.begin(), res++;
    int val, o;
    tie(val, o) = *iter;
    sp.erase(iter);
    if (tot <= 200000) ans.emplace_back(val, o);
    pre = val;
    v[o].pop_back();
    if (v[o].empty()) continue;
    sp.emplace(v[o].back(), o);
  }
  printf("%d\n", res);
  for (auto& p : ans) printf("%d %d\n", p.first, p.second);
  return 0;
}
