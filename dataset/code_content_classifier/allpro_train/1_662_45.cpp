#include <bits/stdc++.h>
using namespace std;
long long int po[500005], pp[500005], arr[500005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k, d, i, idx, t;
  cin >> n >> k >> d;
  arr[0] = 0;
  for (i = 1; i <= n; i++) cin >> arr[i];
  sort(arr + 1, arr + n + 1);
  po[0] = 1;
  pp[0] = 1;
  for (i = 1; i <= k - 1; i++) {
    po[i] = 0;
    pp[i] = pp[i - 1] + po[i];
  }
  for (i = k; i <= n; i++) {
    idx = lower_bound(arr + 1, arr + i, arr[i] - d) - arr;
    if (i - idx + 1 >= k) {
      if (idx == 1)
        t = pp[i - k];
      else
        t = pp[i - k] - pp[idx - 2];
      if (t > 0)
        po[i] = 1;
      else
        po[i] = 0;
    } else
      po[i] = 0;
    pp[i] = pp[i - 1] + po[i];
  }
  if (po[n])
    cout << "YES\n";
  else
    cout << "NO\n";
}
