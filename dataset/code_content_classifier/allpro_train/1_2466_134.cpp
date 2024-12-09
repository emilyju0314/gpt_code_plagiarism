#include <bits/stdc++.h>
using namespace std;
struct BIT {
  int bit[1000005];
  int n;
  void add(int k, int x) {
    while (k <= n) {
      bit[k] += x;
      k += k & -k;
    }
  }
  int sum(int k) {
    int ret = 0;
    while (k > 0) {
      ret += bit[k];
      k -= k & -k;
    }
    return ret;
  }
};
BIT bit;
long long int fac[1000005];
long long int pl[1000005];
int in[1000005];
void make() {
  fac[0] = 1;
  for (int i = 1; i < 1000005; i++) {
    fac[i] = fac[i - 1] * (long long int)i;
    fac[i] %= 1000000007;
  }
}
long long int get(int x) {
  long long int ret =
      fac[x] * ((long long int)x * (long long int)(x - 1) / 2 % 1000000007) %
      1000000007;
  if (ret % 2 == 1) ret += 1000000007;
  return ret / 2;
}
int main() {
  make();
  int n;
  scanf("%d", &n);
  bit.n = n + 2;
  for (int i = 1; i <= n; i++) bit.add(i, 1);
  long long int ret = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    int sum = bit.sum(a) - 1;
    ret += get(n - i - 1) * (long long int)sum % 1000000007;
    ret += fac[n - i - 1] *
           ((long long int)sum * (long long int)(sum - 1) / 2 % 1000000007) %
           1000000007;
    ret %= 1000000007;
    bit.add(a, -1);
    in[i] = sum;
    pl[i] = fac[n - i - 1] * (long long int)sum % 1000000007;
  }
  pl[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    pl[i] += pl[i + 1];
    pl[i] %= 1000000007;
    ret += pl[i + 1] * (long long int)in[i] % 1000000007;
    ret %= 1000000007;
  }
  printf("%I64d\n", ret);
  return 0;
}
