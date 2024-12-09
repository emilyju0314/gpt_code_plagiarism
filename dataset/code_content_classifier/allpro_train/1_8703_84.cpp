#include <bits/stdc++.h>
using namespace std;
int h, w, n, k, a[3030], b[3030], prv[3030], nxt[3030];
vector<int> v[3030];
int main() {
  scanf("%d %d %d %d", &h, &w, &n, &k);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
  }
  long long ans = 0;
  for (int i1 = h; i1 >= 1; i1--) {
    for (auto j : v[i1]) a[j]++;
    int cur = 0, s = 0, j2 = 0;
    for (int j1 = 1; j1 <= w; j1++) {
      while (j2 < w && s < k) s += a[++j2];
      if (s >= k) cur += w - j2 + 1;
      s -= a[j1];
    }
    for (int i = 0; i <= w + 1; i++) {
      prv[i] = i - 1, nxt[i] = i + 1;
    }
    for (int i = 1; i <= w; i++)
      if (!a[i]) {
        prv[nxt[i]] = prv[i], nxt[prv[i]] = nxt[i];
      }
    for (int i = 1; i <= w; i++) b[i] = a[i];
    for (int i2 = h; i2 >= i1; i2--) {
      ans += cur;
      for (auto j : v[i2]) {
        int l = j, r = j, sl = b[j], sr = 0;
        while (nxt[r] <= w && sl + sr + b[nxt[r]] <= k) r = nxt[r], sr += b[r];
        while (1) {
          if (sl + sr == k) {
            cur -= (l - prv[l]) * (nxt[r] - r);
          }
          l = prv[l];
          if (!l) break;
          sl += b[l];
          if (sl > k) break;
          while (sl + sr > k) sr -= b[r], r = prv[r];
        }
        b[j]--;
        if (!b[j]) prv[nxt[j]] = prv[j], nxt[prv[j]] = nxt[j];
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
