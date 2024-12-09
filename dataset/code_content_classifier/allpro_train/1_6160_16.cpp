#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> arr[200100];
vector<long long> vec;
long long M = 998244353;
int main() {
  long long t, n, i, j, k, l, m;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  t = 1;
  while (t--) {
    cin >> n >> k;
    for (i = 1; i <= n; i++) cin >> arr[i].first, arr[i].second = i;
    if (k == 1 || k == n) {
      long long sum = 0, maxi = 0;
      for (i = 1; i <= n; i++) {
        sum += arr[i].first;
        maxi = max(maxi, arr[i].first);
      }
      if (k == 1)
        cout << maxi << ' ' << 1 << '\n';
      else
        cout << sum << ' ' << 1 << '\n';
      return 0;
    }
    sort(arr + 1, arr + n + 1);
    long long sum = 0;
    for (i = n; i > n - k; i--) {
      sum += arr[i].first;
      vec.push_back(arr[i].second);
    }
    sort(vec.begin(), vec.end());
    long long ans = 1;
    for (i = 1; i < vec.size(); i++) {
      ans = ans * (vec[i] - vec[i - 1]);
      ans %= M;
    }
    cout << sum << ' ' << ans << '\n';
  }
  return 0;
}
