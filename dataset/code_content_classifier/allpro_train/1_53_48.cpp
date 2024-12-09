#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  long long i, a[n];
  for (i = 0; i < n; i++) scanf("%lld", &a[i]);
  sort(a, a + n);
  for (i = n - 1; i >= 0; i--) {
    if (k % a[i] == 0) break;
  }
  printf("%lld\n", k / a[i]);
}
