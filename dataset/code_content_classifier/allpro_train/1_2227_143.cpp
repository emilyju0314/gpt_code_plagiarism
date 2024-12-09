#include <bits/stdc++.h>
using namespace std;
vector<long long> a, v;
long long maxn = 1e18;
bool check(long long x) {
  long long t = sqrt(x);
  if (t * t == x) return true;
  return false;
}
long long Dig(long long l, long long r) {
  long long l1 = 2, r1 = 1e9 + 100, l2 = -1, r2 = -1;
  while (l1 <= r1) {
    long long mid = (l1 + r1) / 2;
    if (mid * mid > r) {
      r2 = mid;
      r1 = mid - 1;
    } else
      l1 = mid + 1;
  }
  l1 = 2, r1 = 1e9 + 100;
  while (l1 <= r1) {
    long long mid = (l1 + r1) / 2;
    if (mid * mid >= l) {
      l2 = mid;
      r1 = mid - 1;
    } else
      l1 = mid + 1;
  }
  return r2 - l2;
}
int main() {
  for (int i = 2; i <= 1e6; i++) {
    long long x = i;
    for (int j = 2; j < 64; j++) {
      if (maxn / x < i) break;
      x = x * i;
      if (j != 2) a.push_back(x);
    }
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  int s = a.size();
  for (int i = 0; i < s; i++) {
    if (!check(a[i])) v.push_back(a[i]);
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    long long l, r;
    cin >> l >> r;
    long long ans = 0;
    if (l <= 1) ans++;
    ans +=
        upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
    ans += Dig(l, r);
    cout << ans << endl;
  }
  return 0;
}
