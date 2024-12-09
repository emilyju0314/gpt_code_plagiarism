#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p;
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= 10000000; ++i) {
    long long m = n - 1ll * i * p, tmp = m;
    if (m < 0 && p > 0) break;
    int x = 0;
    while (m) x += (m & 1), m >>= 1;
    if (i >= x && i <= tmp) {
      printf("%d", i);
      return 0;
    }
  }
  puts("-1");
}
