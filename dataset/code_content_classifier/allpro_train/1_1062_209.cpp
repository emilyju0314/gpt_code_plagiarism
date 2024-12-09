#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ifstream in("input.txt");
ofstream out("output.txt");
struct point {
  ld x, y;
  point(ld a, ld b) {
    x = a;
    y = b;
  }
};
ld scal(point a, point b) { return (a.x * b.x) + (b.y * a.y); }
ld vec(point a, point b) { return (a.x * b.y) - (b.x * a.y); }
ld len(point a) { return sqrt(a.x * a.x + a.y * a.y); }
ll powMod(ll x, ll y, ll mod) {
  if (!y) return 1;
  ll z = powMod((x) % mod, (y / 2) % mod, mod);
  if (y % 2)
    return ((x) % mod * (z) % mod * (z) % mod) % mod;
  else
    return ((z) % mod * (z) % mod) % mod;
}
vector<ll> gcdPlus(ll a, ll b) {
  if (!a) return vector<ll>{b, 0, 1};
  vector<ll> tres(3);
  tres = gcdPlus(b % a, a);
  ll x = tres[2] - (b / a) * tres[1];
  ll y = tres[1];
  return vector<ll>{tres[0], x, y};
}
ll gcd(ll a, ll b) {
  while (a > 0 && b > 0) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
struct node {
  ll x, y, z;
};
string downcase(string s) {
  for (ll i = 0; i < s.size(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] += 32;
    }
  }
  return s;
}
ll sum(ll n) {
  ll ans = 0;
  while (n > 0) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}
const ll arrS = 2 * 1e5;
ll rec(string s, char f) {
  if (!(s.size() - 1)) {
    return (s[0] != f);
  }
  ll m = s.size() / 2;
  string a = s.substr(0, m), b = s.substr(m, m);
  ll x = rec(a, f + 1);
  x += (m - count((b).begin(), (b).end(), f));
  ll y = rec(b, f + 1);
  y += (m - count((a).begin(), (a).end(), f));
  return min(x, y);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << rec(s, 'a') << '\n';
  }
  return 0;
}
