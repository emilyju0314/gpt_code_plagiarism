#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> v1[100005 + 1];
long long fact[100005];
long long inverse[100005];
int mark[100005];
long long powmod(long long a) {
  long long b = 1000000007LL - 2;
  long long c = 1000000007LL;
  long long ret = 1LL;
  while (b) {
    if (b & 1) ret = (ret * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return (ret) % c;
}
long long mInverse(long long a) {
  if (a == 0LL) return 1LL;
  return powmod(a);
}
void precompute() {
  fact[0] = 1;
  inverse[0] = 1;
  for (int i = 1; i <= 100000; ++i) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= 1000000007LL;
    inverse[i] = mInverse(fact[i]);
  }
}
void sieve() {
  int i, j;
  memset(mark, 0, sizeof(mark));
  for (i = 2; i <= 100005; i += 2) {
    v1[i].push_back(2);
    mark[i] = 1;
  }
  for (i = 3; i <= 100005; i += 3)
    if (mark[i] == 0) v1[i].push_back(3);
  for (i = 5; i * i <= 100005; i += 2) {
    if (mark[i] == 0) {
      mark[i] = 1;
      v1[i].push_back(i);
      for (j = i; j * i <= 100005; j += 2) {
        if (mark[i * j] == 0) {
          mark[i * j] == 1;
          v1[i * j].push_back(i);
        }
      }
    }
  }
  for (i = sqrt(100005); i <= 100005; ++i)
    if (mark[i] == 0) v1[i].push_back(i);
}
long long nck(int n, int k) {
  if (k > n)
    return 0;
  else if (k == 0 || k == n)
    return 1;
  long long res = fact[n];
  res = res * inverse[k];
  res %= 1000000007LL;
  res = res * inverse[n - k];
  res %= 1000000007LL;
  return res;
}
int main() {
  precompute();
  sieve();
  int q, n, k, i, j;
  scanf("%d", &q);
  while (q--) {
    v.clear();
    scanf("%d", &n);
    scanf("%d", &k);
    long long ans = nck(n - 1, k - 1);
    int div = n;
    int prev = -1;
    while (div > 1) {
      if (v1[div][0] != prev) v.push_back(v1[div][0]);
      prev = v1[div][0];
      div /= v1[div][0];
    }
    for (i = 1; i < (1 << v.size()); ++i) {
      int setbit = __builtin_popcount(i);
      int val = 1;
      for (j = 0; j < v.size(); ++j) {
        if (i & (1 << j)) val = val * v[j];
      }
      if (setbit & 1)
        ans -= nck(n / val - 1, k - 1);
      else
        ans += nck(n / val - 1, k - 1);
      ans = (ans % 1000000007LL + 2 * 1000000007LL) % 1000000007LL;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
