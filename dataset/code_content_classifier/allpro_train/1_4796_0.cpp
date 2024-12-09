#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, k, l, r, sa, sk;
  cin >> n >> k >> l >> r >> sa >> sk;
  int a, aa, b, bb, ans[n];
  a = sk / k, aa = sk % k;
  if (k == n) {
    b = 0;
    bb = 0;
  } else {
    b = (sa - sk) / (n - k);
    bb = (sa - sk) % (n - k);
  }
  for (int i = 0; i < k; ++i) {
    ans[i] = a;
  }
  for (int i = 0; i < aa; ++i) {
    ans[i]++;
  }
  for (int i = k; i < n; ++i) {
    ans[i] = b;
  }
  for (int i = 0; i < bb; ++i) {
    ans[k + i]++;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}
