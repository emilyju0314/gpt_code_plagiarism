#include <bits/stdc++.h>
using namespace std;
using lld = long long int;
using llu = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
mt19937 rnd;
int nextint(int s, int t) { return (int)(rnd() % (t - s + 1)) + s; }
int n, m, p;
int a[1000009];
int b[1000009];
int main() {
  int t = 1, tv = 0;
  int i, j, k, l;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      b[i] = -1;
    }
    bool cycle = false;
    int res = 0;
    for (i = 0; i < n && !cycle; i++) {
      if (a[i] == 0) {
        if (b[i] == -1) {
          b[i] = 0;
          j = i;
          while (1) {
            int pj = j;
            j = (j - m + n) % n;
            if (a[j] == 0) break;
            if (b[j] == -1) {
              b[j] = b[pj] + 1;
              res = max(res, b[j]);
            } else {
              cycle = true;
              break;
            }
          }
        }
      }
    }
    if (!cycle) {
      for (i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == -1) {
          cycle = true;
          break;
        }
      }
    }
    if (cycle) {
      printf("-1\n");
    } else {
      printf("%d\n", res);
    }
  }
}
