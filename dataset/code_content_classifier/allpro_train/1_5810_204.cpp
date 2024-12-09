#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long a, long long p) { return power(a, p - 2, p); }
vector<long long> pos[200007];
long long id = 0;
int main() {
  long long n, q;
  scanf("%lld %lld", &(n), &(q));
  vector<long long> a;
  for (long long i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    a.push_back(x);
  }
  set<long long> s;
  for (auto p : a) s.insert(p);
  map<long long, long long> mapa;
  for (auto p : s) mapa[p] = ++id;
  for (long long i = 0; i < n; i++) {
    a[i] = mapa[a[i]];
  }
  for (long long i = 0; i < n; i++) pos[a[i]].push_back(i + 1);
  for (long long i = 0; i <= id; i++) sort(pos[i].begin(), pos[i].end());
  vector<pair<pair<long long, long long>, long long> > v;
  v.push_back({{0, 0}, 0});
  for (long long i = 1; i <= id; i++) {
    v.push_back({{pos[i][0], pos[i][pos[i].size() - 1]}, pos[i].size()});
  }
  long long maxi = 0;
  long long start = 0;
  long long end = 0;
  long long ans = 0;
  sort(v.begin(), v.end());
  for (long long i = 1; i <= id; i++) {
    long long st = v[i].first.first;
    if (st > end) {
      ans += (end - start) - maxi;
      maxi = 0;
      start = end;
      ;
      end = v[i].first.second;
      maxi = v[i].second;
      continue;
    }
    end = max(v[i].first.second, end);
    maxi = max(maxi, (long long)v[i].second);
  }
  if (maxi != 0) {
    ans += end - start - maxi;
  }
  printf("%lld\n", ans);
}
