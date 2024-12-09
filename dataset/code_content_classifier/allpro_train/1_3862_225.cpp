#include <bits/stdc++.h>
using namespace std;
const int M = 200009;
int n, q, k, x, s;
pair<int, int> p[M];
vector<int> pb[M];
set<int> last;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> s;
    p[i] = {x, s};
    pb[x].push_back(i);
  }
  for (int i = 1; i <= n; i++)
    if (pb[i].size() > 0) last.insert(last.end(), *pb[i].rbegin());
  last.insert(-1);
  cin >> q;
  for (; q; q--) {
    cin >> k;
    vector<int> esc(k);
    for (int i = 0; i < k; i++) {
      cin >> esc[i];
      if (pb[esc[i]].size() > 0) last.erase(*pb[esc[i]].rbegin());
    }
    pair<int, int> ans = {0, 0};
    if (last.size() != 1) {
      auto iw = --last.end();
      int win = p[*iw].first;
      auto bwin = *upper_bound(pb[win].begin(), pb[win].end(), *--iw);
      ans = {win, p[bwin].second};
    }
    cout << ans.first << " " << ans.second << endl;
    for (int i = 0; i < k; i++)
      if (pb[esc[i]].size() > 0) last.insert(last.end(), *pb[esc[i]].rbegin());
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  solve();
}
