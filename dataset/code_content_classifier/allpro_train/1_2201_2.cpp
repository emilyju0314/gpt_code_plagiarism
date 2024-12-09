#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6 + 8;
const long long sz = 1e5 + 5;
void f_io() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
}
int32_t main() {
  f_io();
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> l(n), r(n), arr(n);
    for (long long i = 0; i < n; i++) cin >> l[i] >> r[i];
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = i + 1; j < n; j++) {
        if (l[i] < r[j] && l[j] < r[i]) {
          arr[i]++;
          arr[j]++;
          cnt++;
        }
      }
    }
    vector<long long> ans;
    for (long long i = 0; i < n; i++)
      if (arr[i] == cnt) ans.push_back(i);
    cout << ans.size() << "\n";
    for (auto k : ans) cout << k + 1 << " ";
  }
}
