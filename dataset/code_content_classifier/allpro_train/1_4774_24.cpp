#include <bits/stdc++.h>
using namespace std;
void solve(long long testcase) {
  long long n, curr, k;
  cin >> n >> curr >> k;
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long i = 1;
  while (i < n) {
    long long diff = abs(a[i] - a[i + 1]);
    if (diff <= k) {
      if (a[i] >= a[i + 1])
        curr += a[i] - max(0LL, a[i + 1] - k);
      else
        curr += min(a[i], k - diff);
    } else {
      if (a[i] >= a[i + 1]) {
        curr += a[i] - max(0LL, a[i + 1] - k);
      } else {
        if ((diff - k) > curr) {
          cout << "NO\n";
          return;
        } else {
          curr -= (diff - k);
        }
      }
    }
    i++;
  }
  cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
}
