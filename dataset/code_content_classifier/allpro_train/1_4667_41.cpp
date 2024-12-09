#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  ll N;
  cin >> N;
  vector<ll> S(N);
  REP(i, 0, N) {
    ll P;
    string M;
    cin >> P >> M;
    ll x = 0;
    REP(j, 0, M.size()) {
      char c = M[j];
      if('0' <= c && c <= '9') x = x * P + (c - '0');
      if('A' <= c && c <= 'Z') x = x * P + (c - 'A' + 10);
      if('a' <= c && c <= 'z') x = x * P + (c - 'a' + 10 + 'Z' - 'A' + 1);
    }
    S[i] = x;
  }

  ll g = 0;
  REP(i, 0, N) g = g ^ S[i];
  cout << (g != 0 ? "win" : "lose") << endl;
}
