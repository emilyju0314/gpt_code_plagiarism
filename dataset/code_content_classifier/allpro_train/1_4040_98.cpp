#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, nr, p, sol, x, k;
  scanf("%lld", &n);
  nr = 1;
  k = 1;
  p = 1;
  while (nr <= n) {
    if (n % nr == 0) sol = nr;
    p *= 2;
    k++;
    x = p;
    nr = 0;
    for (int i = 1; i <= k; ++i) nr += x, x *= 2;
  }
  printf("%lld", sol);
  return 0;
}
