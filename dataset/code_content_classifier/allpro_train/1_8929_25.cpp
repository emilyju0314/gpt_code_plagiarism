#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (n % 2 == 0 or n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 or n % (i + 2) == 0) return 0;
  return 1;
}
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % 1000000007;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % 1000000007;
    res %= 1000000007;
  }
  return res;
}
long long max(long long a, long long b) { return (a > b ? a : b); }
long long min(long long a, long long b) { return (a < b ? a : b); }
struct node {
  long long u, v, w, z;
  node(long long a, long long b, long long c, long long d) {
    u = a;
    v = b;
    w = c;
    z = d;
  }
};
struct compare {
  bool operator()(const node a, const node b) const {
    if (a.u == b.u) {
      if (a.v == b.v) {
        return a.w < b.w;
      }
      return a.v < b.v;
    }
    return a.u < b.u;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<node> v;
  for (long long i = 1; i <= n; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    v.push_back(node(a, b, c, i));
  }
  long long taken[n + 1];
  memset(taken, 0, sizeof(taken));
  for (long long i = 0; i < n; i++) {
    if (taken[i]) {
      continue;
    }
    long long ind = i;
    long long mx = 2e18;
    for (long long j = 0; j < n; j++) {
      if (taken[j]) {
        continue;
      }
      if (j == i) {
        continue;
      }
      long long dist =
          abs(v[i].u - v[j].u) + abs(v[i].v - v[j].v) + abs(v[i].w - v[j].w);
      if (dist < mx) {
        mx = dist;
        ind = j;
      }
    }
    taken[i] = 1;
    taken[ind] = 1;
    cout << i + 1 << " " << ind + 1 << "\n";
  }
}
