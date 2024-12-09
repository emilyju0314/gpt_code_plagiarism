#include <bits/stdc++.h>
using namespace std;
long n, q, c1, c2, a, b, out[1000001], p;
bool g;
int main() {
  scanf("%d%d", &n, &q);
  for (long i = 0; i < q; i++) {
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d", &b);
      c1 += b;
      c2 += b;
      if (b % 2) g = !g;
    } else {
      if (!g) {
        c1++;
        c2--;
      } else {
        c1--;
        c2++;
      }
      g = !g;
    }
    if (c1 < 0) c1 += n;
    if (c1 >= n) c1 -= n;
    if (c2 < 0) c2 += n;
    if (c2 >= n) c2 -= n;
  }
  for (long i = 0; i < n; i++) {
    if (i % 2 == 0)
      p = i + c1;
    else
      p = i + c2;
    if (p >= n) p -= n;
    out[p] = i + 1;
  }
  for (long i = 0; i < n; i++) printf("%d ", out[i]);
  return 0;
}
