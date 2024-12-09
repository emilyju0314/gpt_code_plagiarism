#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n;
vector<pair<int, int> > segs, leftSegs;
bool cmp(pair<int, int> p1, pair<int, int> p2) { return p1.second < p2.second; }
set<int> ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int ii = 0; ii < n; ii++) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (a == b)
      ans.insert(a);
    else
      segs.push_back({a, b});
  }
  for (auto e : segs) {
    bool contain = false;
    for (auto p : ans)
      if (p >= e.first && p <= e.second) contain = true;
    if (!contain) leftSegs.push_back(e);
  }
  sort(leftSegs.begin(), leftSegs.end(), cmp);
  int ptr = 0;
  while (ptr < leftSegs.size()) {
    int t = ptr + 1;
    while (t < leftSegs.size() && leftSegs[ptr].second >= leftSegs[t].first)
      t++;
    ans.insert(leftSegs[ptr].second);
    ptr = t;
  }
  cout << ans.size() << "\n";
  for (auto a : ans) cout << a << " ";
}
