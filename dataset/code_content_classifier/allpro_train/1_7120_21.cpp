#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", (n / 2 - n / 4 + 1) % mod * ((n / 4 + 1) % mod) % mod);
  }
  return 0;
}
