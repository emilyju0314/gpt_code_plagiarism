#include <bits/stdc++.h>
int main(void) {
  int p, k;
  int exp;
  long long int r = 1;
  scanf(" %d %d", &p, &k);
  if (k == 0) {
    exp = p - 1;
  } else if (k == 1) {
    exp = p;
  } else {
    long long int aux = k;
    int m = 1;
    while (aux != 1) {
      aux = (aux * k) % p;
      m++;
    }
    exp = (p - 1) / m;
  }
  while (exp--) {
    r = (r * p) % (int)(1e9 + 7);
  }
  printf("%lld\n", r);
  return 0;
}
