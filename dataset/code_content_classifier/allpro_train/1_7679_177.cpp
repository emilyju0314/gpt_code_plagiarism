#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using pill = pair<int, ll>;
using vvi = vector<vi>;
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll fast_exp(ll base, ll n, ll m) {
  if (n == 0) return 1;
  ll t = fast_exp(base, n / 2, m);
  if (n % 2 == 0)
    return (t * t) % m;
  else
    return (((t * t) % m) * base) % m;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i > 0 and a[i] == a[i - 1]) {
      cout << "NO\n";
      return 0;
    }
  }
  ll y = -1;
  for (int i = 1; i < n; ++i) {
    if (abs(a[i] - a[i - 1]) > 1ll) {
      if (y == -1)
        y = abs(a[i] - a[i - 1]);
      else if (y != abs(a[i] - a[i - 1])) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  if (y == -1) {
    cout << "YES\n1 " << (ll)1e9 << "\n";
    return 0;
  }
  for (int k = 1; k < n; ++k) {
    ll i = (a[k] - 1) / y, j = (a[k] - 1) % y;
    if (i > (ll)1e9) {
      cout << "NO\n";
      return 0;
    }
    ll i1 = (a[k - 1] - 1) / y, j1 = (a[k - 1] - 1) % y;
    if (abs(i - i1) + abs(j - j1) != 1) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n" << (ll)1e9 << " " << y << "\n";
  return 0;
}
