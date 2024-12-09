#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long bit[1000002], arr[1000002];
void convert(long long n) {
  long long temp[n];
  for (long long i = 0; i < n; i++) {
    temp[i] = arr[i];
  }
  sort(temp, temp + n);
  for (long long i = 0; i < n; i++) {
    arr[i] = lower_bound(temp, temp + n, arr[i]) - temp + 1;
  }
}
long long getSum(long long pos, long long n) {
  long long res = 0;
  while (pos > 0) {
    res += bit[pos];
    pos -= pos & (-pos);
  }
  return res;
}
void update(long long n, long long pos, long long new_val) {
  while (pos <= n) {
    bit[pos] += new_val;
    pos += pos & (-pos);
  }
}
long long findkth(long long k, long long n) {
  long long s = 1, e = n;
  while (s < e) {
    long long mid = s + (e - s) / 2;
    long long temp = getSum(mid, n);
    if (temp >= k) {
      e = mid;
    } else {
      s = mid + 1;
    }
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k, q, i, j, x, y, l, r, maxm = -1e18, minm = 1e18;
  string str;
  cin >> n >> q;
  long long cnt = n;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (i = 1; i <= n; i++) {
    bit[i] = 0;
  }
  long long ans = 0;
  for (i = 0; i < n; i++) {
    update(n, arr[i], 1);
  }
  while (q--) {
    long long x;
    cin >> x;
    if (x > 0) {
      update(n, x, 1);
      cnt++;
    } else {
      x = -x;
      cnt--;
      long long ind = findkth(x, n);
      update(n, ind, -1);
    }
  }
  if (cnt != 0) {
    ans = findkth(1, n);
  }
  cout << ans;
  cout << "\n";
  return 0;
}
