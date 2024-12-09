#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 3 * 100005;
const long long MAX = 5000;
const long long N1 = 1005;
long long n, k;
long long pref[N], arr[N], suff[N];
bool ok(long long s, long long mid, long long el, long long k) {
  long long temp = 0;
  long long sum2 = pref[mid];
  if (s != 0) {
    sum2 = pref[mid] - pref[s - 1];
  }
  return ((mid - s + 1) * el - sum2) <= k;
}
long long f(long long idx) {
  long long el = arr[idx];
  long long s = 0;
  long long e = idx;
  long long ans = 0;
  long long temp_k = k;
  while (s <= e) {
    long long mid = (s + e) / 2;
    if (ok(mid, e, el, temp_k)) {
      ans += e - mid + 1;
      long long sum2 = pref[e];
      if (mid != 0) {
        sum2 = pref[e] - pref[mid - 1];
      }
      temp_k = temp_k - ((e - mid + 1) * el - (sum2));
      e = mid - 1;
      if (temp_k < 0) break;
    } else {
      s = mid + 1;
    }
  }
  return ans;
}
int32_t main() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  for (long long i = 0; i < n; i++) {
    if (i == 0) {
      pref[i] = arr[i];
    } else {
      pref[i] += pref[i - 1] + arr[i];
    }
  }
  cerr << '\n';
  long long ans = 1;
  long long ret = arr[0];
  for (long long i = 1; i < n; i++) {
    long long temp = f(i);
    if (ans < temp) {
      ans = temp;
      ret = arr[i];
    }
  }
  cout << ans << " " << ret;
}
