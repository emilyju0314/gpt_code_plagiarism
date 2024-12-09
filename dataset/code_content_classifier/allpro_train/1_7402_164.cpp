#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100002];
int b[100002], n, mn = INT_MAX, mx = INT_MIN, s = 0, cnt = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) b[i] = a[i].second;
  for (int i = 0; i < n; i++) {
    mn = min(mn, b[i]);
    mx = max(mx, b[i]);
    if (mn == s && mx == i) {
      cnt++;
      s = i + 1;
      mn = INT_MAX;
      mx = INT_MIN;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
