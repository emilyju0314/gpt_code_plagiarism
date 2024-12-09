#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), chk;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 1LL * a[0] * a.back();
    for (int i = 2; 1LL * i * i <= ans; i++) {
      if ((ans % i) == 0) {
        chk.emplace_back(i);
        if ((ans / i) != i) chk.emplace_back(ans / i);
      }
    }
    sort(chk.begin(), chk.end());
    cout << (chk != a ? -1 : ans) << '\n';
  }
  return 0;
}
