#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt1 = 0, cnt0 = 0;
  long long ans1 = 0, ans2 = 0;
  scanf("%d", &n);
  int a[n], l_1[n], r_0[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      ++cnt1;
    } else
      l_1[i] = cnt1;
  }
  for (int i = n - 1; i > -1; --i) {
    if (a[i] == 0) {
      ++cnt0;
    } else
      r_0[i] = cnt0;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      ans1 += r_0[i];
    }
  }
  for (int i = n - 1; i > -1; --i) {
    if (a[i] == 0) {
      ans2 += l_1[i];
    }
  }
  printf("%lld", min(ans1, ans2));
  return 0;
}
