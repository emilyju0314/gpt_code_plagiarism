#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  long long bit[40] = {0};
  for (int i = (int)0; i <= (int)n - 1; ++i) {
    cin >> a[i];
    bit[(int)(log2(a[i]))] += 1LL;
  }
  long long res = 0;
  for (int i = 0; i < 40; i++) {
    if (bit[i] > 1) {
      res += (bit[i] * (bit[i] - 1LL)) / 2LL;
    }
  }
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
