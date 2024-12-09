#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 1e5 + 100;
long long int a[N], sum[N];
int n, k;
int lbs(long long int val) {
  int lo = 1, hi = n;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] > val)
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  return lo;
}
int hbs(long long int val) {
  int lo = 1, hi = n;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= val)
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  return hi;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  int g = 1, mx = 1;
  int lst = a[n];
  for (int i = 2; i <= a[1]; i++) {
    int p = 0;
    bool ck = 0;
    long long int ans = 0;
    for (int j = i; j <= lst + i; j += i) {
      int x2 = hbs(j);
      if (a[x2] - p > k) {
        ck = 1;
        break;
      }
      p = j;
    }
    if (!ck) {
      mx = i;
    }
  }
  cout << mx << endl;
}
