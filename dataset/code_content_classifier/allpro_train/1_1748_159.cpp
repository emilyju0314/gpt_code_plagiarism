#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long bigmod(long long base, long long power, long long mod) {
  if (power == 0)
    return 1;
  else if (power % 2 == 1) {
    long long p1 = base % mod;
    long long p2 = (bigmod(base, power - 1, mod)) % mod;
    return (p1 * p2) % mod;
  } else if (power % 2 == 0) {
    long long p1 = (bigmod(base, power / 2, mod)) % mod;
    return (p1 * p1) % mod;
  }
}
long long ncr(long long n, long long k) {
  long long C[n + 1][k + 1];
  long long i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  return C[n][k];
}
long long prime[500008];
long long sp[500008];
void seive() {
  for (int i = 2; i <= 500008; i += 2) sp[i] = 2;
  for (int i = 3; i <= 500008; i += 2) sp[i] = i;
  long long x = sqrt(500008);
  for (int i = 3; i <= x; i += 2) {
    if (sp[i] == i) {
      for (int j = i * i; j <= 500008; j += i) {
        sp[j] = i;
      }
    }
  }
}
map<long long, long long> m;
void pf(long long n) {
  while (1) {
    if (n <= 1) break;
    long long x = sp[n];
    while (n % x == 0) {
      n /= x;
      m[x]++;
    }
  }
}
long long a[500008];
void digit(long long n) {
  long long m = n;
  long long dg;
  while (m) {
    dg = m % 10;
    m /= 10;
  }
}
map<pair<long long, long long>, long long> mep;
int main() {
  ios_base::sync_with_stdio(false);
  long long t = 1;
  cin >> t;
  while (t--) {
    vector<pair<long long, pair<long long, long long>>> v;
    v.clear();
    long long n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      long long x, y, z;
      cin >> x >> y >> z;
      v.push_back({x, {y, z}});
    }
    long long st = 0;
    long long temp = m;
    long long prex = m;
    long long prey = m;
    int ok = 0;
    for (int i = 0; i < v.size(); i++) {
      long long t = v[i].first;
      long long x = v[i].second.first;
      long long y = v[i].second.second;
      long long sz = t - st;
      prex = max(prex - sz, x);
      prey = min(prey + sz, y);
      st = t;
      if (prex > prey) {
        cout << "NO" << endl;
        ok = 1;
        break;
      }
    }
    if (ok == 0) cout << "YES" << endl;
  }
}
