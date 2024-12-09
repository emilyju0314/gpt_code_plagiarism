#include <bits/stdc++.h>
using namespace std;
int a[101], n, res;
bool can(int x) {
  vector<int> b(a, a + x);
  int k = 0;
  for (int j = x; j < n; ++j) {
    bool f = 0;
    int c = 0;
    while (c != x) {
      if (k == x) k = 0;
      if (b[k] > 0) {
        b[k] = min(a[j], b[k] - 1);
        k++;
        f = 1;
        break;
      } else {
        k++, c++;
      }
    }
    if (!f) return false;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a + n);
  reverse(a, a + n);
  int l = 1, r = n, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (can(mid)) {
      res = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", res);
  return 0;
}
