#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4.1")
using namespace std;
int w, n, m;
vector<int> a;
vector<string> g;
bool read() {
  if (!(cin >> w >> n >> m)) return false;
  a = vector<int>(n);
  g = vector<string>(m);
  for (int i = 0; i < (int)(n); ++i) cin >> a[i];
  for (int i = 0; i < (int)(m); ++i) cin >> g[i];
  for (int i = 0; i < (int)(m); ++i) reverse((g[i]).begin(), (g[i]).end());
  return true;
}
vector<int> solve() {
  vector<int> pws(w + 1, 1);
  for (int i = 0; i < (int)((int)(pws).size()); ++i)
    if (i) pws[i] = pws[i - 1] * 3;
  vector<int> cnt_orig(pws[w]);
  vector<int> reach;
  for (int i = 0; i < (int)(n); ++i) {
    int mask = 0;
    for (int j = 0; j < (int)(w); ++j) mask += pws[j] * ((a[i] >> j) & 1);
    reach.push_back(mask);
    cnt_orig[mask]++;
  }
  sort((reach).begin(), (reach).end());
  reach.resize(unique((reach).begin(), (reach).end()) - reach.begin());
  vector<int> cnt(pws[w]);
  for (int x : reach)
    for (int y : reach) cnt[x + y] += cnt_orig[x] * cnt_orig[y];
  vector<int> ans(m);
  string cur;
  int id;
  map<char, vector<int> > go_rec;
  go_rec['A'] = {0, 1};
  go_rec['O'] = {0};
  go_rec['X'] = {0, 2};
  go_rec['a'] = {2};
  go_rec['o'] = {1, 2};
  go_rec['x'] = {1};
  function<void(int, int)> rec = [&](int pos, int mask) {
    if (pos == w) {
      ans[id] += cnt[mask];
      return;
    }
    const char ch = cur[pos];
    auto it = go_rec.find(ch);
    assert(it != go_rec.end());
    for (int bit : it->second) rec(pos + 1, mask + pws[pos] * bit);
  };
  for (int i = 0; i < (int)(m); ++i) {
    cur = g[i];
    id = i;
    rec(0, 0);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  while (read()) {
    auto ans = solve();
    for (int x : ans) cout << x << '\n';
  }
  return 0;
}
