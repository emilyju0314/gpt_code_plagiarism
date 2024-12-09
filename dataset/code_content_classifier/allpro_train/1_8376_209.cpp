#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n), oa(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    oa[i] = arr[i];
  }
  vector<vector<long long> > q(n);
  for (long long i = 0; i < k; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    q[a].push_back(arr[b]);
    q[b].push_back(arr[a]);
  }
  sort(arr.begin(), arr.end());
  for (long long i = 0; i < n; i++) {
    vector<long long>::iterator low;
    low = lower_bound(arr.begin(), arr.end(), oa[i]);
    long long scnt = (low - arr.begin());
    sort(q[i].begin(), q[i].end());
    auto it = lower_bound(q[i].begin(), q[i].end(), oa[i]);
    long long qscnt = (it - q[i].begin());
    cout << scnt - qscnt << " ";
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
}
