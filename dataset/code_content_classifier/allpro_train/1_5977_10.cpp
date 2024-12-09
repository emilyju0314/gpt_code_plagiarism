#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long INF = 1e9, MOD = INF + 7;
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
long long power(long long a, long long b) {
  return (!b ? 1 : power(a, b / 2) * power(a, b / 2) * (b % 2 ? a : 1));
}
long long mod(long long a) { return (a % MOD + MOD) % MOD; }
const long long N = 3e1 + 1;
bool ask(long long x, long long y) {
  cout << "?"
       << " " << x << " " << y << endl;
  char ans;
  cin >> ans;
  return (ans == 'x');
}
void play() {
  long long dw = 0, up = INF + 1;
  for (long long i = 0; i < N; i++) {
    if (ask(1 << i, 1 << (i + 1))) {
      dw = 1 << i;
      up = 1 << (i + 1);
      break;
    }
  }
  if (dw == 1 && up == 2) {
    if (ask(2, 1))
      cout << "!"
           << " " << 1 << endl;
    else
      cout << "!"
           << " " << 2 << endl;
  } else {
    while (up - dw > 1) {
      long long md = (dw + up) / 2;
      if (ask(dw, md))
        up = md;
      else
        dw = md;
    }
    cout << "!"
         << " " << up << endl;
  }
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  while (cin >> s)
    if (s == "start")
      play();
    else
      return 0;
  return 0;
}
