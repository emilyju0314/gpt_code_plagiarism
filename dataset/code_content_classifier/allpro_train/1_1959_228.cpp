#include <bits/stdc++.h>
using namespace std;
struct State {
  int nL = 0, nR = 0;
  int len;
};
void solve() {
  const int N = 200001;
  int n, k, q, l, r;
  cin >> n >> k >> q;
  map<int, State> u;
  u[1];
  u[N];
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    ++r;
    ++u[l].nL;
    ++u[r].nR;
  }
  int xPrev = 1, lenPrev = 0;
  int count = 0;
  for (auto& pa : u) {
    int x = pa.first;
    State& state = pa.second;
    state.len = lenPrev + (count >= k ? x - xPrev : 0);
    count += state.nL - state.nR;
    xPrev = x;
    lenPrev = state.len;
  }
  for (int i = 0; i < q; ++i) {
    cin >> l >> r;
    ++r;
    auto jFrom = u.lower_bound(l);
    auto jTill = u.lower_bound(r);
    int sum = jTill->second.len - jFrom->second.len;
    if (l < jFrom->first) {
      auto jPrev = jFrom;
      --jPrev;
      if (jPrev->second.len != jFrom->second.len) {
        sum += jFrom->first - l;
      }
    }
    if (r < jTill->first) {
      auto jPrev = jTill;
      --jPrev;
      if (jPrev->second.len != jTill->second.len) {
        sum -= jTill->first - r;
      }
    }
    cout << sum << endl;
  }
}
int main(int argc, char**) {
  if (argc > 1) {
    freopen("debug/in.txt", "r", stdin);
    freopen("debug/out.txt", "w", stdout);
  }
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
