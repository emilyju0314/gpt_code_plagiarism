#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
const double pi = 2 * asin(1.0);
int n;
int m;
const long long inf = (long long)1e18;
vector<int> g[100010];
int a[100010], was[100010];
long long s[100010], d[100010];
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
long long lcm(long long a, long long b) {
  a /= gcd(a, b);
  if ((a + 0.0) * b > inf) return inf;
  return b * a;
}
int go(int x, int p) {
  int l = ((int)(g[x]).size()) - int(p != 0);
  if (!l) {
    s[x] = a[x];
    d[x] = 1;
    return 0;
  }
  long long k = 1, sa = inf;
  for (auto it = g[x].begin(); it != g[x].end(); it++) {
    if (*it == p) continue;
    go(*it, x);
    k = lcm(k, d[*it]);
    sa = min(sa, s[*it]);
  }
  if ((k + 0.0) * l > inf)
    d[x] = inf;
  else
    d[x] = k * l;
  s[x] = (sa / k) * k * l;
  return 0;
}
int main() {
  scanf("%d", &n);
  long long ss = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ss += a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  go(1, 0);
  cout << ss - s[1] << endl;
  return 0;
}
