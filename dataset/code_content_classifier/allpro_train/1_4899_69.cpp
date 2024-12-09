#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const int NINF = -1e9;
int d[maxn];
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);
    int odd, even;
    odd = even = NINF;
    for (int i = 0; i < n; i++) {
      if (d[i] % 2 == 0) {
        odd = max(odd, odd + d[i]);
        even = max({even, even + d[i], d[i]});
      } else {
        int odd2;
        odd2 = max({odd, even + d[i], d[i]});
        even = max({even, odd + d[i]});
        odd = odd2;
      }
    }
    printf("%d\n", odd);
  }
  return 0;
}
