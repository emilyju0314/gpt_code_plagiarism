#include <bits/stdc++.h>
using namespace std;
long long f[100];
void solve(long long X) {
  cout << X << " ";
  long long k = log2(X);
  if (k == 0) return;
  long long Y = X - (1ll << k);
  Y = (Y + f[k]) % (1ll << k);
  Y += (1ll << k);
  solve(Y / 2);
}
void update(long long k, long long K) {
  f[k] += K;
  f[k] %= (1ll << k);
  if (f[k] < 0) f[k] += (1ll << k);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(f, 0, sizeof f);
  long long Q;
  cin >> Q;
  while (Q--) {
    long long T, X, K;
    cin >> T;
    if (T < 3) {
      cin >> X >> K;
      long long k = 0;
      while (X > 1) X /= 2, k++;
      update(k, K);
      if (T == 1) update(k + 1, -2 * K);
    } else {
      cin >> X;
      solve(X);
      cout << "\n";
    }
  }
}
