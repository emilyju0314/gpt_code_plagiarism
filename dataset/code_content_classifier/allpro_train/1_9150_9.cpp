#include <bits/stdc++.h>
using namespace std;
int a[100005], t[100005], ti[100005];
long long pre[100005], ex[100005];
int main() {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    pre[i] = pre[i - 1] + t[i];
  }
  for (i = 1; i <= n; i++) {
    if (a[i] <= t[i])
      ex[i] += a[i];
    else if (a[i] >= pre[n] - pre[i - 1]) {
      ti[i]++;
      ti[n + 1]--;
    } else {
      int lo = i;
      int hi = n;
      int mid;
      while (hi > lo + 1) {
        mid = (lo + hi) / 2;
        if (pre[mid] - pre[i - 1] >= a[i])
          hi = mid;
        else
          lo = mid;
      }
      for (mid = hi; mid >= lo; mid--)
        if (pre[mid] - pre[i - 1] < a[i]) break;
      ti[i]++;
      ti[mid + 1]--;
      ex[mid + 1] += a[i] - (pre[mid] - pre[i - 1]);
    }
  }
  long long ofs = 0;
  for (i = 1; i <= n; i++) {
    ofs += ti[i];
    printf("%lld ", ex[i] + ofs * t[i]);
  }
  return 0;
}
