#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int N = 1e5 + 7;
long long arr[N];
int getl(int l, int r, long long key) {
  int ans = -1;
  while (l <= r) {
    int mid = ((l + r) >> 1);
    if (arr[mid] >= key) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  return ans;
}
int getr(int l, int r, long long key) {
  int ans = -1;
  while (l <= r) {
    int mid = ((l + r) >> 1);
    if (arr[mid] <= key) {
      l = mid + 1;
      ans = mid;
    } else
      r = mid - 1;
  }
  return ans;
}
int main(void) {
  int n, i;
  long long x, k;
  while (cin >> n >> x >> k) {
    for (i = 1; i <= n; ++i) cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    long long ans = 0;
    for (i = 1; i <= n; ++i) {
      if (k == 0) {
        if (arr[i] % x) {
          long long l_lim = arr[i], r_lim = arr[i] / x * x + x - 1LL;
          int l = getl(1, n, l_lim), r = getr(1, n, r_lim);
          if (l > r || l == -1 || r == -1) continue;
          ans += (long long)(r - l + 1);
        }
        continue;
      }
      if (arr[i] % x) {
        long long l_lim = arr[i] / x * x + k * x,
                  r_lim = arr[i] / x * x + (k + 1) * x - 1LL;
        int l = getl(1, n, l_lim), r = getr(1, n, r_lim);
        if (l > r || l == -1 || r == -1) continue;
        ans += (long long)(r - l + 1);
      } else {
        long long l_lim = arr[i] + (k - 1) * x, r_lim = arr[i] + k * x - 1LL;
        int l = getl(1, n, l_lim), r = getr(1, n, r_lim);
        if (l > r || l == -1 || r == -1) continue;
        ans += (long long)(r - l + 1);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
