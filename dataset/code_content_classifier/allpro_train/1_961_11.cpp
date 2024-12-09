#include <bits/stdc++.h>
using namespace std;
inline void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  deque<long long> D;
  for (long long i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      D.push_back(v[i]);
    } else {
      D.push_front(v[i]);
    }
  }
  for (auto i : D) cout << i << ' ';
  cout << '\n';
}
signed main() {
  fastio();
  long long T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
