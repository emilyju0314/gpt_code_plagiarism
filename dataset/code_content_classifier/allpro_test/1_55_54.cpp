#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
T power(T base, U expo, T mod) {
  T res = 1;
  while (expo > 0) {
    if (expo & 1) res = res * base % mod;
    expo >>= 1;
    base = base * base % mod;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int mod = (int)1e9 + 7;
  int k;
  cin >> k;
  cout << 6ll * power(4ll, (1ll << k) - 2, (long long)mod) % mod << '\n';
  return 0;
}
