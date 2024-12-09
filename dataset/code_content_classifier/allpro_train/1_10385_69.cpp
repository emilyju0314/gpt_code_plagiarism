#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, T, H[100000];

int main(void) {
  cin >> N >> T;
  REP(i, 0, N) cin >> H[i];

  ll sum = 0, m = 0;
  REP(i, 0, N) {
    ll t = T - sum;
    m = max(m, H[i]);
    if(t <= 0) cout << 1 << endl;
    else cout << t / m + (t % m >= H[i] ? 1 : 0) + 1 << endl;
    sum += H[i];
  }
}