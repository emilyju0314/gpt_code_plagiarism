#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int n, m;
vector<ll> hero;
vector<ll> s, h, a;
int checkPosition(int p, vector<ll> &res) {
  int heroesLeft = 0, heroesRight = 0;
  for (int i = 0; i < m; ++i) {
    if (s[i] < p)
      heroesLeft++;
    else
      ++heroesRight;
  }
  vector<ll> aa = a;
  vector<ll> hh = hero;
  for (int _ = 0; _ < heroesLeft; ++_) {
    int take = -1;
    ll needAtLeast = 0;
    for (int pos = p - 1; pos >= 0; --pos) {
      needAtLeast -= aa[pos];
      needAtLeast = max(0ll, needAtLeast);
      if (hh[pos] != -1 && h[hh[pos]] >= needAtLeast) take = hh[pos];
    }
    if (take == -1) return -1;
    for (int pos = s[take]; pos <= p - 1; ++pos) {
      aa[pos] = 0;
    }
    hh[s[take]] = -1;
    res.push_back(take);
  }
  for (int _ = 0; _ < heroesRight; ++_) {
    int take = -1;
    ll needAtLeast = 0;
    for (int pos = p; pos < n; ++pos) {
      needAtLeast -= aa[pos];
      needAtLeast = max(0ll, needAtLeast);
      if (hh[pos] != -1 && h[hh[pos]] >= needAtLeast) {
        take = hh[pos];
      }
    }
    if (take == -1) return -1;
    for (int pos = s[take]; pos >= p; --pos) {
      aa[pos] = 0;
    }
    hh[s[take]] = -1;
    res.push_back(take);
  }
  if (heroesLeft == 0) return p + 1;
  return p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  s = vector<ll>(m);
  h = vector<ll>(m);
  for (int i = 0; i < m; ++i) cin >> s[i] >> h[i];
  hero = vector<ll>(n, -1);
  for (int i = 0; i < m; ++i) {
    --s[i];
    hero[s[i]] = i;
  }
  a = vector<ll>(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n + 1; ++i) {
    vector<ll> res;
    if (-1 == checkPosition(i, res)) continue;
    res.clear();
    cout << checkPosition(i, res) << endl;
    for (const auto &u : res) cout << (u + 1) << " ";
    cout << '\n';
    return 0;
  }
  cout << -1 << endl;
}
