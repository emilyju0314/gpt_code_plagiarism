#include <bits/stdc++.h>
using namespace std;
int n;
long long p;
long long k;
map<long long, long long> d;
long long kq;
int main() {
  scanf("%d%lld%lld", &n, &p, &k);
  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%lld", &x);
    x = ((x * x % p * x % p * x % p - (x * k % p)) + p) % p;
    kq += d[x];
    d[x]++;
  }
  cout << kq;
  return 0;
}
