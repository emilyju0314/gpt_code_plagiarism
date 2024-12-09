#include <bits/stdc++.h>
using namespace std;
long long int x[2000011];
long long int p[2000011];
int ind, n, range;
long double func(int i, int len) {
  long double ret = x[i];
  ret += p[i - 1] - p[i - len - 1];
  ret += p[n] - p[n - len];
  ret /= (long double)(2 * len + 1);
  return ret;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i + 1];
  }
  sort(x + 1, x + n + 1);
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] + x[i];
  int len = 0;
  long double ans = -1e18;
  for (int i = 1; i <= n; i++) {
    int lo = 0;
    int hi = min(i - 1, n - i) + 1;
    int mid;
    while (hi - lo > 1) {
      mid = (hi + lo) / 2;
      if (func(i, mid) >= func(i, mid - 1))
        lo = mid;
      else
        hi = mid;
    }
    long double cur = func(i, lo);
    cur -= x[i];
    if (cur > ans) {
      ans = cur;
      ind = i;
      range = lo;
    }
  }
  cout << 2 * range + 1 << "\n";
  for (int j = ind; j > ind - range - 1; j--) cout << x[j] << " ";
  for (int j = n; j > n - range; j--) cout << x[j] << " ";
}
