#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
const char nl = '\n';
void solve() {
  int n, mx = 0;
  cin >> n;
  long long a, b;
  for (int i = 0; i < (n); i++) {
    cin >> a >> b;
    if (mx < a + b) {
      mx = a + b;
    }
  }
  cout << mx << nl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
