#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
T GCD(T a, T b) { return b == 0 ? a : GCD(b, a%b); }

int main()
{
  int N; cin >> N;

  ll ans = 1;
  for (int i = 0; i < N; ++i) {
    ll T; cin >> T;
    ans = ans/GCD(ans, T)*T;
  }

  cout << ans << endl;
}