#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int a[N], c[N], p[N], n, k;
bool h[N];
struct Bt {
  int c[N];
  int lowbit(int x) { return x & -x; }
  void modify(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) c[i] += v;
  }
  int query(int x) {
    int s = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) s += c[i];
    return s;
  }
} b1, b2;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), p[a[i]] = i;
  for (int i = 1; i <= k; ++i) {
    int x;
    scanf("%d", &x);
    h[x] = 1;
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (h[i] == 0) {
      int l = p[i], r = n;
      int R = p[i], L = p[i];
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (b1.query(mid) - b1.query(p[i] - 1) == 0)
          l = mid + 1, R = mid;
        else
          r = mid - 1;
      }
      l = 1, r = p[i];
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (b1.query(p[i]) - b1.query(mid - 1) == 0)
          r = mid - 1, L = mid;
        else
          l = mid + 1;
      }
      ans += (R - L + 1) - (b2.query(R) - b2.query(L - 1));
      b2.modify(p[i], 1);
    } else
      b1.modify(p[i], 1);
  }
  cout << ans << endl;
  return 0;
}
