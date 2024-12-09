#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll maxSize = 200007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, a, b, k;
  cin >> n >> a >> b >> k;
  auto sum = a + b;
  vector<ll> h(n);
  for (ll i = 0; i < n; ++i) {
    ll next;
    cin >> next;
    auto res = next % sum;
    if (res == 0) res = b + a;
    if (res % a == 0)
      h[i] = res / a - 1;
    else
      h[i] = res / a;
  }
  sort(h.begin(), h.end());
  ll answer = 0;
  auto it = h.begin();
  while (it != h.end() && k >= 0) {
    if (*it <= k) {
      ++answer;
      k -= *it;
    } else
      break;
    ++it;
  }
  cout << answer;
}
