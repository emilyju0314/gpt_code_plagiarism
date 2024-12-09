#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll s1(ll n) { return n * (n + 1) / 2; }
vector<ll> pfac(ll n) {
  vector<ll> ret;
  if (n % 2 == 0) {
    ret.emplace_back(2);
    while (n % 2 == 0) n /= 2;
  }
  for (ll i = 3; i * i <= n; i += 2)
    if (n % i == 0) {
      ret.emplace_back(i);
      while (n % i == 0) n /= i;
    }
  if (n == 1)
    return ret;
  else {
    ret.emplace_back(n);
    return ret;
  }
}
set<ll> fac(ll n) {
  set<ll> ret;
  for (ll i = 1; i * i <= n; i++)
    if (n % i == 0) {
      if (i * i == n and i != 1)
        ret.insert(i);
      else {
        if (i != 1) ret.insert(i);
        if (n / i != 1) ret.insert(n / i);
      }
    }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  ll T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    auto v = pfac(n);
    if (v.size() == 2 and v[0] * v[1] == n) {
      cout << v[0] << " " << v[1] << " " << v[0] * v[1] << endl;
      cout << 1 << "\n";
    } else if (v.size() == 2) {
      cout << v[0] << " ";
      set<ll> ban = {v[0], v[1], v[0] * v[1]};
      auto fac = ::fac(n);
      ll show = 0;
      for (auto it : fac)
        if (it % (v[0] * v[1]) == 0 and it != v[0] * v[1]) {
          show = it;
          ban.insert(it);
          break;
        }
      for (auto it : fac)
        if (ban.count(it) == 0 and it % v[0] == 0)
          cout << it << " ", ban.insert(it);
      cout << v[0] * v[1] << " ";
      for (auto it : fac)
        if (ban.count(it) == 0 and it % v[1] == 0)
          cout << it << " ", ban.insert(it);
      cout << v[1] << " " << show << "\n" << 0 << "\n";
    } else {
      auto fac = ::fac(n);
      v.emplace_back(v.front());
      set<ll> ban;
      for (ll i = 0; i < v.size() - 1; i++)
        ban.insert(v[i]), ban.insert(v[i] * v[i + 1]);
      for (ll i = 0; i < v.size() - 1; i++) {
        cout << v[i] << " ";
        set<ll> del;
        for (auto it : fac)
          if (it % v[i] == 0) {
            del.insert(it);
            if (ban.count(it) == 0) cout << it << " ";
          }
        cout << v[i] * v[i + 1] << " ";
        for (auto it : del) fac.erase(it);
      }
      cout << "\n";
      cout << "0\n";
    }
  }
  return 0;
}
