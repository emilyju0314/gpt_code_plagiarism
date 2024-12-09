#include <bits/stdc++.h>
using namespace std;
long f[200001];
long find(long p) {
  if (f[p] != p) f[p] = find(f[p]);
  return f[p];
}
void merge(long a, long b) {
  long fa = find(a), fb = find(b);
  if (fa > fb)
    f[fb] = fa;
  else
    f[fa] = fb;
}
int main() {
  long n, m;
  scanf("%ld%ld", &n, &m);
  for (long i = 0; i <= n; ++i) f[i] = i;
  for (long i = 0, x, y; i < m; ++i) {
    scanf("%ld%ld", &x, &y);
    merge(x - 1, y - 1);
  }
  long ans = 0;
  for (long i = 0, p = find(0); i < n; ++i) {
    if (find(i) != p) {
      merge(i, p);
      p = find(i);
      ++ans;
    }
    if (i == p && i < n - 1) p = find(i + 1);
  }
  printf("%ld", ans);
  return 0;
}
