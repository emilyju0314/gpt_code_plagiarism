#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const vector<int> mods = {998244353, 1000000007, 1000000009};
const int inf = 3e18;
const double pi = acos(-1.0);
const double eps = 0.0000001;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class... K>
using umap = unordered_map<K...>;
template <class... K>
using uset = unordered_set<K...>;
using l3 = array<int, 3>;
int n, h;
int query(const l3& qs) {
  cout << "? ";
  for (int i = (0); i < (3); ++i) cout << qs[i] + 1 << " \n"[i == 2];
  int r;
  cin >> r;
  return r - 1;
}
void ans(int res) { cout << "! " << res + 1 << '\n'; }
void solve(int _t) {
  cin >> h;
  n = (1LL << h) - 1;
  umap<int, int> fr;
  for (int i = (0); i < (420); ++i) {
    l3 tq;
    for (int i = (0); i < (3); ++i) tq[i] = rng() % n;
    if (tq[0] == tq[1] || tq[1] == tq[2] || tq[2] == tq[0]) continue;
    fr[query(tq)]++;
  }
  vector<pair<int, int> > is;
  for (auto& f_ : fr) {
    is.push_back({-f_.second, f_.first});
    sort(begin(is), end(is));
    if (((int)(is).size()) > 2) is.pop_back();
  }
  int c1 = is[0].second, c2 = is[1].second;
  for (int i = (0); i < (n); ++i) {
    if (c1 == i || c2 == i) continue;
    int r = query({i, c1, c2});
    if (c1 != r && c2 != r) {
      ans(r);
      return;
    }
  }
}
int main() {
  cout.precision(13);
  int t = 1;
  for (int _t = (0); _t < (t); ++_t) solve(_t);
  return 0;
}
