#include <bits/stdc++.h>
int main() {
  long long int n, lcm;
  scanf("%lld", &n);
  if (n == 2)
    lcm = 2;
  else if (n == 1)
    lcm = 1;
  else if (n % 2 == 1)
    lcm = (n - 2) * (n - 1) * n;
  else if (n % 3 == 0)
    lcm = (n - 1) * (n - 2) * (n - 3);
  else
    lcm = n * (n - 1) * (n - 3);
  printf("%lli", lcm);
  return 0;
}
