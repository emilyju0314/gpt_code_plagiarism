#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll p = 1000000007;
bool can(const vector<ll> &ais, ll limit, ll count) {
  ll n = ais.size();
  vector<ll> bins(count, 0);
  ll j = 0, neg = 0;
  while (j < n) {
    if (ais[j] - neg <= 0) break;
    bins[j % count] += ais[j] - neg;
    j++;
    if (j % count == 0) neg++;
  }
  ll s = 0;
  for (const auto &bin : bins) s += bin;
  return s >= limit;
}
int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> ais(n);
  for (int i = 0; i < n; ++i) {
    cin >> ais[i];
  }
  sort(ais.begin(), ais.end());
  reverse(ais.begin(), ais.end());
  ll s = 0;
  for (const auto &ai : ais) s += ai;
  if (s < m) {
    cout << -1 << endl;
    return 0;
  }
  ll high = n, low = 0;
  while (high - low > 1) {
    ll mid = (low + high) / 2;
    if (can(ais, m, mid))
      high = mid;
    else
      low = mid;
  }
  cout << high << endl;
  return 0;
}
