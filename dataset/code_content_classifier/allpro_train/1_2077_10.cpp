#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using namespace std;

typedef long long ll;
const ll INF = 1e15;

vector<ll> S;

inline bool can_beat(ll l, ll x, ll s)
{
  return (s < l + x);
}

ll near(ll n)
{
  ll ok = S.size()-1, ng = -1;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    (S[mid] >= n ? ok : ng) = mid;
  }
  return ok;
}

bool check(ll X, ll M)
{
  int m = 0, l = 1;
  while (m < M) {
    if (can_beat(l, X, S.back())) {
      // cerr << "m+1 = " << m+1 << endl;
      // cerr << "m =" << m << endl;
      return (m+1 >= M ? true : false);
    }

    // cerr << "A " << m << endl;
    // vector<ll>::iterator it = lower_bound(S.begin(), S.end(), l);
    // rep(i, 1e6) lower_bound(S.begin(), S.end(), l);
    int idx = near(l);
    // cerr << "B " << m << endl;

    ll diff = INF;
    if (can_beat(l, X, S[idx])) {
      diff = min(diff, abs(l - S[idx]));
    }
    if (idx-1 >= 0 && can_beat(l, X, S[idx-1])) {
      diff = min(diff, abs(l - S[idx-1]));
    }

    l += max(1LL, X - diff);

    m++;
  }
    // cerr << "m =" << m << endl;
  return true;
}

int main()
{
  int N, M;
  while (cin >> N >> M, N || M) {
    // cerr << "================" << endl;

    S.resize(N);
    rep(i, N) cin >> S[i];

    // sort(S.begin(), S.end());

    ll ok = S[0], ng = S.back();

    if (!check(ok, M)) {
      cout << -1 << endl;
    } else {
      while (abs(ok - ng) > 1) {
        // cerr << "ok, ng = " << ok << ", " << ng << endl;
        ll mid = (ok + ng) / 2;
        (check(mid, M) ? ok : ng) = mid;
      }
      cout << ok << endl;
    }
  }
}