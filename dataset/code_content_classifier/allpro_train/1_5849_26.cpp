#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[100009];
int a[100009];
int b[100009];
bool pres[100005];
bool check(int mid) {
  memset(pres, 0, sizeof pres);
  for (int i = mid - 1; i >= 0; --i) {
    if (pres[d[i]])
      b[i] = 0;
    else
      b[i] = d[i], pres[d[i]] = 1;
  }
  int c = 0, ret = 0;
  for (int i = 0; i < mid; ++i) {
    if (b[i] == 0)
      c++;
    else {
      if (c >= a[b[i]])
        ret++, c -= a[b[i]];
      else
        return 0;
    }
  }
  return ret == m;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", d + i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", a + i + 1);
  }
  int ans = -1, low = 1, high = n;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (check(mid))
      ans = mid, high = mid - 1;
    else
      low = mid + 1;
  }
  printf("%d", ans);
  return 0;
}
