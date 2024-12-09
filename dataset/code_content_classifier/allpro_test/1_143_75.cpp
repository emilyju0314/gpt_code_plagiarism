#include <bits/stdc++.h>
using namespace std;
long long tc, n;
long long a[200001];
long long nums[200001];
int32_t main() {
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (long long i = 0; i <= n; i++) nums[i] = 0;
    priority_queue<long long> pq;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      nums[a[i]]++;
    }
    long long adds = 0;
    bool ok = 1;
    for (long long i = 0; i <= n; i++) {
      if (!ok) {
        cout << " -1";
        continue;
      }
      if (i == 0) {
        cout << nums[0];
        for (long long j = 1; j < nums[0]; j++) pq.push(0);
      } else {
        long long cnt = nums[i] + adds;
        if (nums[i - 1] == 0) {
          if (pq.empty()) {
            cnt = -1;
            ok = 0;
          } else {
            cnt += i - 1 - pq.top();
            adds += i - 1 - pq.top();
            pq.pop();
          }
        }
        for (long long j = 1; j < nums[i]; j++) pq.push(i);
        cout << " " << cnt;
      }
    }
    cout << "\n";
  }
  return 0;
}
