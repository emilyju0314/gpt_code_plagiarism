#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
const long long maxn = 2e5 + 10;
const long long mod = 1e9 + 7;
long long a[maxn], f[maxn], val[maxn], dg[maxn];
set<pair<long long, long long> > s[maxn];
set<pair<long long, long long> > tot;
inline void Add(long long x) {
  if (s[x].empty()) return;
  long long delta = a[x] / dg[x];
  pair<long long, long long> p1 = *s[x].begin(), p2 = *s[x].rbegin();
  tot.insert(make_pair(p1.first + delta, p1.second));
  tot.insert(make_pair(p2.first + delta, p2.second));
}
inline void Erase(long long x) {
  if (s[x].empty()) return;
  long long delta = a[x] / dg[x];
  pair<long long, long long> p1 = *s[x].begin(), p2 = *s[x].rbegin();
  tot.erase(make_pair(p1.first + delta, p1.second));
  tot.erase(make_pair(p2.first + delta, p2.second));
}
inline void Modify(long long x, long long y) {
  s[f[x]].erase(make_pair(val[x], x));
  val[x] = y;
  s[f[x]].insert(make_pair(val[x], x));
}
inline long long calc(long long x, long long d) {
  return x - ((d - 1) * (x / d));
}
int main() {
  long long n, q;
  cin >> n >> q;
  for (int i = 0; i < int(n); i++) {
    cin >> a[i];
    dg[i] = 1;
  }
  for (int i = 0; i < int(n); i++) {
    cin >> f[i];
    f[i]--;
    dg[i]++;
    dg[f[i]]++;
  }
  for (int i = 0; i < int(n); i++) {
    val[i] += calc(a[i], dg[i]);
    val[f[i]] += a[i] / dg[i];
  }
  for (int i = 0; i < int(n); i++) {
    s[f[i]].insert(make_pair(val[i], i));
  }
  for (int i = 0; i < int(n); i++) {
    if (s[i].empty()) continue;
    long long delta = a[i] / dg[i];
    pair<long long, long long> p1 = *s[i].begin(), p2 = *s[i].rbegin();
    tot.insert(make_pair(p1.first + delta, p1.second));
    tot.insert(make_pair(p2.first + delta, p2.second));
  }
  while (q--) {
    long long task, x, y;
    cin >> task;
    if (task == 1) {
      cin >> x >> y;
      x--;
      y--;
      Erase(x);
      Erase(y);
      Erase(f[y]);
      Erase(f[x]);
      Erase(f[f[x]]);
      Erase(f[f[y]]);
      Erase(f[f[f[x]]]);
      Modify(y, val[y] + (a[x] / dg[x]) + calc(a[y], dg[y] + 1) -
                    calc(a[y], dg[y]));
      Modify(f[y], val[f[y]] + (a[y] / (dg[y] + 1)) - (a[y] / dg[y]));
      Modify(f[x], val[f[x]] - (a[x] / (dg[x])) + calc(a[f[x]], dg[f[x]] - 1) -
                       calc(a[f[x]], dg[f[x]]));
      Modify(f[f[x]],
             val[f[f[x]]] + (a[f[x]] / (dg[f[x]] - 1)) - (a[f[x]] / dg[f[x]]));
      dg[f[x]]--;
      dg[y]++;
      s[f[x]].erase(make_pair(val[x], x));
      s[y].insert(make_pair(val[x], x));
      Add(x);
      Add(y);
      Add(f[y]);
      Add(f[x]);
      Add(f[f[x]]);
      Add(f[f[y]]);
      Add(f[f[f[x]]]);
      f[x] = y;
    }
    if (task == 2) {
      cin >> x;
      x--;
      cout << val[x] + (a[f[x]] / dg[f[x]]) << endl;
    }
    if (task == 3) {
      cout << (tot.begin()->first) << " " << (tot.rbegin()->first) << endl;
    }
  }
}
