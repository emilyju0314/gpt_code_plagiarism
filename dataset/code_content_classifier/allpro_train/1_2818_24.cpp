#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-Wconversion"
using ll = long long;
map<ll, ll> cnts;
map<ll, ll> need;
bool check(ll k) {
  if (cnts[1] < k) return false;
  ll chains[50] = {0};
  ll take[50] = {0};
  ll top = k;
  map<ll, ll> need2(need);
  for (int i = 0; i < 50; i++) {
    if (cnts[1LL << i] == 0) break;
    chains[i] = min(top, cnts[1LL << i]);
    top = chains[i];
    need2[max(0, i - 1)] -= chains[i];
  }
  for (int i = 0; i < 49; i++) {
    take[i] = chains[i] - chains[i + 1];
  }
  for (const auto &pair : need2) {
    ll cur = pair.first;
    ll stillneed = pair.second;
    while (cur < 50) {
      ll d = min(stillneed, take[cur]);
      stillneed -= d;
      take[cur] -= d;
      cur++;
    }
    if (stillneed > 0) {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ll cur = 1;
  ll ce = 0;
  for (int i = 0; i < n; i++) {
    ll v;
    cin >> v;
    cnts[v]++;
    while (2 * cur < v) {
      ce++;
      cur *= 2;
    }
    need[ce]++;
  }
  bool any = false;
  for (int k = 1; k <= 100001; k++) {
    if (check(k)) {
      any = true;
      cout << k << " ";
    }
  }
  if (!any)
    cout << -1 << endl;
  else
    cout << endl;
}
