#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long p = 1e9 + 7;
long long par[N];
long long sz[N];
long long a[N];
long long find_par(long long u) {
  while (par[u] != u) {
    par[u] = par[par[u]];
    u = par[u];
  }
  return par[u];
}
void merge(long long a, long long b) {
  long long pa = find_par(a);
  long long pb = find_par(b);
  if (pa != pb) {
    if (sz[pb] > sz[pa]) swap(pa, pb);
    par[pb] = pa;
    sz[pa] += sz[pb];
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < N; i++) par[i] = i, sz[i] = 1;
  for (long long i = 0; i < m; i++) {
    long long k;
    cin >> k;
    for (long long j = 0; j < k; j++) cin >> a[j];
    for (long long j = 1; j < k; j++) merge(a[j], a[0]);
  }
  for (long long i = 1; i <= n; i++) {
    long long x = find_par(i);
    cout << sz[x] << ' ';
  }
  return 0;
}
