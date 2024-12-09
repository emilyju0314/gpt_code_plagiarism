#include <bits/stdc++.h>
long long int c1, c2, n;
long long int group(long long int x) { return c1 + c2 * (x - 1) * (x - 1); }
long long int part(long long int m) {
  int a = (n / m), b = (n % m);
  return b * group(a + 1) + (m - b) * group(a);
}
char str[200005];
void solve() {
  scanf("%lld", &n);
  scanf("%lld", &c1);
  scanf("%lld", &c2);
  long long int i, l, h, m;
  int a;
  h = 0;
  scanf("%s", str);
  for (i = 0; i < n; ++i) h += (str[i] - '0');
  l = 1;
  while (l < h) {
    m = ((l + h) / 2);
    if (part(m) < part(m + 1))
      h = m;
    else
      l = m + 1;
  }
  printf("%lld\n", part(l));
}
void starting() {}
int main() {
  int t = 1;
  starting();
  while (t--) solve();
}
