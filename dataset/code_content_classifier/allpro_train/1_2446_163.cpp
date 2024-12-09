#include <bits/stdc++.h>
const int maxn = 1 << 21;
int h, g, a[maxn], b[maxn];
bool r[maxn];
int gm(int k, int l) {
  int ans = r[k] || a[k] <= l ? 0 : k;
  if (k * 2 >= (1 << h)) return ans;
  int j = gm(k * 2, l);
  if (a[j] < a[ans]) ans = j;
  j = gm(k * 2 + 1, l);
  if (a[j] < a[ans]) ans = j;
  return ans;
}
void solve() {
  scanf("%d%d", &h, &g);
  a[0] = 0x7fffffff;
  for (int i = 1; i < (1 << h); ++i) {
    scanf("%d", a + i);
    b[i] = 0;
    r[i] = false;
  }
  for (int i = (1 << g) - 1; i > 0; --i) {
    int l = std::max(b[i * 2], b[i * 2 + 1]);
    int j = gm(i, l);
    r[j] = true;
    b[i] = a[j];
  }
  long long ans = 0;
  for (int i = 1; i < (1 << h); ++i) {
    if (r[i]) ans += a[i];
  }
  printf("%lld\n", ans);
  for (int i = (1 << h) - 1; i > 0; --i) {
    if (!r[i]) printf("%d ", i);
  }
  putchar('\n');
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
