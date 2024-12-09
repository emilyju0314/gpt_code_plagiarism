#include <bits/stdc++.h>
using namespace std;
long long ans = 1e9;
const long long MAXA = 1000100;
vector<long long> g[MAXA];
long long p[MAXA];
long long c[MAXA];
void bfs(long long v) {
  vector<long long> q = {v};
  p[v] = -1;
  c[v] = 0;
  for (long long i = 0; i < q.size(); i++) {
    long long x = q[i];
    for (auto u : g[x]) {
      if (c[u] == -1) {
        c[u] = c[x] + 1;
        p[u] = x;
        q.push_back(u);
      } else {
        if (u != p[x]) {
          ans = min(ans, c[u] + c[x] + 1);
        }
      }
    }
  }
}
signed main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<pair<long long, long long> > primes(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    vector<long long> divisiors;
    for (long long T = 2; T * T <= a[i]; T++) {
      while (a[i] % (T * T) == 0) {
        a[i] /= T * T;
      }
    }
    for (long long T = 1; T * T <= a[i]; T++) {
      if (a[i] % T == 0) {
        divisiors.push_back(T);
        if (T * T != a[i]) divisiors.push_back(a[i] / T);
      }
    }
    if (divisiors.size() % 2) {
      cout << 1;
      return 0;
    }
    sort(divisiors.begin(), divisiors.end());
    if (divisiors.size() == 4) {
      long long p1 = divisiors[1];
      long long p2 = divisiors[2];
      primes[i] = {p1, p2};
    }
    if (divisiors.size() == 2) {
      long long p = divisiors[1];
      primes[i] = {p, 1};
    }
  }
  for (long long i = 0; i < n; i++) {
    g[primes[i].first].push_back(primes[i].second);
    g[primes[i].second].push_back(primes[i].first);
  }
  for (long long i = 1; i <= 1000; i++) {
    long long t = 1;
    for (long long j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        t = 0;
      }
    }
    if (t) {
      fill(c, c + MAXA, -1);
      bfs(i);
    }
  }
  if (ans == 1e9) {
    cout << -1;
    return 0;
  }
  cout << ans;
}
