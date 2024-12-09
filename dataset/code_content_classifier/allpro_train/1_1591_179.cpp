#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 10;
const long long BINF = 1e18 + 10;
long long get(long long l, long long r) {
  if (l > r) {
    swap(l, r);
  }
  return r * (r + 1) / 2 - l * (l - 1) / 2;
}
long long solve(long long a, long long b, long long lim) {
  long long res = 0;
  if (a > lim) {
    if (b >= lim) {
      res += lim * (a - b + 1);
    } else {
      res += get(b, lim) + lim * (a - lim);
    }
  } else {
    res += get(a, b);
  }
  return res;
}
void source() {
  long long n, x, y, need;
  cin >> n >> x >> y >> need;
  if (need <= 1) {
    cout << 0;
    exit(0);
  }
  long long l = 0, r = 2 * n + 10;
  long long mx_up = n - y + 1, mx_down = y;
  while (r - l > 1) {
    long long mid = (l + r) / 2, sum = 0;
    long long left = max(x - mid, 1ll), right = min(x + mid, n);
    long long a = mid + 1, vl = a - (x - left), vr = a - (right - x);
    sum = solve(a, vl, mx_up) + solve(a, vr, mx_up) - min(mx_up, a);
    sum += solve(a, vl, mx_down) + solve(a, vr, mx_down) - min(mx_down, a);
    sum -= right - left + 1;
    if (sum >= need) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}
