#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int s[maxn];
int bit[2][maxn];
int low(int p) { return p & (-p); }
void merg(int u, int p, int n, int k) {
  while (p <= n) {
    bit[u][p] += k;
    p = p + low(p);
  }
}
int sum(int u, int p) {
  int s = 0;
  while (p) {
    s += bit[u][p];
    p = p - low(p);
  }
  return s;
}
int main() {
  int i, n, a, b, k, q;
  cin >> n >> k >> a >> b >> q;
  for (i = 0; i < q; i++) {
    int p;
    scanf("%d", &p);
    if (p == 1) {
      int w1;
      scanf("%d", &w1);
      int w;
      scanf("%d", &w);
      if (s[w1] < a && s[w1] >= b) {
        if (s[w1] + w >= a) {
          merg(1, w1, n, a - s[w1]);
        } else {
          merg(1, w1, n, w);
        }
        s[w1] += w;
      } else if (s[w1] < b) {
        if ((s[w1] + w) >= b)
          merg(0, w1, n, b - s[w1]);
        else
          merg(0, w1, n, w);
        if (s[w1] + w >= a) {
          merg(1, w1, n, a - s[w1]);
        } else {
          merg(1, w1, n, w);
        }
        s[w1] += w;
      }
    } else {
      scanf("%d", &p);
      int s = sum(0, p - 1);
      if (p + k <= n) {
        s += sum(1, n) - sum(1, p + k - 1);
      }
      printf("%d\n", s);
    }
  }
}
