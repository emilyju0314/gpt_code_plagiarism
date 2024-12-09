#include <bits/stdc++.h>
using namespace std;
const int nm = 200002;
int n;
long long a[nm], s, d;
long long find(int i) {
  int l = 1, r = a[i], mid, kq = a[i] + 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (d - mid < n - 1)
      r = mid - 1;
    else if (d - mid > s - a[i])
      l = mid + 1;
    else {
      kq = mid;
      r = mid - 1;
    }
  }
  return kq;
}
long long find2(int i) {
  int l = 1, r = a[i], mid, kq = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (d - mid < n - 1)
      r = mid - 1;
    else if (d - mid > s - a[i])
      l = mid + 1;
    else {
      kq = mid;
      l = mid + 1;
    }
  }
  return kq;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  for (int i = 1; i <= n; ++i) {
    long long l = find(i);
    long long r = find2(i);
    if (l <= r)
      cout << a[i] - (r - l + 1) << " ";
    else
      cout << a[i] << " ";
  }
}
