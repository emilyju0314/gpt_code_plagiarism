#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
  ll N, X;
  cin >> N >> X;
  vector<ll> x(N);
  for (int i = 0; i < N; ++i) cin >> x[i];
  vector<ll> a(N + 1, 0);
  for (int i = 0; i < N; ++i) a[i + 1] = a[i] + x[i];

  ll ans = INF;
  auto F = [](ll x, ll y) { return (INF / x < y) ? INF : x * y; };
  auto E = [F](ll i, ll x) { return (i == 1) ? F(5, x) : F((2 * i + 1), x); };
  for (ll k = 1; k <= N; ++k) {
    ll sum = (N + k) * X;
    for (ll i = 1; i <= (N + k - 1) / k; ++i) {
      sum += E(i, a[N - k * (i - 1)] - a[max(0LL, N - k * i)]);
      sum = min(sum, INF);
    }
    ans = min(ans, sum);
  }

  cout << ans << endl;
  return 0;
}
