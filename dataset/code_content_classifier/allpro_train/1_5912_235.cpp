#include <bits/stdc++.h>
using namespace std;
bool ok(int m, int n, int k) {
  int lines = 0;
  while (m) {
    lines += m;
    if (lines >= n) return true;
    m /= k;
  }
  return false;
}
int main() {
  int n, k, mid, l = 1, r = 1e9;
  scanf("%i %i", &n, &k);
  while (l < r) {
    mid = l + (r - l) / 2;
    if (!ok(mid, n, k))
      l = mid + 1;
    else
      r = mid;
  }
  printf("%i", l);
  return 0;
}
