#include <bits/stdc++.h>
#define REP(i, a, n) for (ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void) {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M), B(M);
  REP(i, 0, M) cin >> A[i] >> B[i];

  map<pll, ll> p;
  REP(i, 0, M) p[pll(A[i], B[i])]++;

  vector<ll> x(N, M);
  for (auto q : p) {
    ll a = q.first.first, b = q.first.second, cnt = q.second;
    x[0] += a * cnt;
    for (ll j = b - a; j - 1 < N; j += b) {
      x[j - 1] -= b * cnt;
    }
  }

  REP(i, 0, N - 1) x[i + 1] += x[i];
  REP(i, 0, N) cout << x[i] << endl;
}
