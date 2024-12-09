#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long N = 1e6 + 10;
const long long inf = (long long)1e12 + 10ll;
const long long mod = 1e9 + 7;
const long long eps = 1e-9;
const char spc = 29;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
using namespace std;
long long n, first;
long long a[N];
long long pref[N];
long long prefdays[N];
long long calc(long long first) { return first * (first + 1ll) / 2ll; }
long long binsearch(long long strt, long long first) {
  long long l = 0;
  long long r = n;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (prefdays[strt + mid] - prefdays[strt] > first)
      r = mid;
    else
      l = mid + 1;
  }
  if (prefdays[strt + l] - prefdays[strt] > first) --l;
  return l;
}
long long f(long long mn, long long day) {
  long long first = ::first;
  long long res = calc(a[mn]) - calc(day - 1);
  first -= a[mn] - day + 1;
  if (!first) return res;
  ++mn;
  long long cnt = binsearch(mn, first);
  res += (pref[mn + cnt] - pref[mn]);
  first -= (prefdays[mn + cnt] - prefdays[mn]);
  res += calc(first);
  return res;
}
long long ternsearch(long long mn) {
  long long l = max(a[mn] - first + 1, 1ll);
  long long r = a[mn];
  while (l + 2 < r) {
    long long m1 = l + (r - l) / 3;
    long long m2 = r - (r - l) / 3;
    if (f(mn, m1) < f(mn, m2))
      l = m1;
    else
      r = m2;
  }
  long long res = 0;
  for (long long i = l; i <= r; ++i) res = max(res, f(mn, i));
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> first;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = n; i < n * 2; ++i) a[i] = a[i - n];
  n *= 2;
  long long ans = 0;
  for (long long i = 0; i < n; ++i) pref[i + 1] = pref[i] + calc(a[i]);
  for (long long i = 0; i < n; ++i) prefdays[i + 1] = prefdays[i] + a[i];
  for (long long i = 0; i < n / 2; ++i) ans = max(ans, ternsearch(i));
  cout << ans << endl;
}
