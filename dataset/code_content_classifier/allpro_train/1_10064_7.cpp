#include <bits/stdc++.h>
using namespace std;
long long n, k, t;
long long bs_ch(long long mid, long long x) {
  if (mid * mid + mid <= 2 * x) return 1;
  return 0;
}
long long bs(long long l, long long r, long long x) {
  long long mid = (l + r) / 2;
  while (r - l > 1) {
    bs_ch(mid, x) ? l = mid : r = mid;
    mid = (l + r) / 2;
  }
  return r;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    k--;
    long long x = bs(0, n - 1, k);
    k -= x * (x + 1) / 2;
    if (k)
      for (int i = n - 1; i >= 0; i--)
        (i == x || i == k + x) ? cout << 'b' : cout << 'a';
    else {
      for (int i = n - 1; i > 0; i--)
        (i == x || i == k + x) ? cout << 'b' : cout << 'a';
      cout << "b";
    }
    cout << endl;
  }
  return 0;
}
