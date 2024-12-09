#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long N = 1;
const long long big = 6e18;
long long block = 800;
const long long mod = 1e6;
long long n;
set<pair<long long, long long> > a;
vector<pair<long long, pair<long long, long long> > > t;
set<pair<long long, pair<long long, long long> > > cht;
vector<pair<long long, long long> > convex;
long double cross(pair<long long, long long> a, pair<long long, long long> b) {
  return (b.second - a.second + 0.0) / (a.first - b.first + 0.0);
}
void add(pair<long long, long long> a) {
  while (convex.size() >= 2 &&
         cross(convex[convex.size() - 2], a) <
             cross(convex[convex.size() - 2], convex[convex.size() - 1]))
    convex.pop_back();
  convex.push_back(a);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  t.push_back({0, {0, 0}});
  for (int i = (0); i < (n); i += 1) {
    long long x, a, b = 0;
    cin >> x >> a;
    if (x == 1) cin >> b;
    t.push_back({x, {a, b}});
  }
  block = 4950;
  for (int i = 1; i <= n; i += block) {
    long long l = i, r = min(i + block, n + 1);
    set<pair<long long, pair<long long, long long> > > sub;
    for (int j = l; j < r; j++) {
      if (t[j].first == 2 && t[j].second.first < l) {
        pair<long long, pair<long long, long long> > del = {
            t[t[j].second.first].second.first,
            {t[t[j].second.first].second.second, t[j].second.first}};
        auto it = cht.find(del);
        cht.erase(it);
        sub.insert(del);
      }
    }
    for (auto u : cht) add({u.first, u.second.first});
    for (int j = l; j < r; j++) {
      if (t[j].first == 1) {
        cht.insert({t[j].second.first, {t[j].second.second, j}});
        sub.insert({t[j].second.first, {t[j].second.second, j}});
      }
      if (t[j].first == 2) {
        long long L = t[j].second.first;
        pair<long long, pair<long long, long long> > del = {
            t[L].second.first, {t[L].second.second, L}};
        auto it = sub.find(del);
        sub.erase(it);
        if (L >= l) {
          it = cht.find(del);
          cht.erase(it);
        }
      }
      if (t[j].first == 3) {
        long long ans = -big;
        if (sub.size() == 0 && cht.size() == 0) {
          cout << "EMPTY SET\n";
          continue;
        }
        long long x = t[j].second.first;
        for (auto u : sub) ans = max(ans, u.first * x + u.second.first);
        if (convex.size() > 0) {
          long long L = 1, R = convex.size() - 1;
          ans = max(convex[0].first * x + convex[0].second, ans);
          long double XX = x;
          while (L <= R) {
            long long m = (L + R) >> 1;
            ans = max(convex[m].first * x + convex[m].second, ans);
            if (cross(convex[m], convex[m - 1]) > XX)
              R = m - 1;
            else
              L = m + 1;
          }
        }
        cout << ans << '\n';
      }
    }
    convex.clear();
  }
}
