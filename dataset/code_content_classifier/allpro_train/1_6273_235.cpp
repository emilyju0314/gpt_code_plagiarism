#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = (int)1e6 + 7, mod = 1000000007, M = 2e9;
int w, h, n, t, a, b, fh[N], fw[N];
set<int> H, W, dh, dw;
set<int>::iterator it;
char c;
int main() {
  H.insert(0);
  W.insert(0);
  scanf("%d%d%d", &w, &h, &n);
  H.insert(h);
  W.insert(w);
  dh.insert(h);
  dw.insert(w);
  fh[h]++;
  fw[w]++;
  while (n--) {
    scanf(" %c%d", &c, &t);
    if (c == 'H') {
      it = H.upper_bound(t);
      b = *it;
      it--;
      a = *it;
      H.insert(t);
      fh[b - a]--;
      fh[t - a]++;
      fh[b - t]++;
      if (!fh[b - a]) dh.erase(b - a);
      dh.insert(t - a);
      dh.insert(b - t);
    } else {
      it = W.upper_bound(t);
      b = *it;
      it--;
      a = *it;
      W.insert(t);
      fw[b - a]--;
      fw[t - a]++;
      fw[b - t]++;
      if (!fw[b - a]) dw.erase(b - a);
      dw.insert(t - a);
      dw.insert(b - t);
    }
    long long x = *dh.rbegin(), y = *dw.rbegin();
    printf("%I64d\n", x * y);
  }
  return 0;
}
