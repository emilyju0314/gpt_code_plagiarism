#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Init {
  Init() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} Init;

signed main() {
  int A, B, P, Q, R;
  cin >> A >> B >> P >> Q >> R;

  cout << double(P * B - Q * B + Q * A) / (Q + R) + B << endl;
  return 0;
}
