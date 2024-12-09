#include <bits/stdc++.h>
using namespace std;
long long resl[1000], resr[1000];
map<pair<int, long long>, long long> cache;
long long query(int f, long long x) {
  if (cache.count({f, x})) return cache[{f, x}];
  cout << "? " << f << " " << x << "\n" << flush;
  long long r;
  cin >> r;
  cache[{f, x}] = r;
  return r;
}
long long findx(int f, long long a, long long b, long long m) {
  while (a < b) {
    long long c = (a + b) / 2;
    long long r = query(f, c);
    if (r < m)
      a = c + 1;
    else
      b = c;
  }
  return a;
}
vector<int> kth(vector<int> f, int k, long long a, long long b, long long &c,
                long long m) {
  swap(f[0], f[rand() % f.size()]);
  vector<int> x, eq, y;
  long long p = findx(f[0], a, b, m);
  eq.push_back(f[0]);
  for (int i = 1; i < f.size(); ++i) {
    long long r = query(f[i], p);
    if (r > m)
      x.push_back(f[i]);
    else if (r < m)
      y.push_back(f[i]);
    else
      eq.push_back(f[i]);
  }
  if (x.size() <= k && k < x.size() + eq.size())
    c = p;
  else if (k < x.size())
    x = kth(x, k, a, p - 1, c, m);
  else
    y = kth(y, k - x.size() - eq.size(), p + 1, b, c, m);
  for (int yy : eq) x.push_back(yy);
  for (int yy : y) x.push_back(yy);
  return x;
}
void calc(vector<int> f, long long a, long long b, long long l, long long s) {
  if (f.size() == 0) return;
  if (f.size() == 1) {
    resl[f[0] - 1] = a;
    resr[f[0] - 1] = b;
    return;
  }
  long long m = l + s * (f.size() / 2);
  long long c;
  f = kth(f, f.size() / 2, a, b, c, m);
  vector<int> x, y;
  for (int i = 0; i < f.size() / 2; ++i) x.push_back(f[i]);
  for (int i = f.size() / 2; i < f.size(); ++i) y.push_back(f[i]);
  calc(x, a, c, l, s);
  calc(y, c, b, m, s);
}
int main() {
  int n;
  long long L;
  cin >> n >> L;
  vector<int> f;
  for (int i = 1; i <= n; ++i) f.push_back(i);
  calc(f, 0, 1e18, 0, L / n);
  cout << "!\n";
  for (int i = 0; i < n; ++i) cout << resl[i] << " " << resr[i] << "\n";
}
