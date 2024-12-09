#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll MOD = 1e9 + 7, N = 1e5 + 10;
void test() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> upd(2 * k + 2);
  for (ll i = 0; i < n / 2; i++) {
    ll sm = a[i] + a[n - i - 1];
    ll mn = min(a[i], a[n - i - 1]);
    ll d = k - mn;
    upd[sm + 1]++;
    upd[sm + d + 1]--;
    upd[sm + d + 1] += 2;
    upd[2 * k + 1] -= 2;
    ll mx = max(a[i], a[n - i - 1]);
    d = mx - 1;
    upd[sm]--;
    upd[sm - d]++;
    upd[2] += 2;
    upd[sm - d] -= 2;
  }
  ll cur = 0;
  ll ans = 1e18;
  for (ll i = 2; i < 2 * k + 1; i++) {
    cur += upd[i];
    ans = min(ans, cur);
  }
  cout << ans << '\n';
  return;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll tt = 1;
  cin >> tt;
  for (ll i = 0; i < tt; i++) test();
  return 0;
}
